USE QuanLyDeTai
GO
SET DATEFORMAT DMY

--Q27--
/* Cho biết số lượng giáo viên viên và tổng lương của họ. */
SELECT COUNT(GV.MAGV) 'SO LUONG GIAO VIEN', SUM(GV.LUONG) 'TONG LUONG'
FROM GIAOVIEN GV

--Q28--
/* Cho biết số lượng giáo viên và lương trung bình của từng bộ môn. */
SELECT BM.TENBM 'TEN BO MON', COUNT(GV.MAGV) 'SO LUONG GIAO VIEN', AVG(GV.LUONG) 'LUONG TRUNG BINH'
FROM GIAOVIEN GV JOIN BOMON BM ON GV.MABM = BM.MABM
GROUP BY BM.TENBM

--Q29--
/* Cho biết tên chủ đề và số lượng đề tài thuộc về chủ đề đó. */
SELECT CD.TENCD, COUNT(DT.MADT) 'SO LUONG DE TAI'
FROM CHUDE CD JOIN DETAI DT ON CD.MACD = DT.MACD
GROUP BY CD.TENCD

--Q30--
/* Cho biết tên giáo viên và số lượng đề tài mà giáo viên đó tham gia. */
SELECT GV.HOTEN, COUNT(DISTINCT TG.MADT) 'SO LUONG DE TAI GV THAM GIA'
FROM GIAOVIEN GV JOIN THAMGIADT TG ON GV.MAGV = TG.MAGV
GROUP BY TG.MAGV, GV.HOTEN

--Q31--
/* Cho biết tên giáo viên và số lượng đề tài mà giáo viên đó làm chủ nhiệm. */
SELECT GV.HOTEN, COUNT(DT.MADT) 'SO LUONG DE TAI GV LAM CHU NHIEM'
FROM GIAOVIEN GV JOIN DETAI DT ON GV.MAGV = DT.GVCNDT
GROUP BY GV.MAGV, GV.HOTEN

--Q32--
/* Với mỗi giáo viên cho tên giáo viên và số người thân của giáo viên đó. */
SELECT GV.MAGV, GV.HOTEN, COUNT(NT.TEN) 'SO NGUOI THAN CUA GV'
FROM GIAOVIEN GV LEFT JOIN NGUOITHAN NT ON GV.MAGV = NT.MAGV
GROUP BY GV.MAGV, GV.HOTEN

--Q33--
/* Cho biết tên những giáo viên đã tham gia từ 3 đề tài trở lên. */
SELECT GV.HOTEN
FROM GIAOVIEN GV JOIN THAMGIADT TG ON GV.MAGV = TG.MAGV
GROUP BY GV.MAGV, GV.HOTEN
HAVING COUNT(DISTINCT TG.MADT)>= 3

--Q34--
/* Cho biết số lượng giáo viên đã tham gia vào đề tài Ứng dụng hóa học xanh. */
SELECT COUNT(GV.MAGV) 'SO LUONG GV THAM GIA DE TAI UNG DUNG HOA HOC XANH'
FROM GIAOVIEN GV JOIN THAMGIADT TG ON GV.MAGV = TG.MAGV JOIN DETAI DT ON TG.MADT = DT.MADT
WHERE DT.TENDT = N'Ứng dụng hóa học xanh'


