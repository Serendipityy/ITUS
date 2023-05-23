USE QuanLyDeTai
GO
SET DATEFORMAT DMY
--Q1--
/* Cho biết họ tên và mức lương của các giáo viên nữ. */
SELECT GV.HOTEN, GV.LUONG
FROM GIAOVIEN GV
WHERE GV.PHAI = N'Nữ'

--Q2--
/* Cho biết họ tên của các giáo viên và lương của họ sau khi tăng 10%. */
SELECT GV.HOTEN, GV.LUONG * 1.1 N'LƯƠNG SAU KHI TĂNG 10%'
FROM GIAOVIEN GV

--Q3--
/* Cho biết mã của các giáo viên có họ tên bắt đầu là “Nguyễn” và lương trên $2000 hoặc,
giáo viên là trưởng bộ môn nhận chức sau năm 1995. */
SELECT GV.MAGV
FROM GIAOVIEN GV LEFT JOIN BOMON BM ON GV.MAGV = BM.TRUONGBM 
WHERE (GV.HOTEN LIKE N'Nguyễn %' AND GV.LUONG > 2000) OR (BM.TRUONGBM IS NOT NULL AND YEAR(BM.NGAYNHANCHUC) > 1995)

--Q4--
/* Cho biết tên những giáo viên khoa Công nghệ thông tin. */
SELECT GV.HOTEN
FROM GIAOVIEN GV JOIN BOMON BM ON GV.MABM = BM.MABM JOIN KHOA K ON BM.MAKHOA = K.MAKHOA
WHERE K.TENKHOA = N'Công nghệ thông tin'

--Q5--
/* Cho biết thông tin của bộ môn cùng thông tin giảng viên làm trưởng bộ môn đó. */
SELECT *
FROM GIAOVIEN GV JOIN BOMON BM ON GV.MAGV = BM.TRUONGBM

--Q6--
/* Với mỗi giáo viên, hãy cho biết thông tin của bộ môn mà họ đang làm việc. */
SELECT GV.MAGV, GV.HOTEN, BM.*
FROM GIAOVIEN GV JOIN BOMON BM ON GV.MABM = BM.MABM

--Q7--
/* Cho biết tên đề tài và giáo viên chủ nhiệm đề tài. */
SELECT DT.TENDT, GV.HOTEN N'GIÁO VIÊN CHỦ NHIỆM ĐỀ TÀI'
FROM DETAI DT JOIN GIAOVIEN GV ON DT.GVCNDT = GV.MAGV

--Q8--
/* Với mỗi khoa cho biết thông tin trưởng khoa. */
SELECT GV.*
FROM KHOA K LEFT JOIN GIAOVIEN GV ON GV.MAGV = K.TRUONGKHOA
ORDER BY GV.MAGV ASC

--Q9--
/* Cho biết các giáo viên của bộ môn “Vi sinh” có tham gia đề tài 006. */
SELECT DISTINCT GV.*
FROM GIAOVIEN GV JOIN BOMON BM ON GV.MABM = BM.MABM JOIN THAMGIADT TGIA ON GV.MAGV = TGIA.MAGV
WHERE BM.TENBM = N'Vi sinh' AND TGIA.MADT = '006'

--Q10--
/* Với những đề tài thuộc cấp quản lý “Thành phố”, cho biết mã đề tài, đề tài thuộc về chủ
đề nào, họ tên người chủ nghiệm đề tài cùng với ngày sinh và địa chỉ của người ấy. */
SELECT DT.MADT, CD.TENCD, GV.HOTEN, GV.NGSINH, GV.DIACHI
FROM DETAI DT JOIN CHUDE CD ON DT.MACD = CD.MACD JOIN GIAOVIEN GV ON DT.GVCNDT = GV.MAGV
WHERE DT.CAPQL = N'Thành phố'

--Q11--
/* Tìm họ tên của từng giáo viên và người phụ trách chuyên môn trực tiếp của giáo viên
đó. */
SELECT GV1.HOTEN 'HO TEN GIAO VIEN', GV2.HOTEN 'HO TEN GVQLCM'
FROM GIAOVIEN GV1 LEFT JOIN GIAOVIEN GV2 ON GV1.GVQLCM = GV2.MAGV

--Q12--
/* Tìm họ tên của những giáo viên được “Nguyễn Thanh Tùng” phụ trách trực tiếp. */
SELECT GV1.HOTEN
FROM GIAOVIEN GV1 JOIN GIAOVIEN GV2 ON GV1.GVQLCM = GV2.MAGV
WHERE GV2.HOTEN = N'Nguyễn Thanh Tùng'

