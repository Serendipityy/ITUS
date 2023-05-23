USE MASTER
GO

IF DB_ID('QLSinhVien') IS NOT NULL
DROP DATABASE QLSinhVien
GO

CREATE DATABASE QLSinhVien
GO

USE QLSinhVien
SET DATEFORMAT DMY
GO

CREATE TABLE Khoa 
(
	ma varchar(10),
	tenKhoa nvarchar(100),
	namThanhLap int
	CONSTRAINT PK_Khoa
	PRIMARY KEY(ma)
)

CREATE TABLE KhoaHoc
(
	Ma varchar(10),
	namBatDau int,
	namKetThuc int
	CONSTRAINT PK_KhoaHoc
	PRIMARY KEY(Ma)
)

CREATE TABLE SinhVien
(
	Ma varchar(10),
	hoTen nvarchar(100),
	namSinh int,
	danToc nvarchar(20),
	maLop varchar(10),
	CONSTRAINT PK_SinhVien
	PRIMARY KEY(Ma)
)

CREATE TABLE ChuongTrinh
(
	Ma varchar(10),
	tenChuongTrinh nvarchar(100)
	CONSTRAINT PK_ChuongTrinh
	PRIMARY KEY (Ma)
)

CREATE TABLE MonHoc
(
	Ma varchar(10),
	tenMonHoc nvarchar(100),
	maKhoa varchar(10)
	CONSTRAINT PK_MonHoc
	PRIMARY KEY(Ma)
)

CREATE TABLE KetQua 
(
	maSinhVien varchar(10),
	maMonHoc varchar(10),
	lanThi int,
	diem float,
	CONSTRAINT PK_KetQua
	PRIMARY KEY(maSinhVien, maMonHoc,lanThi)
)

CREATE TABLE GiangKhoa
(
	maChuongTrinh varchar(10),
	maKhoa varchar(10),
	maMonHoc varchar(10),
	namHoc int,
	hocKy int,
	soTietLyThuyet int,
	soTietThucHanh int,
	soTinChi int,
	CONSTRAINT PK_GiangKhoa
	PRIMARY KEY(maChuongTrinh, maKhoa, maMonHoc)
)

CREATE TABLE Lop
(
	Ma varchar(10),
	maKhoaHoc varchar(10),
	maKhoa varchar(10),
	maChuongTrinh varchar(10),
	soThuTu int,
	CONSTRAINT PK_Lop
	PRIMARY KEY(Ma)
)


ALTER TABLE MonHoc ADD
	CONSTRAINT FK_MonHoc_Khoa FOREIGN KEY(maKhoa) REFERENCES Khoa(ma)

ALTER TABLE KetQua ADD
	CONSTRAINT FK_KetQua_SinhVien FOREIGN KEY(maSinhVien) REFERENCES SinhVien(Ma),
	CONSTRAINT FK_KetQua_MonHoc FOREIGN KEY(maMonHoc) REFERENCES MonHoc(Ma)

ALTER TABLE GiangKhoa ADD
	CONSTRAINT FK_GiangKhoa_ChuongTrinh FOREIGN KEY(maChuongTrinh) REFERENCES ChuongTrinh(Ma),
	CONSTRAINT FK_GiangKhoa_Khoa FOREIGN KEY(maKhoa) REFERENCES Khoa(ma),
	CONSTRAINT FK_GiangKhoa_MonHoc FOREIGN KEY(maMonHoc) REFERENCES MonHoc(Ma)

ALTER TABLE Lop ADD
	CONSTRAINT FK_Lop_KhoaHoc FOREIGN KEY(maKhoaHoc) REFERENCES KhoaHoc(Ma),
	CONSTRAINT FK_Lop_Khoa FOREIGN KEY(maKhoa) REFERENCES Khoa(ma),
	CONSTRAINT FK_Lop_ChuongTrinh FOREIGN KEY(maChuongTrinh) REFERENCES ChuongTrinh(Ma)

ALTER TABLE SinhVien ADD
	CONSTRAINT FK_SinhVien_Lop FOREIGN KEY(maLop) REFERENCES Lop(Ma)
