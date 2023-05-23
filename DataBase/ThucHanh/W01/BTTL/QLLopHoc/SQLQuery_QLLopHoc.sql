USE master
GO
--Tao co so du lieu bang ngon ngu SQL
IF DB_ID('test1') IS NOT NULL
DROP DATABASE test1
GO

CREATE DATABASE test1
GO

USE test1
GO

CREATE TABLE HOCSINH
(
mahs CHAR(10) PRIMARY KEY,
hoten NVARCHAR(50),
gioitinh NCHAR(3),
ngaysinh date,
diachi NVARCHAR(100),
malop CHAR(10),

)
GO

CREATE TABLE LOPHOC
(
malop CHAR(10) PRIMARY KEY,
tenlop NVARCHAR(40),
nam CHAR(4),
gvcn CHAR(10),
loptruong CHAR(10),

)
GO

CREATE TABLE GIAOVIEN
(
magv CHAR(10) PRIMARY KEY,
hoten NVARCHAR(50),
gioitinh NCHAR(3),
ngaysinh date,
diachi NVARCHAR(100),

)
GO


INSERT INTO LOPHOC (malop,tenlop,nam,gvcn,loptruong) VALUES ('L01','21CTT1','2021','GV01','HS01')
INSERT INTO LOPHOC (malop,tenlop,nam,gvcn,loptruong) VALUES ('L02','21CTT2','2021','GV02','HS02')
INSERT INTO LOPHOC (malop,tenlop,nam,gvcn,loptruong) VALUES ('L03','21CTT3','2021','GV03','HS03')
INSERT INTO LOPHOC (malop,tenlop,nam,gvcn,loptruong) VALUES ('L04','21CTT4','2021','GV04','HS04')
INSERT INTO LOPHOC (malop,tenlop,nam,gvcn,loptruong) VALUES ('L05','21CTT5','2021','GV05','HS05')


INSERT INTO HOCSINH (mahs,hoten,gioitinh,ngaysinh,diachi,malop) VALUES ('HS01',N'Nguyễn Huy Hoàng',N'Nữ','2003-03-04',N'Công xã Paris, Quận 1, TP.HCM','L01')
INSERT INTO HOCSINH (mahs,hoten,gioitinh,ngaysinh,diachi,malop) VALUES ('HS02',N'Nguyễn Ngọc Như Huyền',N'Nữ','2003-06-18',N'Số 7, công trường Lam Sơn, Bến Nghé, Quận 1, TP.HCM','L02')
INSERT INTO HOCSINH (mahs,hoten,gioitinh,ngaysinh,diachi,malop) VALUES ('HS03',N'Trần Nam Phương',N'Nam','2003-02-01',N'Vinhomes Central Park, Phường 22, Bình Thạnh','L03')
INSERT INTO HOCSINH (mahs,hoten,gioitinh,ngaysinh,diachi,malop) VALUES ('HS04',N'Vi Lý Duy Trường',N'Nam','2003-05-24',N'120 Xa lộ Hà Nội, Phường Tân Phú, Quận 9, TP.HCM','L04')
INSERT INTO HOCSINH (mahs,hoten,gioitinh,ngaysinh,diachi,malop) VALUES ('HS05',N'Vương Huỳnh Khải',N'Nam','2003-08-16',N'208 Nguyễn Hữu Cảnh, Phường 22, Quận Bình Thạnh','L05')


INSERT INTO GIAOVIEN (magv,hoten,gioitinh,ngaysinh,diachi) VALUES ('GV01',N'Lương Hán Cơ',N'Nam','1985-01-01',N'Phường Bến Thành, Quận 1, TP.HCM')
INSERT INTO GIAOVIEN (magv,hoten,gioitinh,ngaysinh,diachi) VALUES ('GV02',N'Đinh Bá Tiến',N'Nam','1980-04-04',N'1106 Võ Văn Kiệt, Phường 6, Quận 5, TP.HCM')
INSERT INTO GIAOVIEN (magv,hoten,gioitinh,ngaysinh,diachi) VALUES ('GV03',N'Lê Hà Minh',N'Nam','1990-02-03',N'Đường Nguyễn Huệ, Quận 1, TP.HCM')
INSERT INTO GIAOVIEN (magv,hoten,gioitinh,ngaysinh,diachi) VALUES ('GV04',N'Nguyễn Cao Đẳng',N'Nam','1991-06-19',N'Bùi Viện, Phạm Ngũ Lão, Đề Thám, Quận 1, TP.HCM')
INSERT INTO GIAOVIEN (magv,hoten,gioitinh,ngaysinh,diachi) VALUES ('GV05',N'Chung Thùy Linh',N'Nữ','1992-09-17',N'Quận Bình Tân, TP.HCM')

-------------------
ALTER TABLE LOPHOC ADD
CONSTRAINT FK_LOPHOC_HOCSINH
FOREIGN KEY(loptruong)
REFERENCES HOCSINH(mahs),


CONSTRAINT FK_LOPHOC_GIAOVIEN
FOREIGN KEY(gvcn)
REFERENCES GIAOVIEN(magv)

ALTER TABLE HOCSINH ADD
CONSTRAINT FK_HOCSINH_LOPHOC
FOREIGN KEY(malop)
REFERENCES LOPHOC(malop)

----------------------------

SELECT * FROM dbo.GIAOVIEN
SELECT * FROM dbo.LOPHOC
SELECT * FROM dbo.HOCSINH