-----------QLCB-------------------
USE QLChuyenBay
GO

--Q36. Phi công lái nhiều chuyến bay nhất?
-- mỗi phi công lái ? chuyến bay
SELECT NV.MANV
FROM NHANVIEN NV JOIN PHANCONG PC ON NV.MANV=PC.MANV
WHERE NV.LOAINV=1
/* Đếm phân công trên từng nhân viên */
GROUP BY NV.MANV
/* Trong phần con chỉ cần ghi vô những cái cần count 
DISTINCT vì có thể phân công nhiều lần trên cùng một 
mã chuyến bay */
HAVING COUNT( DISTINCT PC.MACB) >= ALL (SELECT COUNT(PC.MACB) 
							FROM PHANCONG PC)
--Q51. Mã chuyến bay bay tất cả các máy bay của Airbus
--KQ (của phép chia: KEYWORD: CHỦ TỪ GẮN VỚI TẤT CẢ (TRƯỚC TẤT CẢ)): (MACB) 
/*
--> MACB-->nhiều bảng có MACB?--> CHUYENBAY (chứa đầy đủ thông tin về MACB (tập bự hơn))
Đề chỉ yêu cầu mã chuyến bay CÓ BAY, nên chỉ cần chọn bảng LICHBAY là đủ
--> Chọn bảng nào cũng được
*/
--S (số chia: KEYWORD: TẤT CẢ CÁI GÌ): MAYBAY (SOHIEU, MALOAI), LOAIMB
/* => máy bay của Airbus => MAYBAY, LOAIMB (trong này mới có hãng sản xuất) */
--R (số bị chia: KEYWORD: VỪA CÓ KQ, VỪA CÓ S): LICHBAY
/* vừa có SOHIEU, MALOAI, vừa có MACB và thể hiện được ý nghĩa của đề bài => LICHBAY */


/*
- Câu truy vấn cha ngoài cùng là KQ
- Câu truy vấn con ở giữa là S
- Câu nằm trong cùng (sau cùng, dưới cùng) là R
KQ x S -> R 
R / S -> KQ
*/
--EXCEPT
SELECT CB.MACB
FROM CHUYENBAY CB --có thể dùng trực tiếp LICHBAY
/* Lấy ra tất cả các máy bay Boeing TRỪ ĐI
tất cả các máy bay trong lịch bay (JOIN với CB)

Khi dùng EXCEPT thì phải select đúng với những gì đề yêu cầu
S gồm có SOHIEU và MALOAI nên phải SELECT đầy đủ 2 cái đó */

WHERE NOT EXISTS (
	(SELECT MB.MALOAI, MB.SOHIEU
	FROM MAYBAY MB JOIN LOAIMB LMB ON MB.MALOAI=LMB.MALOAI
	WHERE LMB.HANGSX='Boeing')
	EXCEPT
	(SELECT LB.MALOAI, LB.SOHIEU
	FROM LICHBAY LB
	WHERE LB.MACB=CB.MACB)
)

--NOT EXISTS
SELECT CB.MACB
FROM CHUYENBAY CB
WHERE NOT EXISTS (
	SELECT *
	FROM MAYBAY MB JOIN LOAIMB LMB ON MB.MALOAI=LMB.MALOAI
	/* Khi dùng NOT EXISTS thì phải kết tương quan giữa R và S */
	WHERE LMB.HANGSX='Boeing' AND NOT EXISTS (
		SELECT *
		FROM LICHBAY LB
		WHERE LB.MACB=CB.MACB AND LB.MALOAI=LMB.MALOAI AND LB.SOHIEU=MB.SOHIEU)
)

--GROUP BY
SELECT LB.MACB
FROM LICHBAY LB JOIN LOAIMB LMB ON LB.MALOAI=LMB.MALOAI
WHERE LMB.HANGSX='Boeing'
GROUP BY LB.MACB
HAVING COUNT(DISTINCT LB.SOHIEU) = (
	SELECT COUNT(*)
	FROM MAYBAY MB JOIN LOAIMB LMB ON MB.MALOAI=LMB.MALOAI
	WHERE LMB.HANGSX='Boeing')


--Q56. Các khách hàng có đặt chỗ trong tất cả các ngày 31/10/2000 đến 1/1/2000
--KQ: KHACHHANG(MAKH)
--S: NGAYDI --> LICHBAY (chỉ có LICHBAY mới chứa được TẤT CẢ các ngày đi)
--R: DATCHO(MAKH,NGAYDI)

