USE QLChuyenBay
GO
/*=======3. TRUY VẤN LỒNG + HÀM */
/* Q34. Cho	biết hãng	sản	xuất,	mã	loại	và	số hiệu	của máy	bay	đã	được	sử dụng	nhiều	nhất. */
SELECT LMB.HANGSX, LMB.MALOAI, LB.SOHIEU
FROM LOAIMB LMB JOIN LICHBAY LB
ON LB.MALOAI=LMB.MALOAI
GROUP BY LMB.HANGSX, LMB.MALOAI, LB.SOHIEU
HAVING COUNT(*) >= ALL (SELECT COUNT(*) FROM LICHBAY GROUP BY SOHIEU, MALOAI)


/* Q35. .Cho	biết tên	nhân	viên	được	phân	công	đi	nhiều	chuyến	bay	nhất. */
SELECT NV.TEN
FROM NHANVIEN NV JOIN PHANCONG PC
ON PC.MANV=NV.MANV
GROUP BY PC.MANV, NV.TEN
HAVING COUNT(PC.MANV)>= ALL(SELECT COUNT(MANV) FROM PHANCONG GROUP BY MANV)

/* Q36. Cho	biết	thông	tin	của	phi	công	(tên,	địa	chỉ,	điện	thoại)	lái	nhiều	chuyến	bay	nhất */
SELECT NV.TEN, NV.DCHI, NV.DTHOAI
FROM NHANVIEN NV JOIN PHANCONG PC
ON PC.MANV=NV.MANV
WHERE NV.LOAINV = 1
GROUP BY NV.TEN, NV.DCHI, NV.DTHOAI
HAVING COUNT(PC.MACB) >= ALL(SELECT COUNT(PC.MANV) 
							FROM NHANVIEN NV JOIN PHANCONG PC
							ON PC.MANV=NV.MANV WHERE NV.LOAINV=1
							GROUP BY PC.MANV)

/* Q37. Cho	biết sân	bay	(SBDEN)	và	số lượng	chuyến	bay	của	sân	bay	có	ít	chuyến	bay	đáp	
xuống	nhất.	*/
SELECT CB.SBDEN, COUNT(CB.MACB) AS SOLUONGCHUYENBAY
FROM CHUYENBAY CB
GROUP BY CB.SBDEN
HAVING COUNT(CB.MACB) <= ALL (SELECT COUNT(CB.MACB)
							FROM CHUYENBAY CB
							GROUP BY CB.SBDEN)


/* Q38. Cho	biết sân bay (SBDI)	và	số lượng	chuyến	bay	của	sân	bay	có	nhiều	chuyến	bay	xuất	
phát	nhất. */
SELECT CB.SBDI, COUNT(CB.MACB) 'SO LUONG CHUYEN BAY'
FROM CHUYENBAY CB
GROUP BY CB.SBDI
HAVING COUNT(CB.MACB) >= ALL (SELECT COUNT(CB.MACB)
							FROM CHUYENBAY CB 
							GROUP BY CB.SBDI)

/* Q39.Cho	biết tên,	địa	chỉ,	và	điện	thoại	của	khách	hàng	đã	đi	trên	nhiều chuyến bay	nhất. */
SELECT KH.TEN, KH.DCHI, KH.DTHOAI
FROM KHACHHANG KH JOIN DATCHO DC ON DC.MAKH=KH.MAKH
GROUP BY KH.MAKH, KH.TEN, KH.DCHI, KH.DTHOAI
HAVING COUNT(DC.MACB) >= ALL(SELECT COUNT(DC.MACB) 
						FROM DATCHO DC
						GROUP BY DC.MAKH)


