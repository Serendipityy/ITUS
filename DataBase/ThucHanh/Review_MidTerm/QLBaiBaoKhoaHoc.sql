USE MASTER
GO

IF DB_ID('QLBaiBaoKhoaHoc') IS NOT NULL
DROP DATABASE QLBaiBaoKhoaHoc
GO

CREATE DATABASE QLBaiBaoKhoaHoc
GO

USE QLBaiBaoKhoaHoc
GO

CREATE TABLE CongTrinh
(
	MaCT char(5),
	GVHD char(5),
	TenCT nvarchar(80),
	ngayNop datetime,
	MaTruong char(5),
	Hang nvarchar(15),
	CONSTRAINT PK_CongTrinh
	PRIMARY KEY (MaCT)
)

CREATE TABLE TacGia
(
	MaTruong char(5),
	MaTacGia char(5),
	TenTacGia nvarchar(50),
	SoCM char(10),
	GioiTinh nchar(3),
	CONSTRAINT PK_TacGia
	PRIMARY KEY (MaTacGia, MaTruong)
)

CREATE TABLE DSTacGia_CongTrinh
(
	MaCT char(5),
	MaTruong char(5),
	MaTG char(5),
	CONSTRAINT PK_DSTacGia_CongTrinh
	PRIMARY KEY (MaCT, MaTG)
)

ALTER TABLE CongTrinh ADD
	CONSTRAINT FK_CongTrinh_TacGia FOREIGN KEY(GVHD,MaTruong) REFERENCES TacGia(MaTacGia,MaTruong)


ALTER TABLE DSTacGia_CongTrinh ADD
	CONSTRAINT FK_DSTacGia_CongTrinh_CongTrinh FOREIGN KEY(MaCT) REFERENCES CongTrinh(MaCT),
	CONSTRAINT FK_DSTacGia_CongTrinh_TacGia FOREIGN KEY(MaTG,MaTruong) REFERENCES TacGia(MaTacGia,MaTruong)
	

INSERT INTO CongTrinh VALUES('CT1',NULL,N'Tư vấn việc làm',10/22/2012,NULL,N'Nhất')
INSERT INTO CongTrinh VALUES('CT2',NULL,N'Chuyển văn bản thành SQL',09/25/2013,NULL,N'Khuyến Khích')


INSERT INTO TacGia VALUES('TN','TG001',N'Lê Nam','2222222',N'Nam')
INSERT INTO TacGia VALUES('TN','TG002',N'Hoàng Vy','3333333',N'Nữ')
INSERT INTO TacGia VALUES('TN','TG003',N'Gia Hồng','4444444',N'Nữ')
INSERT INTO TacGia VALUES('BK','TG004',N'Kim Nhung','5555555',N'Nữ')


UPDATE CongTrinh SET GVHD = 'TG001', MaTruong='TN' WHERE MaCT = 'CT1'
UPDATE CongTrinh SET GVHD = 'TG002', MaTruong='TN' WHERE MaCT = 'CT2'


INSERT INTO DSTacGia_CongTrinh VALUES('CT1','TN','TG001')
INSERT INTO DSTacGia_CongTrinh VALUES('CT1','TN','TG002')
INSERT INTO DSTacGia_CongTrinh VALUES('CT2','TN','TG001')
INSERT INTO DSTacGia_CongTrinh VALUES('CT2','TN','TG003')


SELECT * FROM dbo.CongTrinh
SELECT * FROM dbo.TacGia
SELECT * FROM dbo.DSTacGia_CongTrinh

/* Truy vấn*/

/* Cho danh sách các tác giả giới tính nam (mã, tên, mã trường) có công trình đạt hạng khuyến 
khích trong tháng này */
SELECT TG.MaTacGia, TG.MaTruong, TG.TenTacGia
FROM TacGia TG JOIN CongTrinh CT ON TG.MaTacGia = CT.GVHD
WHERE CT.Hang = N'Khuyến Khích' AND TG.GioiTinh='Nam'

/* Với mỗi tác giả, cho biết mã, tên, số công trình khoa học đã tham gia */
SELECT TG.MaTacGia, TG.TenTacGia, COUNT(DSTGCT.MaCT) AS SoLuongCongTrinh
FROM TacGia TG
LEFT JOIN DSTacGia_CongTrinh DSTGCT ON TG.MaTacGia = DSTGCT.MaTG AND TG.MaTruong = DSTGCT.MaTruong
GROUP BY TG.MaTacGia, TG.TenTacGia

/* Cho danh sách các giáo viên hướng dẫn nhiều công trình nhất */

SELECT TOP 1 TG.MaTacGia, TG.TenTacGia, COUNT(DSTG.MaCT) AS SoLuongCongTrinh
FROM TacGia TG
INNER JOIN DSTacGia_CongTrinh DSTG ON TG.MaTacGia = DSTG.MaTG AND TG.MaTruong = DSTG.MaTruong
GROUP BY TG.MaTacGia, TG.TenTacGia
ORDER BY COUNT(DSTG.MaCT) DESC
