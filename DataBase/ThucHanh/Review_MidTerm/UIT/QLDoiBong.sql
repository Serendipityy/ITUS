USE MASTER
GO

IF DB_ID('QLDoiBong') IS NOT NULL
DROP DATABASE QLDoiBong
GO

CREATE DATABASE QLDoiBong
GO

USE QLDoiBong
SET DATEFORMAT DMY
GO

CREATE TABLE DOIBONG
(
	MaDoi varchar(2),
	TenDoi varchar(100),
	NamTL int,
	CONSTRAINT PK_DOIBONG
	PRIMARY KEY(MaDoi)
)

CREATE TABLE CAUTHU
(
	MaCauThu varchar(2),
	TenCauThu varchar(50),
	NgaySinh datetime,
	Phai bit,
	NoiSinh varchar(50),
	CONSTRAINT PK_CAUTHU
	PRIMARY KEY(MaCauThu)
)

CREATE TABLE CT_DB
(
	MaDoi varchar(2),
	MaCauThu varchar(2),
	NgayVaoCLB datetime,
	CONSTRAINT PK_CT_DB
	PRIMARY KEY(MaDoi,MaCauThu)

)

CREATE TABLE THIDAU
(
	MaDoi varchar(2),
	NgayThiDau datetime,
	HieuSo int,
	KetQua bit
	CONSTRAINT PK_THIDAU
	PRIMARY KEY(MaDoi,NgayThiDau)
)


/*ALTER TABLE CT_DB ADD
	CONSTRAINT FK_CT_DB_DOIBONG FOREIGN KEY(MaDoi) REFERENCES DOIBONG(MaDoi),
	CONSTRAINT FK_CT_DB_CAUTHU FOREIGN KEY(MaCauThu) REFERENCES CAUTHU(MaCauThu)
*/
ALTER TABLE THIDAU ADD
	CONSTRAINT FK_THIDAU_DOIBONG FOREIGN KEY(MaDoi) REFERENCES DOIBONG(MaDoi)



INSERT INTO DOIBONG VALUES
	('A1','The Cong', 1945),
	('A2','Song Da Nam Dinh',1983),
	('A3','Ngan Hang Dong A',2001),
	('A5','Song Lam Nghe An',1982),
	('B2','Cang Sai Gon',1985),
	('C1','Gach Dong Tam_LA',2001),
	('C2','Cong An Hai Phong',1992)

INSERT INTO CAUTHU VALUES
	('01','Huynh Duc','12/09/1974',1,'Tp.HCM'),
	('02','Hong Son','10/05/1973',1,'Ha Noi'),
	('03','Thanh Nam','25/12/1978',1,'Nam Dinh'),
	('04','Bao Khanh','01/12/1980',1, 'Ha Noi'),
	('05','Duc Thang','15/11/1976',1,'Ha Noi')


INSERT INTO CT_DB VALUES
	('A1','01','10/10/1988'),
	('A1','02','12/01/1985'),
	('A3','03','01/01/2002'),
	('A5','02','30/10/1994'),
	('B2','01','10/12/1995'),
	('C1','05','24/7/2002'),
	('C2','06','10/2/2000'),
	('C2','01','8/9/2000')

INSERT INTO THIDAU VALUES
	('A1','22/12/2004',2,1),
	('A1','26/10/2005',1,0),
	('A3','25/10/2005',0,NULL),
	('A5','10/10/2005',3,1),
	('B2','19/08/2005',3,0),
	('C1','19/05/2005',1,1),
	('C2','30/10/2004',2,0)

SELECT * FROM dbo.DOIBONG
SELECT * FROM dbo.CAUTHU
SELECT * FROM dbo.CT_DB
SELECT * FROM dbo.THIDAU

/* Đưa ra thông tin các đội bóng và số trận tham gia thi đấu của từng đội. Thông tin gồm : 
Tên đội bóng, số trận đấu */
SELECT DB.TenDoi, COUNT(TD.MaDoi) AS 'SO TRAN DAU'
FROM DOIBONG DB JOIN THIDAU TD ON DB.MaDoi=TD.MaDoi
GROUP BY DB.TenDoi


/* Đưa ra thông tin các đội bóng và số trận tham gia thi đấu của từng đội. Thông tin gồm : 
Tên đội bóng, số trận đấu */
SELECT CT.TenCauThu
FROM CAUTHU CT 
WHERE CT.MaCauThu IN(
	SELECT CTDB.MaCauThu
	FROM CT_DB CTDB
	WHERE CTDB.MaDoi='A1'
) AND MaCauThu IN(
	SELECT CTDB.MaCauThu
	FROM CT_DB CTDB
	WHERE CTDB.MaDoi='B2'
) AND MaCauThu IN(
	SELECT CTDB.MaCauThu
	FROM CT_DB CTDB
	WHERE CTDB.MaDoi='C2'
)