/* Q40. .Cho	biết mã	số,	tên	và	lương	của	các	phi	công	có	khả năng	lái	nhiều	loại	máy	bay	nhất */
SELECT NV.MANV, NV.TEN, NV.LUONG
FROM NHANVIEN NV JOIN KHANANG KN
ON KN.MANV=NV.MANV
WHERE NV.LOAINV = 1
GROUP BY KN.MANV, NV.MANV, NV.TEN, NV.LUONG
HAVING COUNT(KN.MALOAI) >= ALL(SELECT COUNT(KN.MALOAI)
						FROM KHANANG KN GROUP BY KN.MANV)

/* Q41. Cho	biết	thông	tin	(mã	nhân	viên,	tên,	lương)	của	nhân	viên	có	mức	lương	cao	nhất. */
SELECT NV.MANV, NV.TEN, NV.LUONG
FROM NHANVIEN NV
WHERE NV.LUONG >= ALL(SELECT NV.LUONG FROM NHANVIEN NV)

/* Q42. Cho	biết	tên,	địa chỉ của các nhân	viên	có lương	cao	nhất trong	phi	hành	đoàn	(các	nhân	
viên	được phân	công	trong	một chuyến	bay)	mà	người	đó	tham	gia. */
/******** CHƯA HIỂU LẮM :(( *********/
SELECT DISTINCT NV.TEN, NV.DCHI
FROM NHANVIEN NV JOIN PHANCONG PC ON PC.MANV=NV.MANV
JOIN (
	SELECT PC.MACB, MAX(NV.LUONG) 'LUONGCAONHAT'
	FROM NHANVIEN NV JOIN PHANCONG PC ON NV.MANV=PC.MANV
	GROUP BY PC.MACB
) MAX_LUONG ON PC.MACB=MAX_LUONG.MACB AND NV.LUONG=MAX_LUONG.LUONGCAONHAT

/* Q43. Cho	biết mã chuyến bay,	giờ đi	và giờ đến của chuyến bay	bay	sớm nhất trong	ngày. */
SELECT CB.MACB, CB.GIODI, CB.GIODEN
FROM CHUYENBAY CB
WHERE CB.GIODI <= ALL(SELECT DISTINCT CB.GIODI FROM CHUYENBAY CB)

/* Q44. Cho	biết mã	chuyến bay	có thời gian	bay	dài nhất.	Xuất	ra	mã	chuyến	bay	và	thời	gian	bay	
(tính	bằng	phút) */
SELECT CB.MACB, DATEDIFF(MINUTE, CB.GIODI, CB.GIODEN) 'THOIGIANBAY (PHUT)'
FROM CHUYENBAY CB
WHERE DATEDIFF(MINUTE, CB.GIODI, CB.GIODEN) >= ALL(SELECT DATEDIFF(MINUTE, CB.GIODI, CB.GIODEN) FROM CHUYENBAY CB)

/* Q45. Cho	biết mã	chuyến bay	có thời gian	bay	ít	nhất.	Xuất	ra	mã	chuyến	bay	và	thời	gian	bay.*/
SELECT CB.MACB, DATEDIFF(MINUTE, CB.GIODI, CB.GIODEN) 'THOIGIANBAY (PHUT)'
FROM CHUYENBAY CB
WHERE DATEDIFF(MINUTE, CB.GIODI, CB.GIODEN) <= ALL(SELECT DATEDIFF(MINUTE, CB.GIODI, CB.GIODEN) FROM CHUYENBAY CB)

/* Q46. Cho	biết mã chuyến bay	và ngày đi	của những chuyến bay	bay	trên	loại máy bay	B747	
nhiều nhất */
SELECT LB.MACB, LB.NGAYDI
FROM LICHBAY LB
WHERE LB.MACB IN (
	SELECT LB.MACB
	FROM LICHBAY LB
	WHERE LB.MALOAI='B747'
	GROUP BY LB.MACB
	HAVING COUNT(*) >= ALL (SELECT COUNT(*) FROM LICHBAY LB WHERE LB.MALOAI='B747' GROUP BY LB.MACB)
)