INSERT INTO Khoa VALUES
	('CNTT',N'Công nghệ thông tin',1995),
	('VL',N'Vật Lý',1970)

INSERT INTO KhoaHoc VALUES
	('K2002',2002,2006),
	('K2003',2003,2007),
	('K2004',2004,2008)

INSERT INTO SinhVien VALUES
	('0212001',N'Nguyễn Vĩnh An',1984,'Kinh',NULL),
	('0212002',N'Nguyễn Thanh Bình',1985,'Kinh',NULL),
	('0212003',N'Nguyễn Thanh Cường',1984,'Kinh',NULL),
	('0212004',N'Nguyễn Quốc Duy',1983,'Kinh',NULL),
	('0311001',N'Phạm Tuấn Anh',1985,'Kinh',NULL),
	('0311002',N'Huỳnh Thanh Sang',1984,'Kinh',NULL)


INSERT INTO ChuongTrinh VALUES
	('CQ',N'Chính Qui')

INSERT INTO MonHoc VALUES
	('THT01',N'Toán Cao cấp A1','CNTT'),
	('VLT01',N'Toán cao cấp A1','VL'),
	('THT02',N'Toán rời rạc','CNTT'),
	('THCS01',N'Cấu trúc dữ liệu 1','CNTT'),
	('THCS02',N'Hệ điều hành','CNTT')

INSERT INTO KetQua VALUES
	('0212001','THT01',1,4),
	('0212001','THT01',2,7),
	('0212002','THT01',1,8),
	('0212003','THT01',1,6),
	('0212004','THT01',1,9),
	('0212001','THT02',1,8),
	('0212002','THT02',1,5.5),
	('0212003','THT02',1,4),
	('0212003','THT02',2,6),
	('0212001','THCS01',1,6.5),
	('0212002','THCS01',1,4),
	('0212003','THCS01',1,7)

INSERT INTO GiangKhoa VALUES
	('CQ','CNTT','THT01',2003,1,60,0,5),
	('CQ','CNTT','THT02',2003,2,45,0,4),
	('CQ','CNTT','THCS01',2004,1,45,30,4)

INSERT INTO Lop VALUES
	('TH2002/01','K2002','CNTT','CQ',1),
	('TH2002/02','K2002','CNTT','CQ',2),
	('VL2003/01','K2003','VL','CQ',1)

UPDATE SinhVien SET maLop='TH2002/01' WHERE Ma='0212001'
UPDATE SinhVien SET maLop='TH2002/01' WHERE Ma='0212002'
UPDATE SinhVien SET maLop='TH2002/02' WHERE Ma='0212003'
UPDATE SinhVien SET maLop='TH2002/02' WHERE Ma='0212004'
UPDATE SinhVien SET maLop='VL2003/01' WHERE Ma='0311001'
UPDATE SinhVien SET maLop='VL2003/01' WHERE Ma='0311002'
SELECT * FROM dbo.Khoa
SELECT * FROM dbo.KhoaHoc
SELECT * FROM dbo.SinhVien
SELECT * FROM dbo.ChuongTrinh
SELECT * FROM dbo.MonHoc
SELECT * FROM dbo.KetQua
SELECT * FROM dbo.GiangKhoa
SELECT * FROM dbo.Lop

-- 4. TRUY VẤN
--4.1. Danh sách các sinh viên khoa "Công nghệ Thông tin" khóa 2002-2006
SELECT SV.*
FROM SINHVIEN SV
JOIN Lop L ON SV.maLop=L.Ma
JOIN KhoaHoc KH ON KH.Ma=L.maKhoaHoc
JOIN Khoa K ON L.maKhoa=K.ma
WHERE KH.namBatDau=2002 AND KH.namKetThuc=2006 AND K.tenKhoa = N'Công nghệ thông tin'

--4.2. Cho biết các sinh viên (MSSV, họ tên, năm sinh) của các sinh viên
-- học sớm hơn tuổi quy định(theo tuổi qui đinhk thì sinh viên đủ 18 tuổi
-- khi bắt đầu khóa học)