SELECT KH.*
FROM KHACHHANG KH
WHERE NOT EXISTS (SELECT LB.NGAYDI FROM LICHBAY LB
				WHERE NOT EXISTS (
				SELECT DC.NGAYDI FROM DATCHO DC
				WHERE ((DC.NGAYDI=LB.NGAYDI) 
				AND (DC.NGAYDI BETWEEN '2000-10-31' AND '2000-1-1'))))

-- Nếu dùng EXCEPT --> select NGAYDI


--Q57Bis.Cho biết mã và tên phi công có khả năng lái được tất cả các loại máy bay của hãng "Airbus"
--KQ: NHANVIEN(MANV)
--S: LOAIMB(MALOAI)
--R: KHANANG(MANV,MALOAI) --tự thêm dữ liệu để test
SELECT DISTINCT NV.MANV, NV.TEN
FROM NHANVIEN NV
WHERE NV.LOAINV=1
AND NOT EXISTS (
	SELECT * FROM LOAIMB LMB
	WHERE LMB.HANGSX=N'Airbus'
	AND NOT EXISTS (
		SELECT * FROM KHANANG KN
		WHERE KN.MANV=NV.MANV AND KN.MALOAI=LMB.MALOAI)
)
		
--GROUP BY
SELECT NV.MANV, NV.TEN
FROM NHANVIEN NV, KHANANG KN, LOAIMB LMB
WHERE KN.MANV=NV.MANV AND NV.LOAINV=1 AND LMB.MALOAI=KN.MALOAI
AND LMB.HANGSX=N'Airbus'
GROUP BY NV.MANV, NV.TEN
HAVING COUNT(DISTINCT KN.MALOAI)=(SELECT DISTINCT COUNT(LMB.MALOAI)
							FROM LOAIMB LMB
							WHERE LMB.HANGSX=N'Airbus')

--Q57. Cho biết mã và tên phi công không có khả năng lái được tất cả các loại máy bay của hãng "Airbus"
--Ít nhất 1 loại phi công không lái được, không cần dùng phép chia
-- (số lượng loại lái được nhỏ hơn số lượng loại mà Airbus có)
SELECT NV.MANV, NV.TEN
FROM NHANVIEN NV, KHANANG KN, LOAIMB LMB
WHERE KN.MANV=NV.MANV AND NV.LOAINV=1 AND LMB.MALOAI=KN.MALOAI
AND LMB.HANGSX=N'Airbus'
GROUP BY NV.MANV, NV.TEN
HAVING COUNT(DISTINCT KN.MALOAI) < (SELECT DISTINCT COUNT(LMB.MALOAI)
							FROM LOAIMB LMB
							WHERE LMB.HANGSX=N'Airbus')


-- C2
SELECT DISTINCT NV.MANV, NV.TEN
FROM NHANVIEN NV
WHERE NV.LOAINV=1
AND EXISTS (
	SELECT * FROM LOAIMB LMB
	WHERE LMB.HANGSX=N'Airbus'
	AND NOT EXISTS (
		SELECT * FROM KHANANG KN
		WHERE KN.MANV=NV.MANV AND KN.MALOAI=LMB.MALOAI)
)
	
-----------QLDT------------------
USE QuanLyDeTai
GO

--Q48. Giáo viên trùng tên và trùng giới tính với giáo viên khác cùng bộ môn
-- TEN, GIOITINH, BOMON 
SELECT GV.*
FROM GIAOVIEN GV
WHERE EXISTS(	
	SELECT * FROM GIAOVIEN GV1
	WHERE GV1.MAGV <> GV.MAGV AND
	GV1.MABM = GV.MABM AND GV1.PHAI = GV.PHAI
	AND GV1.HOTEN=GV.HOTEN)

--Q63. Cho biết tên đề tài nào mà được tất cả các giáo viên của bộ môn Hóa Hữu Cơ tham gia.
--KQ: DETAI(TENDT)
--S: GIAOVIEN(BM HHC)
--R: THAMGIADT

SELECT DISTINCT DT.TENDT
FROM DETAI DT, THAMGIADT TG1
WHERE DT.MADT=TG1.MADT AND NOT EXISTS(
	(SELECT * --S là null
	FROM GIAOVIEN GV, BOMON BM
	WHERE GV.MABM=BM.MABM AND BM.TENBM=N'Hóa Hữu Cơ'
	AND NOT EXISTS (
		SELECT * FROM THAMGIADT TG 
		WHERE (TG.MADT=DT.MADT) AND (TG.MAGV=GV.MAGV))))
			AND EXISTS (--Kiểm tra S có null không
				SELECT * FROM GIAOVIEN GV, BOMON BM
				WHERE GV.MABM=BM.MABM AND BM.TENBM=N'Hóa Hữu Cơ'
				)