/* Với	mỗi	chuyến	bay	có	trên	3	hành	khách,	cho	biết	mã	chuyến	bay	và	số lượng	nhân	viên	
trên	chuyến	bay	đó.	Xuất	ra	mã	chuyến	bay	và	số lượng	nhân	viên */

--------CÁCH NÀY SAI RÒI
/* SELECT DISTINCT CB.MACB, COUNT(PC.MANV) 'SOLUONGNHANVIEN'
FROM CHUYENBAY CB JOIN PHANCONG PC
ON PC.MACB= CB.MACB 
JOIN DATCHO DC ON DC.MACB=PC.MACB
GROUP BY CB.MACB, PC.MANV, DC.MACB
HAVING COUNT(DC.MAKH)>3
*/

SELECT DISTINCT TEMP.MACB, COUNT(DISTINCT PC.MANV) 'SLNV'
FROM (SELECT DC.MACB, COUNT(DC.MAKH) 'SL HANH KHACH' FROM DATCHO DC
GROUP BY DC.MACB HAVING COUNT(DC.MAKH) >3 ) TEMP 
LEFT JOIN PHANCONG PC ON TEMP.MACB = PC.MACB
GROUP BY TEMP.MACB


/* Q48. Với	mỗi	loại	nhân	viên	có	tổng	lương	trên	600000,	cho	biết	số lượng	nhân	viên	trong	
từng	loại	nhân	viên	đó.	Xuất	ra	loại	nhân	viên,	và	số lượng	nhân	viên	tương	ứng. */
SELECT NV.LOAINV, COUNT(NV.MANV) AS SOLUONGNV
FROM NHANVIEN NV
GROUP BY NV.LOAINV
HAVING SUM(NV.LUONG)>600000

/* Q49. .Với	mỗi	chuyến	bay	có	trên	3	nhân	viên,	cho biết	mã	chuyến	bay	và	số lượng	khách	hàng	
đã	đặt	chỗ trên	chuyến	bay	đó */
SELECT TEMP.MACB, COUNT(DISTINCT DC.MAKH) 'SL HANH KHACH'
FROM (SELECT PC.MACB, COUNT(PC.MANV) 'SLNV' FROM PHANCONG PC
GROUP BY PC.MACB HAVING COUNT(PC.MANV) > 3) TEMP 
LEFT JOIN DATCHO DC ON TEMP.MACB = DC.MACB
GROUP BY TEMP.MACB

/* Q50. Với	mỗi	loại	máy	bay	có	nhiều	hơn	một	chiếc,	cho	biết	số lượng	chuyến	bay	đã	được	bố
trí	bay	bằng	loại	máy	bay	đó.	Xuất	ra	mã	loại	và	số lượng */
SELECT LB.MALOAI, COUNT(LB.MACB) AS SOLUONG
FROM LICHBAY LB
WHERE LB.MALOAI IN(SELECT LB.MALOAI FROM LICHBAY LB
				GROUP BY LB.MALOAI
				HAVING COUNT(LB.SOHIEU)>1)
GROUP BY LB.MALOAI

-- *********** PHÉP CHIA
/* Q51.Cho	biết mã	những	chuyến bay đã bay	tất cả các máy bay	của hãng "Boeing". */
SELECT LB.MACB
FROM LICHBAY LB
WHERE NOT EXISTS (	SELECT LMB.MALOAI FROM LOAIMB LMB
					WHERE LMB.HANGSX='Boeing'
					EXCEPT
					SELECT LB2.MALOAI FROM LICHBAY LB2
					WHERE LB2.MACB = LB.MACB )

/* Q52.Cho	biết mã	và	tên	phi	công	có khả năng	lái	tất cả các máy bay	của hãng "Airbus". */
SELECT NV.MANV, NV.TEN
FROM NHANVIEN NV 
WHERE NV.LOAINV = 1 AND NOT EXISTS (	SELECT LMB.MALOAI FROM LOAIMB LMB
					WHERE LMB.HANGSX='Airbus'
					EXCEPT
					SELECT KN.MALOAI FROM KHANANG KN 
					WHERE KN.MANV=NV.MANV)

