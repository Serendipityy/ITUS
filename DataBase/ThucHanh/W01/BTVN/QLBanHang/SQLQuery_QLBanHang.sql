USE master
GO

-- Tao co so du lieu bang ngon ngu SQL
IF DB_ID('test2') IS NOT NULL
DROP DATABASE test2
GO

CREATE DATABASE test2
GO

USE test2
GO

CREATE TABLE KHACH_HANG
(
makh CHAR(10) PRIMARY KEY,
hoten NVARCHAR(50),
gioitinh NCHAR(3),
dthoai CHAR(15),
diachi NVARCHAR(100)

)
GO

CREATE TABLE SAN_PHAM
(
masp CHAR(10) PRIMARY KEY,
tensp NVARCHAR(40),
ngaysx DATE, 
dongia FLOAT

)
GO

CREATE TABLE CT_HOA_DON
(
mahd CHAR(10) PRIMARY KEY,
masp CHAR(10),
soluong INT,
dongia FLOAT

)
GO

CREATE TABLE HOA_DON
(
mahd CHAR(10) PRIMARY KEY,
ngaylap DATE,
makh CHAR(10)

)
GO

-------------------
ALTER TABLE HOA_DON ADD
CONSTRAINT FK_HOA_DON_KHACH_HANG
FOREIGN KEY(makh)
REFERENCES KHACH_HANG(makh)

ALTER TABLE CT_HOA_DON ADD
CONSTRAINT FK_CT_HOA_DON_SAN_PHAM
FOREIGN KEY(masp)
REFERENCES SAN_PHAM(masp),
CONSTRAINT FK_CT_HOA_DON_HOA_DON
FOREIGN KEY(mahd)
REFERENCES HOA_DON(mahd)

------------------------------
INSERT INTO KHACH_HANG (makh,hoten,gioitinh,dthoai,diachi) VALUES ('KH01',N'Nguyễn Huy Hoàng',N'Nữ','0777515109',N'Thủ Đức, TP.HCM')
INSERT INTO KHACH_HANG (makh,hoten,gioitinh,dthoai,diachi) VALUES ('KH02',N'Nguyễn Ngọc Như Huyền',N'Nữ','0904336219',N'Hóc Môn, TP.HCM')
INSERT INTO KHACH_HANG (makh,hoten,gioitinh,dthoai,diachi) VALUES ('KH03',N'Trần Nam Phương',N'Nam','0366289046',N'Hóc Môn, TP.HCM')
INSERT INTO KHACH_HANG (makh,hoten,gioitinh,dthoai,diachi) VALUES ('KH04',N'Trần Anh Kiệt',N'Nam','0914255481',N'Quận 1, TP.HCM')
INSERT INTO KHACH_HANG (makh,hoten,gioitinh,dthoai,diachi) VALUES ('KH05',N'Võ Minh Khuê',N'Nam','0558217569',N'Quận 5, TP.HCM')


INSERT INTO SAN_PHAM (masp,tensp,ngaysx,dongia) VALUES (N'SP01', N'Tai nghe Xiaomi','2016-01-01','165000')
INSERT INTO SAN_PHAM (masp,tensp,ngaysx,dongia) VALUES (N'SP02', N'Bút highlight','2016-05-06','100000')
INSERT INTO SAN_PHAM (masp,tensp,ngaysx,dongia) VALUES (N'SP03', N'Ví tiền','2020-08-16','200500')
INSERT INTO SAN_PHAM (masp,tensp,ngaysx,dongia) VALUES (N'SP04', N'Giày sneaker','2021-06-06','350600')
INSERT INTO SAN_PHAM (masp,tensp,ngaysx,dongia) VALUES (N'SP05', N'Balo','2021-02-15','300000')


INSERT INTO HOA_DON (mahd,ngaylap,makh) VALUES ('HD01','2023-01-02','KH01')
INSERT INTO HOA_DON (mahd,ngaylap,makh) VALUES ('HD02','2023-05-04','KH02')
INSERT INTO HOA_DON (mahd,ngaylap,makh) VALUES ('HD03','2023-06-06','KH03')
INSERT INTO HOA_DON (mahd,ngaylap,makh) VALUES ('HD04','2023-08-04','KH04')
INSERT INTO HOA_DON (mahd,ngaylap,makh) VALUES ('HD05','2023-03-26','KH05')

INSERT INTO CT_HOA_DON (mahd,masp,soluong,dongia) VALUES ('HD01','SP01','50','200000')
INSERT INTO CT_HOA_DON (mahd,masp,soluong,dongia) VALUES ('HD02','SP02','100','400000')
INSERT INTO CT_HOA_DON (mahd,masp,soluong,dongia) VALUES ('HD03','SP03','200','650000')
INSERT INTO CT_HOA_DON (mahd,masp,soluong,dongia) VALUES ('HD04','SP04','250','666666')
INSERT INTO CT_HOA_DON (mahd,masp,soluong,dongia) VALUES ('HD05','SP05','400','750000')


SELECT * FROM dbo.KHACH_HANG
SELECT * FROM dbo.SAN_PHAM
SELECT * FROM dbo.HOA_DON
SELECT * FROM dbo.CT_HOA_DON