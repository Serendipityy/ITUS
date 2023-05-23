USE MASTER
GO

IF DB_ID('QLPhongBan') IS NOT NULL
DROP DATABASE QLPhongBan
GO

CREATE DATABASE QLPhongBan
GO

USE QLPhongBan
SET DATEFORMAT DMY
GO

CREATE TABLE PHONGBAN
(
	MaPhongBan char(5),
	TenPhongBan nvarchar(40),
	DiaDiem char(5),
	TruongPhong char(5)
	CONSTRAINT PK_PHONGBAN 
	PRIMARY KEY (MaPhongBan)
)

CREATE TABLE DEAN
(
	MaDeAn char(5),
	TenDeAn nvarchar(40),
	ThoiGian int,
	MaPhongBan char(5),
	TruongDeAn char(5),
	CONSTRAINT PK_DEAN
	PRIMARY KEY(MaDeAn)
)

CREATE TABLE NHANVIEN
(
	MaNV char(5),
	MaPhong char(5),
	HoTen nvarchar(40),
	NgaySinh date,
	GioiTinh nchar(3),
	Luong float,
	CONSTRAINT PK_NHANVIEN
	PRIMARY KEY(MaNV,MaPhong)
)

ALTER TABLE PHONGBAN ADD
	CONSTRAINT FK_PHONGBAN_NHANVIEN FOREIGN KEY(TruongPhong,MaPhongBan) REFERENCES NHANVIEN(MaNV,MaPhong)

ALTER TABLE DEAN ADD
	CONSTRAINT FK_DEAN_PHONGBAN FOREIGN KEY(MaPhongBan) REFERENCES PHONGBAN(MaPhongBan),
	CONSTRAINT FK_DEAN_NHANVIEN FOREIGN KEY(TruongDeAn,MaPhongBan) REFERENCES NHANVIEN(MaNV,MaPhong)

ALTER TABLE NHANVIEN ADD
	CONSTRAINT FK_NHANVIEN_PHONGBAN FOREIGN KEY(MaPhong) REFERENCES PHONGBAN(MaPhongBan)


INSERT INTO DEAN VALUES
	('DA01',N'Ngôi nhà thông minh',120,NULL,NULL),
	('DA02',N'Hành tinh xanh',120,NULL,NULL),
	('DA03',N'Công viên xanh',100,NULL,NULL)

INSERT INTO PHONGBAN VALUES
	('P001',N'Nghiên cứu','C444',NULL),
	('P002',N'Kế hoạch','B234',NULL),
	('P003',N'Nhân sự','D111',NULL)


INSERT INTO NHANVIEN VALUES
	('NV01','P001',N'Trần Hải','12/2/1999','Nam',2500),
	('NV02','P001',N'Lê Anh Đào','30/12/1987',N'Nữ',3000),
	('NV01','P002',N'Lý Khanh','6/6/1960','Nam',1000),
	('NV02','P002',N'Phan Minh Trí','6/6/1960','Nam',2500),
	('NV03','P002',N'Nguyễn Lan','7/3/1982',N'Nữ',3000),
	('NV01','P003',N'Vũ Bình Phương','17/3/1980','Nam',3000),
	('NV02','P003',N'Đặng Khải Minh','22/10/1980','Nam',1400)

UPDATE PHONGBAN SET TruongPhong='NV02' WHERE MaPhongBan ='P001'
UPDATE PHONGBAN SET TruongPhong='NV03' WHERE MaPhongBan ='P002'
UPDATE PHONGBAN SET TruongPhong='NV01' WHERE MaPhongBan ='P003'

UPDATE DEAN SET MaPhongBan='P001', TruongDeAn='NV02' WHERE MaDeAn = 'DA01'
UPDATE DEAN SET MaPhongBan='P002', TruongDeAn='NV01' WHERE MaDeAn = 'DA02'
UPDATE DEAN SET MaPhongBan='P002', TruongDeAn='NV02' WHERE MaDeAn = 'DA03'

SELECT * FROM dbo.DEAN
SELECT * FROM dbo.PHONGBAN
SELECT * FROM dbo.NHANVIEN

/* Truy vấn */
/*   Cho biết thông tin mã và tên nhân viên vừa là trưởng phòng vừa là 
trưởng đề án. */
SELECT NV.MaNV,NV.HoTen
FROM NHANVIEN NV
JOIN PHONGBAN PB ON NV.MaPhong = PB.MaPhongBan
JOIN DEAN DA ON NV.MaPhong = DA.MaPhongBan
WHERE DA.TruongDeAn = PB.TruongPhong

/* Cho biết thông tin mã, tên phòng, họ tên trưởng phòng và số lượng 
nhân viên của từng phòng ban */
/* xem lại */

SELECT p.MaPhongBan, p.TenPhongBan, nvp.HoTen as TruongPhong, COUNT(nv.MaNV) as SoLuongNV
FROM PHONGBAN p
LEFT JOIN NHANVIEN nv ON p.MaPhongBan = nv.MaPhong
LEFT JOIN NHANVIEN nvp ON p.TruongPhong = nvp.MaNV AND p.MaPhongBan = nvp.MaPhong
GROUP BY p.MaPhongBan, p.TenPhongBan, nvp.HoTen

/* Cho biết thông tin mã, tên phòng ban phụ trách từ 2 đề án trở lên */
SELECT PB.MaPhongBan, PB.TenPhongBan
FROM PHONGBAN PB
JOIN DEAN DA ON PB.MaPhongBan=DA.MaPhongBan
GROUP BY PB.MaPhongBan, PB.TenPhongBan
HAVING COUNT(DA.MaDeAn) >= 2