--Q13--
/* Cho biết tên giáo viên là trưởng bộ môn “Hệ thống thông tin”. */
SELECT GV.HOTEN
FROM GIAOVIEN GV JOIN BOMON BM ON GV.MAGV = BM.TRUONGBM
WHERE BM.TENBM = N'Hệ thống thông tin'

--Q14--
/* Cho biết tên người chủ nhiệm đề tài của những đề tài thuộc chủ đề Quản lý giáo dục. */
SELECT DISTINCT GV.HOTEN
FROM GIAOVIEN GV JOIN DETAI DT ON GV.MAGV = DT.GVCNDT JOIN CHUDE CD ON DT.MACD = CD.MACD
WHERE CD.TENCD = N'Quản lý giáo dục'

--Q15--
/* Cho biết tên các công việc của đề tài HTTT quản lý các trường ĐH có thời gian bắt đầu
trong tháng 3/2008. */
SELECT CV.TENCV
FROM DETAI DT JOIN CONGVIEC CV ON DT.MADT = CV.MADT
WHERE DT.TENDT = N'HTTT quản lý các trường ĐH' AND (MONTH(CV.NGAYBD) = 3 AND YEAR(CV.NGAYBD) = 2008)

--Q16--
/* Cho biết tên giáo viên và tên người quản lý chuyên môn của giáo viên đó. */
SELECT GV1.HOTEN, GV2.HOTEN N'Người quản lý chuyên môn'
FROM GIAOVIEN GV1 LEFT JOIN GIAOVIEN GV2 ON GV1.GVQLCM = GV2.MAGV

--Q17--
/* Cho các công việc bắt đầu trong khoảng từ 01/01/2007 đến 01/08/2007. */
SELECT CV.*
FROM CONGVIEC CV
WHERE CV.NGAYBD BETWEEN '1/1/2007' and '1/8/2007'

--Q18--
/* Cho biết họ tên các giáo viên cùng bộ môn với giáo viên “Trần Trà Hương”. */
SELECT GV1.HOTEN
FROM GIAOVIEN GV1 JOIN GIAOVIEN GV2 ON GV1.MABM = GV2.MABM
WHERE GV2.HOTEN = N'Trần Trà Hương'

--Q19--
/* Tìm những giáo viên vừa là trưởng bộ môn vừa chủ nhiệm đề tài. */
SELECT DISTINCT GV.* /* 1 giáo viên có thể chủ nhiệm nhiều đề tài */
FROM GIAOVIEN GV JOIN BOMON BM ON GV.MAGV = BM.TRUONGBM JOIN DETAI DT ON GV.MAGV = DT.GVCNDT

--Q20--
/* Cho biết tên những giáo viên vừa là trưởng khoa và vừa là trưởng bộ môn. */
SELECT GV.HOTEN
FROM GIAOVIEN GV JOIN BOMON BM ON GV.MAGV = BM.TRUONGBM JOIN KHOA K ON GV.MAGV = K.TRUONGKHOA

--Q21--
/* Cho biết tên những trưởng bộ môn mà vừa chủ nhiệm đề tài. */
SELECT DISTINCT GV.HOTEN
FROM GIAOVIEN GV JOIN BOMON BM ON GV.MAGV = BM.TRUONGBM JOIN DETAI DT ON GV.MAGV = DT.GVCNDT 

--Q22--
/* Cho biết mã số các trưởng khoa có chủ nhiệm đề tài. */
SELECT DISTINCT K.TRUONGKHOA
FROM KHOA K JOIN DETAI DT ON K.TRUONGKHOA = DT.GVCNDT

--Q23--
/* Cho biết mã số các giáo viên thuộc bộ môn “HTTT” hoặc có tham gia đề tài mã “001”. */
SELECT DISTINCT GV.MAGV /* 1 giáo viên có thể tham gia nhiều công việc trong cùng đề tài */
FROM GIAOVIEN GV JOIN THAMGIADT TGIA ON GV.MAGV = TGIA.MAGV
WHERE GV.MABM = N'HTTT' OR TGIA.MADT = '001'

--Q24--
/* Cho biết giáo viên làm việc cùng bộ môn với giáo viên 002. */
SELECT GV1.*
FROM GIAOVIEN GV1 JOIN GIAOVIEN GV2 ON GV1.MABM = GV2.MABM
WHERE GV2.MAGV = '002'

--Q25--
/* Tìm những giáo viên là trưởng bộ môn. */
SELECT GV.*
FROM GIAOVIEN GV JOIN BOMON BM ON GV.MAGV = BM.TRUONGBM
ORDER BY GV.MAGV ASC

--Q26--
/* Cho biết họ tên và mức lương của các giáo viên. */
SELECT GV.HOTEN, GV.LUONG
FROM GIAOVIEN GV