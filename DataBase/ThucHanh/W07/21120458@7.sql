USE QuanLyDeTai
GO

--Q75--
/* Cho biết họ tên giáo viên và tên bộ môn họ làm trưởng bộ môn nếu có */
SELECT GV.HOTEN, BM.TENBM
FROM GIAOVIEN GV LEFT JOIN BOMON BM
ON GV.MAGV = BM.TRUONGBM

--Q76--
/* Cho danh sách tên bộ môn và họ tên trưởng bộ môn đó nếu có */ 
SELECT BM.TENBM, GV.HOTEN
FROM BOMON BM LEFT JOIN GIAOVIEN GV
ON BM.TRUONGBM = GV.MAGV

--Q77--
/* Cho danh sách tên giáo viên và các đề tài giáo viên đó chủ nhiệm nếu có */
SELECT GV.HOTEN, D.*
FROM GIAOVIEN GV LEFT JOIN DETAI D
ON GV.MAGV = D.GVCNDT

--Q78--
/* Xuất ra thông tin của giáo viên (MAGV, HOTEN) và mức lương của giáo viên. Mức
lương được xếp theo quy tắc: Lương của giáo viên < $1800 : “THẤP” ; Từ $1800 đến
$2200: TRUNG BÌNH; Lương > $2200: “CAO” */
SELECT MAGV, HOTEN, LUONG, (CASE
								WHEN LUONG < 1800 THEN N'THẤP'
								WHEN LUONG >= 1800 AND LUONG <= 2200 THEN N'TRUNG BÌNH'
								WHEN LUONG > 2200 THEN N'CAO'
							END) XEP_LOAI_LUONG
FROM GIAOVIEN

--Q79--
/* Xuất ra thông tin giáo viên (MAGV, HOTEN) và xếp hạng dựa vào mức lương. Nếu giáo
viên có lương cao nhất thì hạng là 1. */
SELECT GV1.MAGV, GV1.HOTEN, (SELECT COUNT(GV2.MAGV)
							 FROM GIAOVIEN GV2
							 WHERE GV2.LUONG > GV1.LUONG OR (GV2.LUONG = GV1.LUONG AND GV2.HOTEN < GV1.HOTEN)) + 1 HANG
FROM GIAOVIEN GV1
ORDER BY GV1.LUONG DESC, HOTEN ASC

--Q80--
/* Xuất ra thông tin thu nhập của giáo viên. Thu nhập của giáo viên được tính bằng
LƯƠNG + PHỤ CẤP. Nếu giáo viên là trưởng bộ môn thì PHỤ CẤP là 300, và giáo viên là
trưởng khoa thì PHỤ CẤP là 600. */
SELECT MAGV, HOTEN, (CASE 
						WHEN MAGV IN (SELECT TRUONGBM
									  FROM BOMON) 	
						THEN LUONG + 300
						WHEN MAGV IN (SELECT TRUONGKHOA
									  FROM KHOA) 	
						THEN LUONG + 600
						ELSE LUONG 
					 END) THU_NHAP
FROM GIAOVIEN 

--Q81--
/* Xuất ra năm mà giáo viên dự kiến sẽ nghĩ hưu với quy định: Tuổi nghỉ hưu của Nam là
60, của Nữ là 55. */ 
SELECT MAGV, HOTEN, (CASE PHAI
							WHEN N'Nam' THEN YEAR(NGSINH) + 60
							WHEN N'Nữ' THEN YEAR(NGSINH) + 55
					 END) NAM_NGHI_HUU
FROM GIAOVIEN
