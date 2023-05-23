USE MASTER
GO

IF DB_ID('QLBaiHat') IS NOT NULL
DROP DATABASE QLBaiHat
GO

CREATE DATABASE QLBaiHat
GO

USE QLBaiHat
SET DATEFORMAT DMY
GO

CREATE TABLE BAIHAT
(
	IDTheLoai char(10),
	IDBaiHat char(10),
	TenBaiHat nvarchar(50),
	IDTacGia char(10)
	CONSTRAINT PK_BAIHAT
	PRIMARY KEY(IDTheLoai,IDBaiHat)
)

CREATE TABLE THELOAI
(
	IDTheLoai char(10),
	Ten nvarchar(30),
	IDTheLoaiCha char(10),
	IDBaiHatTieuBieu char(10),
	CONSTRAINT PK_THELOAI
	PRIMARY KEY(IDTheLoai)
)

CREATE TABLE TACGIA
(
	IDTacGia char(10),
	HoTen nvarchar(30),
	IDTheLoaiSoTruongNhat char(10),
	CONSTRAINT PK_TACGIA
	PRIMARY KEY(IDTacGia)

)

ALTER TABLE BAIHAT ADD
	CONSTRAINT FK_BAIHAT_THELOAI FOREIGN KEY(IDTheLoai) REFERENCES THELOAI(IDTheLoai),
	CONSTRAINT FK_BAIHAT_TACGIA FOREIGN KEY(IDTacGia) REFERENCES TACGIA(IDTacGia)

ALTER TABLE THELOAI ADD
	CONSTRAINT FK_THELOAI_THELOAI FOREIGN KEY(IDTheLoaiCha) REFERENCES THELOAI(IDTheLoai)


ALTER TABLE TACGIA ADD
	CONSTRAINT FK_TACGIA_THELOAI FOREIGN KEY(IDTheLoaiSoTruongNhat) REFERENCES THELOAI(IDTheLoai)

INSERT INTO THELOAI VALUES
	('TL01',N'Nhạc trữ tình','TL00',NULL),
	('TL02',N'Nhạc cách mạng','TL00',NULL),
	('TL00',N'Nhạc Việt Nam', NULL, NULL)

INSERT INTO BAIHAT VALUES
	('TL01','BH01',N'Ngẫy hứng lý qua cầu',NULL),
	('TL01','BH02',N'Chuyến đò quê hương',NULL),
	('TL02','BH01',N'Du kích sông Thao',NULL),
	('TL02','BH02',N'Sợi nhớ sợi thương',NULL)

INSERT INTO TACGIA VALUES
	('TG01',N'Trần Tiến','TL01'),
	('TG02',N'Đỗ Nhuận','TL02'),
	('TG03',N'Phan Huỳnh Điểu','TL02'),
	('TG04',N'Vi Nhật Tảo','TL01')

UPDATE THELOAI SET IDTheLoaiCha='TL00',IDBaiHatTieuBieu='BH01' WHERE IDTheLoai='TL01'
UPDATE THELOAI SET IDTheLoaiCha='TL00',IDBaiHatTieuBieu='BH02' WHERE IDTheLoai='TL02'

UPDATE BAIHAT SET IDTacGia='TG01' WHERE IDTheLoai='TL01' AND IDBaiHat='BH01'
UPDATE BAIHAT SET IDTacGia='TG04' WHERE IDTheLoai='TL01' AND IDBaiHat='BH02'
UPDATE BAIHAT SET IDTacGia='TG02' WHERE IDTheLoai='TL02' AND IDBaiHat='BH01'
UPDATE BAIHAT SET IDTacGia='TG03' WHERE IDTheLoai='TL02' AND IDBaiHat='BH02'


SELECT * FROM dbo.THELOAI
SELECT * FROM dbo.BAIHAT
SELECT * FROM dbo.TACGIA

/* Truy vấn */

/* Cho biết các bài hát của tác giả có tên là “Trần Tiến” được bình chọn là bài hát tiêu biểu
(tên bài hát, tên thể loại */
SELECT BH.TenBaiHat,TL.Ten
FROM BAIHAT BH 
JOIN THELOAI TL ON BH.IDTheLoai=TL.IDTheLoai AND BH.IDBaiHat = TL.IDBaiHatTieuBieu
JOIN TACGIA TG ON BH.IDTacGia=TG.IDTacGia
WHERE TG.HoTen = N'Trần Tiến'


/* Cho biết các bài hát của tác giả có tên là “Trần Tiến” được bình chọn là bài hát tiêu biểu
(tên bài hát, tên thể loại */

SELECT TG.IDTacGia,TG.HoTen, COUNT (TG.IDTheLoaiSoTruongNhat) AS SOLUONG
FROM TACGIA TG JOIN BAIHAT BH ON TG.IDTheLoaiSoTruongNhat=BH.IDTheLoai AND TG.IDTacGia=BH.IDTacGia
GROUP BY TG.IDTacGia, TG.HoTen

/* Cho danh sách bài hát thuộc thể loại “nhạc trữ tình” của tác giả Đỗ Nhuận */
SELECT BH.*
FROM BAIHAT BH 
JOIN THELOAI TL ON TL.IDTheLoai=BH.IDTheLoai
JOIN TACGIA TG ON TG.IDTacGia= BH.IDTacGia
WHERE TG.HoTen=N'Đỗ Nhuận' AND TL.Ten=N'Nhạc trữ tình'

/* Cho danh sách các thể loại chưa có bài hát nào trong thể loại đó */
SELECT TL.*
FROM THELOAI TL
WHERE TL.IDTheLoai NOT IN (
	SELECT BH.IDTheLoai
	FROM BAIHAT BH
)

/*  Cho danh sách tác giả (mã, họ tên, số bài hát) của mỗi tác giả */
SELECT TG.IDTacGia,TG.HoTen,COUNT(*) AS SOBAIHAT
FROM TACGIA TG
JOIN BAIHAT BH ON BH.IDTacGia=TG.IDTacGia
GROUP BY TG.IDTacGia,TG.HoTen