/* Q53.Cho	biết tên	nhân	viên	(không	phải là phi	công)	được phân	công	bay	vào	tất cả các
chuyến bay	có mã 100 */
SELECT NV.TEN
FROM NHANVIEN NV
WHERE NV.LOAINV=0 AND NOT EXISTS (	SELECT LB.MACB, LB.NGAYDI FROM  LICHBAY LB
									WHERE LB.MACB='100'
									EXCEPT 
									SELECT PC.MACB, PC.NGAYDI FROM PHANCONG PC
									WHERE PC.MANV=NV.MANV)

/* Q54.Cho	biết	ngày	đi	nào	mà	có	tất	cả các	loại	máy	bay	của	hãng	"Boeing"	tham	gia */

SELECT LB.NGAYDI
FROM LICHBAY LB
WHERE NOT EXISTS ( SELECT LMB.MALOAI FROM LOAIMB LMB
					WHERE LMB.HANGSX='Boeing'
					EXCEPT
					SELECT LB1.MALOAI FROM LICHBAY LB1
					WHERE LB1.NGAYDI=LB.NGAYDI)


/* Q55.Cho	biết	loại	máy	bay	của	hãng	"Boeing"	nào	có	tham	gia	vào	tất	cả các	ngày	đi. */
SELECT LMB.MALOAI
FROM LOAIMB LMB
WHERE LMB.HANGSX='Boeing' AND NOT EXISTS (SELECT LB.NGAYDI FROM LICHBAY LB
											EXCEPT 
											SELECT LB.NGAYDI FROM LICHBAY LB
											WHERE LB.MALOAI=LMB.MALOAI)

/* Q56.Cho	biết	mã	và	tên	các	khách	hàng	có	đặt	chổ trong	tất	cả các	ngày	từ 31/10/2000	đến	
1/1/2000 */
SELECT KH.MAKH, KH.TEN
FROM KHACHHANG KH
WHERE NOT EXISTS ( SELECT DC.NGAYDI FROM DATCHO DC
					WHERE DC.NGAYDI BETWEEN '2000-1-1' AND '2000-10-31'
					EXCEPT
					SELECT DC.NGAYDI
					FROM DATCHO DC
					WHERE DC.MAKH=KH.MAKH)

/* Q57.Cho	biết	mã	và	tên	phi	công không	có	khả năng	lái	được	tất	cả các	máy	bay	của	hãng	
"Airbus" */
/*======XEM LẠI========*/
SELECT NV.MANV, NV.TEN
FROM NHANVIEN NV
WHERE NV.LOAINV=1 AND NOT EXISTS (	SELECT LMB.MALOAI FROM LOAIMB LMB
									WHERE LMB.HANGSX='Airbus'
									EXCEPT
									SELECT KN.MALOAI FROM KHANANG KN
									WHERE KN.MANV=NV.MANV)

/* Q58.Cho	biết	sân	bay	nào	đã	có	tất	cả các	loại	máy	bay	của	hãng	"Boeing"	xuất	phát */
SELECT CB.SBDI
FROM CHUYENBAY CB
WHERE NOT EXISTS (	SELECT  LMB1.MALOAI FROM  CHUYENBAY CB1 JOIN LICHBAY LB1 
					ON CB1.MACB=LB1.MACB JOIN LOAIMB LMB1 ON LB1.MALOAI=LMB1.MALOAI
					WHERE LMB1.HANGSX='Boeing'
					EXCEPT
					SELECT LB1.MALOAI
					FROM LICHBAY LB1 JOIN CHUYENBAY CB1 ON CB1.MACB=LB1.MACB
					WHERE CB1.SBDI=CB.SBDI)


			