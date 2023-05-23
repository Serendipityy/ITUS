USE MASTER
GO

IF DB_ID('QLTruongHoc') IS NOT NULL
DROP DATABASE QLTruongHoc
GO

CREATE DATABASE QLTruongHoc
GO

USE QLTruongHoc
SET DATEFORMAT dmy
GO

CREATE TABLE TRUONG
(
	MaTruong char(5),
	TenTruong nvarchar(40),
	DiaChi nvarchar(40),
	NamTL int,
	ChiDoanTruong char(5),
	CONSTRAINT PK_TRUONG
	PRIMARY KEY(MaTruong)	
)

CREATE TABLE LOPHOC
(
	MaLop char(5),
	TenLop nvarchar(40),
	GVCN nvarchar(40),
	MaTruong char(5),
	LopTruong char(5),
	CONSTRAINT PK_LOPHOC 
	PRIMARY KEY(MaLop)
)

CREATE TABLE HOCSINH
(
	MaHS char(5),
	MaTruong char(5),
	HoTen nvarchar(40),
	NgaySinh date,
	GioiTinh nchar(3),
	MaLop char(5),
	CONSTRAINT PK_HOOCSINH
	PRIMARY KEY(MaHS,MaTruong)
)

ALTER TABLE TRUONG ADD
	CONSTRAINT FK_TRUONG_HOCSINH FOREIGN KEY(ChiDoanTruong,MaTruong) REFERENCES HOCSINH(MaHS,MaTruong)

ALTER TABLE LOPHOC ADD
	CONSTRAINT FK_LOPHOC_TRUONG FOREIGN KEY(MaTruong) REFERENCES TRUONG(MaTruong),
	CONSTRAINT FK_LOPHOC_HOCSINH FOREIGN KEY(LopTruong,MaTruong) REFERENCES HOCSINH(MaHS,MaTruong)

ALTER TABLE HOCSINH ADD
	CONSTRAINT FK_HOCSINH_TRUONG FOREIGN KEY(MaTruong) REFERENCES TRUONG(MaTruong),
	CONSTRAINT FK_HOCSINH_LOPHOC FOREIGN KEY(MaLop) REFERENCES LOPHOC(MaLop)

INSERT INTO TRUONG VALUES
	('TR01',N'Lê Hồng Phong', N'225 Nguyễn Văn Cừ, Quận 5, TP.HCM', 1995,NULL),
	('TR02',N'Lê Quý Đôn',N'125 Lê Quý Đôn, Quân 3, TP.HCM',1993,NULL)
	
INSERT INTO LOPHOC VALUES
	('LA001',N'10 chuyên Toán',N'Vương Hải','TR01',NULL),
	('LA002',N'10 chuyên Văn',N'Nguyễn Hồng Hạnh','TR01',NULL),
	('LD001',N'11 chuyên Anh',N'Trấn Trung Trí','TR02',NULL) 

INSERT INTO HOCSINH VALUES
	('HS01','TR01',N'Trần Hải','12/2/1999','Nam','LA001'),
	('HS02','TR01',N'Lê Anh Đào','30/12/1987',N'Nữ','LA001'),
	('HS03','TR01',N'Lý Khanh','6/6/1960','Nam','LA002'),
	('HS04','TR01',N'Phan Minh Trí','6/6/1960','Nam','LA002'),
	('HS01','TR02',N'Nguyễn Lan','7/3/1982',N'Nữ','LD001'),
	('HS02','TR02',N'Vũ Bình Phương','17/3/1980','Nam','LD001'),
	('HS03','TR02',N'Đặng Khải Minh','22/10/1980','Nam','LD001')


UPDATE TRUONG SET ChiDoanTruong='HS01' WHERE MaTruong='TR01'
UPDATE TRUONG SET ChiDoanTruong='HS01' WHERE MaTruong='TR02'

UPDATE LOPHOC SET LopTruong='HS02' WHERE MaLop='LA001'
UPDATE LOPHOC SET LopTruong='HS03' WHERE MaLop='LA002'
UPDATE LOPHOC SET LopTruong='HS01' WHERE MaLop='LD001'
SELECT * FROM dbo.TRUONG
SELECT * FROM dbo.LOPHOC
SELECT * FROM dbo.HOCSINH

/* Truy vấn */

/*  Cho biết thông tin mã và tên lớp có lớp trưởng họ “Nguyễn” */
SELECT LH.MaLop, LH.TenLop
FROM LOPHOC LH JOIN HOCSINH HS ON HS.MaHS = LH.LopTruong
WHERE HS.HoTen LIKE N'Nguyễn %'

/* Cho biết thông tin mã, tên trường và số lượng học sinh của từng trường */
SELECT T.MaTruong,T.TenTruong, COUNT(HS.MaHS) AS SOLUONG_HS
FROM TRUONG T JOIN HOCSINH HS ON T.MaTruong=HS.MaTruong
GROUP BY T.MaTruong,T.TenTruong

/* Cho biết mã và họ tên chi đoàn trưởng của các trường có từ 2 lớp học 
trở lên */

SELECT HS.MaHS, HS.HoTen
FROM HOCSINH HS 
JOIN LOPHOC LH ON HS.MaTruong=LH.MaTruong
JOIN TRUONG T ON T.ChiDoanTruong=HS.MaHS AND T.MaTruong=HS.MaTruong
GROUP BY HS.MaHS,HS.HoTen
HAVING COUNT(LH.MaLop) >=2



