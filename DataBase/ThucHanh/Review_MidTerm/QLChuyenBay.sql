USE MASTER
GO

IF DB_ID('QLChuyenBay') IS NOT NULL
DROP DATABASE QLChuyenBay
GO

CREATE DATABASE QLChuyenBay
GO

USE QLChuyenBay
SET DATEFORMAT MDY
GO

CREATE TABLE KHACHHANG
(
	MAKH CHAR(15),
	TEN CHAR(15),
	DCHI CHAR(50),
	DTHOAI CHAR(12),
	CONSTRAINT PK_KHACHHANG
	PRIMARY KEY(MAKH)
)

CREATE TABLE NHANVIEN
(
	MANV CHAR(15),
	TEN CHAR(15),
	DCHI CHAR(50),
	DTHOAI CHAR(12),
	LUONG NUMERIC(10,2),
	LOAINV BIT,
	CONSTRAINT PK_NHANVIEN 
	PRIMARY KEY(MANV)
)

CREATE TABLE LOAIMB
(
	HANGSX CHAR(15),
	MALOAI CHAR(15),
	CONSTRAINT PK_LOAIMB
	PRIMARY KEY(MALOAI)
)

CREATE TABLE MAYBAY
(
	SOHIEU INT, 
	MALOAI CHAR(15)
	CONSTRAINT PK_MAYBAY
	PRIMARY KEY(SOHIEU,MALOAI)
)

CREATE TABLE CHUYENBAY
(
	MACB CHAR(4),
	SBDI CHAR(3),
	SBDEN CHAR(3),
	GIODI TIME,
	GIODEN TIME,
	CONSTRAINT PK_CHUYENBAY
	PRIMARY KEY(MACB)
)

CREATE TABLE LICHBAY
(
	NGAYDI DATE,
	MACB CHAR(4),
	SOHIEU INT,
	MALOAI CHAR(15)
	CONSTRAINT PK_LICHBAY
	PRIMARY KEY(NGAYDI,MACB)
)

CREATE TABLE DATCHO
(
	MAKH CHAR(15),
	NGAYDI DATE,
	MACB CHAR(4),
	CONSTRAINT PK_DATCHO
	PRIMARY KEY(MAKH,NGAYDI,MACB)
)

CREATE TABLE KHANANG
(
	MANV CHAR(15),
	MALOAI CHAR(15),
	CONSTRAINT PK_KHANANG 
	PRIMARY KEY(MANV,MALOAI)
)

CREATE TABLE PHANCONG
(
	MANV CHAR(15),
	NGAYDI DATE,
	MACB CHAR(4),
	CONSTRAINT PK_PHANCONG
	PRIMARY KEY(MANV,NGAYDI,MACB)
)

ALTER TABLE MAYBAY ADD
	CONSTRAINT FK_MAYBAY_LOAIMB FOREIGN KEY(MALOAI) REFERENCES LOAIMB(MALOAI)

ALTER TABLE LICHBAY ADD
	CONSTRAINT FK_LICHBAY_CHUYENBAY FOREIGN KEY(MACB) REFERENCES CHUYENBAY(MACB),
	CONSTRAINT FK_LICHBAY_MAYBAY FOREIGN KEY(SOHIEU,MALOAI) REFERENCES MAYBAY(SOHIEU,MALOAI)

ALTER TABLE DATCHO ADD
	CONSTRAINT FK_DATCHO_KHACHHANG FOREIGN KEY(MAKH) REFERENCES KHACHHANG(MAKH),
	CONSTRAINT FK_DATCHO_LICHBAY FOREIGN KEY(NGAYDI,MACB) REFERENCES LICHBAY(NGAYDI,MACB)

ALTER TABLE KHANANG ADD
	CONSTRAINT FK_KHANANG_NHANVIEN FOREIGN KEY(MANV) REFERENCES NHANVIEN(MANV),
	CONSTRAINT FK_KHANANG_LOAIMB FOREIGN KEY(MALOAI) REFERENCES LOAIMB(MALOAI)

ALTER TABLE PHANCONG ADD
	CONSTRAINT FK_PHANCONG_NHANVIEN FOREIGN KEY(MANV) REFERENCES NHANVIEN(MANV),
	CONSTRAINT FK_PHANCONG_LICHBAY FOREIGN KEY(NGAYDI,MACB) REFERENCES LICHBAY(NGAYDI,MACB)

INSERT INTO NHANVIEN VALUES
	('1006','Chi','12/6 Nguyen Khiem','8120012',150000,0),
	('1005','Giao','65 Nguyen Thai Son','8120012',500000,0),
	('1001','Huong','8 Dien Bien Phu','8330733',500000,1),
	('1002','Phong','1 Ly Thuong Kiet','8308117',450000,1),
	('1004','Phuong','351 Lac Long Quan','8308155',250000,0),
	('1003','Quang','78 Truong Dinh','8324461',350000,1),
	('1007','Tam','36 Nguyen Van Cu','8458188',500000,0)

INSERT INTO KHACHHANG VALUES
	('0009','Nga','223 Nguyen Trai','8932320'),
	('0101','Anh','567 Tran Phu','8826729'),
	('0045','Thu','285 Le Loi','8932203'),
	('0012','Ha','435 Quang Trung','8933232'),
	('0238','Hung','456 Pasteur','9812101'),
	('0397','Thanh','234 Le Van Si','8952943'),
	('0582','Mai','780 Nguyen Du',''),
	('0934','Minh','678 Le Lai',''),
	('0091','Hai','345 Hung Vuong','8893223'),
	('0314','Phuong','395 Vo Van Tan','8232320'),
	('0613','Vu','348 CMT8','8343232'),
	('0586','Son','123 Bach Dang','8556223'),
	('0422','Tien','75 Nguyen Thong','8332222')

INSERT INTO LOAIMB VALUES
	('Airbus','A310'),
	('Airbus','A320'),
	('Airbus','A330'),
	('Airbus','A340'),
	('Boeing','B727'),
	('Boeing','B747'),
	('Boeing','B757'),
	('MD','DC10'),
	('MD','DC9')
	

INSERT INTO KHANANG VALUES
	('1001','B727'),
	('1001','B747'),
	('1001','DC10'),
	('1001','DC9'),
	('1002','A320'),
	('1002','A340'),
	('1002','B757'),
	('1002','DC9'),
	('1003','A310')


INSERT INTO CHUYENBAY VALUES
	('100','SLC','BOS','08:00','17:50'),
	('112','DCA','DEN','14:00','18:07'),
	('121','STL','SLC','07:00','09:13'),
	('122','STL','YYV','08:30','10:19'),
	('206','DFW','STL','09:00','11:40'),
	('330','JFK','YYV','16:00','18:53'),
	('334','ORD','MIA','12:00','14:14'),
	('335','MIA','ORD','15:00','17:14'),
	('336','ORD','MIA','18:00','20:14'),
	('337','MIA','ORD','20:30','23:53'),
	('394','DFW','MIA','19:00','21:30'),
	('395','MIA','DFW','21:00','23:43'),
	('449','CDG','DEN','10:00','19:29'),
	('930','YYV','DCA','13:00','16:10'),
	('931','DCA','YYV','17:00','18:10'),
	('932','DCA','YYV','18:00','19:10'),
	('991','BOS','ORD','17:00','18:22')

INSERT INTO MAYBAY VALUES
	(10,'B747'),
	(11,'B727'),
	(13,'B727'),
	(13,'B747'),
	(21,'DC10'),
	(21,'DC9'),
	(22,'B757'),
	(22,'DC9'),
	(23,'DC9'),
	(24,'DC9'),
	(70,'A310'),
	(80,'A310'),
	(93,'B757')

INSERT INTO LICHBAY VALUES
	('11/01/2000','100',80,'A310'),
	('11/01/2000','112',21,'DC10'),
	('11/01/2000','206',22,'DC9'),
	('11/01/2000','334',10,'B747'),
	('11/01/2000','395',23,'DC9'),
	('11/01/2000','991',22,'B757'),
	('11/01/2000','337',10,'B747'),
	('10/31/2000','100',11,'B727'),
	('10/31/2000','112',11,'B727'),
	('10/31/2000','206',13,'B727'),
	('10/31/2000','334',10,'B747'),
	('10/31/2000','335',10,'B747'),
	('10/31/2000','337',24,'DC9'),
	('10/31/2000','449',70,'A310')

INSERT INTO DATCHO VALUES 
	('0009','11/01/2000','100'),
	('0009','10/31/2000','449'),
	('0045','11/01/2000','991'),
	('0012','10/31/2000','206'),
	('0238','10/31/2000','334'),
	('0582','11/01/2000','991'),
	('0091','11/01/2000','100'),
	('0314','10/31/2000','449'),
	('0613','11/01/2000','100'),
	('0586','11/01/2000','991'),
	('0586','10/31/2000','100'),
	('0422','10/31/2000','449')

INSERT INTO PHANCONG VALUES
	('1001','11/01/2000','100'),
	('1001','10/31/2000','100'),
	('1002','11/01/2000','100'),
	('1002','10/31/2000','100'),
	('1003','10/31/2000','100'),
	('1003','10/31/2000','337'),
	('1004','10/31/2000','100'),
	('1004','10/31/2000','337'),
	('1005','10/31/2000','337'),
	('1006','11/01/2000','991'),
	('1006','10/31/2000','337'),
	('1007','11/01/2000','112'),
	('1007','11/01/2000','991'),
	('1007','10/31/2000','206')

SELECT * FROM DBO.NHANVIEN
SELECT * FROM DBO.KHACHHANG
SELECT * FROM DBO.KHANANG
SELECT * FROM DBO.LOAIMB
SELECT * FROM DBO.DATCHO
SELECT * FROM DBO.PHANCONG
SELECT * FROM DBO.LICHBAY
SELECT * FROM DBO.CHUYENBAY
SELECT * FROM DBO.MAYBAY

/* Truy vấn */
/*  Cho	biết mã	số,	tên	phi	công,	địa	chỉ,	điện	thoại	của	các	phi	công	đã	từng	lái	máy	bay	loại	
B747 */
SELECT NV.MANV,NV.TEN,NV.DCHI,NV.DTHOAI
FROM NHANVIEN NV
JOIN KHANANG KN ON KN.MANV=NV.MANV
WHERE KN.MALOAI='B747'

/*  Cho	biết mã	số và ngày đi	của	các chuyến bay	xuất	phát	từ sân	bay	DCA	trong	khoảng	thời	
gian từ 14 giờ đến 18 giờ. */

SELECT LB.MACB, LB.NGAYDI
FROM LICHBAY LB JOIN CHUYENBAY CB ON LB.MACB=CB.MACB
WHERE CB.SBDI= 'DCA' AND (CB.GIODI BETWEEN '14:00' AND '18:00')

/* Cho	biết tên	những	nhân	viên	được	phân	công	trên	chuyến	bay	có mã số 100 xuất	phát	tại	
sân	bay	SLC.	Các	dòng	dữ liệu	xuất	ra	không	được	phép	trùng	lắp */
SELECT DISTINCT NV.TEN
FROM NHANVIEN NV JOIN PHANCONG PC ON PC.MANV=NV.MANV
JOIN CHUYENBAY CB ON CB.MACB=PC.MACB
WHERE CB.MACB='100' AND CB.SBDI='SLC'

/* Cho	biết mã	loại	và	số hiệu	máy	bay	đã	từng	xuất	phát	tại	sân	bay	MIA.	Các	dòng	dữ liệu	
xuất	ra	không	được	phép	trùng	lắp */
SELECT DISTINCT MB.MALOAI,MB.SOHIEU
FROM MAYBAY MB JOIN LICHBAY LB ON LB.MALOAI=MB.MALOAI
JOIN CHUYENBAY CB ON CB.MACB=LB.MACB
WHERE CB.SBDI='MIA'

/* Cho	biết mã	chuyến	bay,	ngày	đi,	cùng	với	tên,	địa	chỉ,	điện	thoại	của	tất	cả các	hành	
khách	đi	trên	chuyến	bay	đó.	Sắp	xếp	theo	thứ tự tăng	dần	của	mã	chuyến	bay	và	theo	
ngày	đi	giảm	dần */
SELECT DC.MACB, DC.NGAYDI,KH.TEN,KH.DCHI,KH.DTHOAI
FROM KHACHHANG KH
JOIN DATCHO DC ON DC.MAKH=KH.MAKH
ORDER BY DC.MACB ASC, DC.NGAYDI DESC

/* Cho	biết mã	chuyến	bay,	ngày	đi,	cùng	với	tên,	địa	chỉ,	điện thoại	của tất	cả những	nhân	
viên	được	phân	công	trong	chuyến	bay	đó.	Sắp	xếp	theo	thứ tự tăng	dần	của	mã	chuyến	
bay	và	theo	ngày	đi	giảm	dần. */
SELECT PC.MACB,PC.NGAYDI,NV.TEN,NV.DCHI,NV.DTHOAI
FROM PHANCONG PC 
JOIN NHANVIEN NV ON NV.MANV=PC.MANV
ORDER BY PC.MACB ASC, PC.NGAYDI DESC

/* Cho	biết mã	chuyến	bay,	ngày	đi,	mã	số và	tên	của	những phi	công	được phân	công	vào	
chuyến	bay	hạ cánh xuống	sân	bay	ORD */
SELECT PC.MACB,PC.NGAYDI,PC.MANV,NV.TEN
FROM PHANCONG PC
JOIN NHANVIEN NV ON PC.MANV=NV.MANV   
JOIN CHUYENBAY CB ON PC.MACB=CB.MACB
WHERE CB.SBDEN = 'ORD'

/* Cho	biết các	chuyến	bay	(mã	số chuyến	bay,	ngày	đi	và tên	của phi	công)	trong	đó	phi	
công	có mã 1001	được	phân	công	lái */
SELECT PC.MACB, PC.MANV,PC.NGAYDI, NV.TEN
FROM PHANCONG PC 
JOIN NHANVIEN NV ON NV.MANV=PC.MANV
WHERE PC.MANV='1001'

/* Cho	biết thông	tin	(mã	chuyến	bay,	sân	bay	đi,	giờ đi,	 giờ đến,	ngày	đi)	của	những
chuyến	bay	hạ cánh xuống DEN.	Các	chuyến	bay	được	liệt kê	theo	ngày	đi	giảm	dần	và	
sân	bay	xuất	phát	(SBDI)	tăng	dần */
SELECT CB.MACB,CB.SBDI,CB.GIODI, CB.GIODEN, LB.NGAYDI
FROM CHUYENBAY CB 
JOIN LICHBAY LB ON LB.MACB=CB.MACB
WHERE CB.SBDEN='DEN'
ORDER BY LB.NGAYDI DESC, CB.SBDI ASC

/* Với	mỗi	phi	công,	cho	biết hãng	sản	xuất	và	mã	loại	máy	bay	mà	phi	công	này	có	khả năng	
bay	được.	Xuất	ra	tên	phi	công,	hãng	sản	xuất	và	mã	loại	máy	bay. */ 
SELECT NV.TEN,LMB.HANGSX,LMB.MALOAI 
FROM NHANVIEN NV 
JOIN KHANANG KN ON KN.MANV=NV.MANV
JOIN LOAIMB LMB ON LMB.MALOAI=KN.MALOAI
WHERE NV.LOAINV=1

/* Cho	biết mã	phi	công,	tên	phi	công	đã lái	máy	bay	trong	chuyến	bay	mã số 100	vào	ngày	
11/01/2000. */
SELECT NV.MANV, NV.TEN
FROM NHANVIEN NV
JOIN PHANCONG PC ON PC.MANV=NV.MANV
WHERE PC.MACB='100' AND PC.NGAYDI='11/01/2000'

/* Cho	biết mã	phi	công,	tên	phi	công	đã lái	máy	bay	trong	chuyến	bay	mã số 100	vào	ngày	
11/01/2000. */
SELECT CB.MACB,NV.MANV,NV.TEN
FROM NHANVIEN NV
JOIN PHANCONG PC ON PC.MANV=NV.MANV
JOIN CHUYENBAY CB ON CB.MACB=PC.MACB
WHERE PC.NGAYDI='10/31/2000' AND CB.SBDI='MIA' AND CB.GIODI='20:30'

/* .Cho	biết	thông	tin	về chuyến bay	(mã	chuyến	bay,	số hiệu,	mã	loại,	hãng	sản	xuất)	mà	phi	
công	"Quang" đã	lái. */

SELECT LB.MACB,LB.SOHIEU,LB.MALOAI,LMB.HANGSX
FROM NHANVIEN NV
JOIN PHANCONG PC ON PC.MANV=NV.MANV 
JOIN LICHBAY LB ON LB.MACB=PC.MACB AND LB.NGAYDI=PC.NGAYDI
JOIN CHUYENBAY CB ON CB.MACB=LB.MACB
JOIN MAYBAY MB ON MB.SOHIEU=LB.SOHIEU AND LB.MALOAI=MB.MALOAI
JOIN LOAIMB LMB ON LMB.MALOAI=LB.MALOAI 
WHERE NV.TEN='Quang'

/* Cho	biết tên	của	những	phi	công	chưa	được phân	công	lái	chuyến	bay	nào */
SELECT NV.TEN
FROM NHANVIEN NV
WHERE NV.MANV NOT IN (
	SELECT PC.MANV
	FROM PHANCONG PC
)
/* C2:
select NV.TEN
from NHANVIEN NV 
except
select NV.TEN
from NHANVIEN NV join PHANCONG PC on NV.MANV = PC.MANV
*/


/* Cho	biết	tên	khách	hàng	đã	đi	chuyến	bay	trên	máy bay	của hãng	"Boeing" */
SELECT DISTINCT KH.TEN
FROM KHACHHANG KH 
JOIN DATCHO DC ON DC.MAKH=KH.MAKH
JOIN LICHBAY LB ON LB.MACB=DC.MACB
JOIN LOAIMB LMB ON LMB.MALOAI=LB.MALOAI
WHERE LMB.HANGSX='Boeing'


/* .Cho	biết mã	các chuyến bay	chỉ bay	với máy bay	số hiệu 10	và mã loại B747. */
SELECT LB.MACB
FROM LICHBAY LB
WHERE LB.SOHIEU=10 AND LB.MALOAI='B747'


/** GOM NHÓM + HÀM **/
/* Với	mỗi	sân	bay	(SBDEN),	cho	biết	số lượng	chuyến	bay	hạ cánh xuống	sân	bay	đó.	Kết	
quả được sắp	xếp	theo	thứ tự tăng	dần của sân	bay đến */
SELECT CB.SBDEN, COUNT(CB.MACB) AS SOLUONGCB
FROM CHUYENBAY CB
GROUP BY CB.SBDEN
ORDER BY CB.SBDEN ASC

/* Với	mỗi	sân	bay	(SBDI),	cho	biết	số lượng	chuyến	bay	xuất	phát	từ sân	bay	đó,	sắp	xếp	
theo	thứ tự tăng	dần của	sân	bay xuất	phát. */
SELECT CB.SBDI, COUNT(CB.MACB) AS SOLUONGCB
FROM CHUYENBAY CB
GROUP BY CB.SBDI
ORDER BY CB.SBDI ASC

/* .Với	mỗi	sân	bay	(SBDI),	cho	biết	số lượng	chuyến	bay	xuất	phát	theo	từng	ngày.	Xuất	ra	
mã	sân	bay	đi,	ngày	và	số lượng */
SELECT CB.SBDI,LB.NGAYDI , COUNT(CB.MACB) AS SOLUONG
FROM CHUYENBAY CB 
JOIN LICHBAY LB ON LB.MACB=CB.MACB
GROUP BY CB.SBDI,LB.NGAYDI


/* Với	mỗi	sân	bay	(SBDEN),	cho	biết	số lượng	chuyến	bay	hạ cánh theo	từng	ngày.	Xuất	ra	
mã	sân	bay	đến,	ngày	và	số lượng */
SELECT CB.SBDEN,LB.NGAYDI , COUNT(CB.MACB) AS SOLUONG
FROM CHUYENBAY CB 
JOIN LICHBAY LB ON LB.MACB=CB.MACB
GROUP BY CB.SBDEN,LB.NGAYDI

/* .Với	mỗi	lịch	bay,	cho	biết mã	chuyến	bay,	ngày	đi	cùng	với	số lượng	nhân	viên	không	phải	
là phi	công	của chuyến	bay	đó. */
SELECT LB.MACB,LB.NGAYDI,COUNT(PC.MANV) AS SOLUONG
FROM LICHBAY LB
JOIN PHANCONG PC ON (PC.MACB=LB.MACB AND LB.NGAYDI=PC.NGAYDI)
JOIN NHANVIEN NV ON PC.MANV=NV.MANV
WHERE NV.LOAINV != 1
GROUP BY LB.MACB,LB.NGAYDI

/* Số lượng	chuyến	bay	xuất	phát	từ sân	bay	MIA	vào	ngày	11/01/2000. */
SELECT COUNT(*) AS SOLUONGCHUYENBAY
FROM CHUYENBAY CB JOIN LICHBAY LB ON CB.MACB=LB.MACB
WHERE CB.SBDI='MIA' AND LB.NGAYDI='11/01/2000'

/* Với	mỗi	chuyến	bay,	cho	biết	mã	chuyến	bay,	ngày	đi,	số lượng	nhân	viên	được	phân	công	
trên	chuyến	bay	đó,	sắp	theo	thứ tự giảm	dần	của	số lượng */

SELECT PC.MACB,PC.NGAYDI,COUNT(*) AS SOLUONGNV
FROM PHANCONG PC
JOIN NHANVIEN NV ON NV.MANV=PC.MANV
GROUP BY PC.MACB,PC.NGAYDI
ORDER BY COUNT(*) DESC

/* Với	mỗi	chuyến	bay,	cho	biết	mã	chuyến	bay,	ngày	đi,	cùng	với	số lượng	hành	khách	đã	
đặt	chỗ của	chuyến	bay	đó,	sắp	theo	thứ tự giảm	dần	của	số lượng. */

SELECT DC.MACB,DC.NGAYDI,COUNT(*) AS SOLUONGKH
FROM DATCHO DC
GROUP BY DC.MACB,DC.NGAYDI
ORDER BY COUNT(*) DESC

/* Với	mỗi	chuyến	bay,	cho	biết	mã	chuyến	bay,	ngày	đi,	tổng	lương	của	phi	hành	đoàn	(các	
nhân	viên	được phân	công	trong	chuyến	bay),	sắp	xếp	theo	thứ tự tăng	dần	của	tổng	
lương */
SELECT CB.MACB, LB.NGAYDI, SUM(NV.LUONG) AS TONGLUONG
FROM CHUYENBAY CB
JOIN LICHBAY LB ON LB.MACB=CB.MACB
JOIN PHANCONG PC ON PC.MACB=CB.MACB
JOIN NHANVIEN NV ON NV.MANV=PC.MANV
GROUP BY CB.MACB, LB.NGAYDI
ORDER BY SUM(NV.LUONG)

/* Cho	biết lương	trung	bình	của	các	nhân	viên	không	phải	là	phi	công. */
SELECT AVG(NV.LUONG) AS LUONGTB
FROM NHANVIEN NV
WHERE NV.LOAINV!=1

/* Cho	biết mức	lương	trung	bình	của	các	phi	công. */
SELECT AVG(NV.LUONG) AS LUONGTB
FROM  NHANVIEN NV
WHERE NV.LOAINV = 1

/* Với	mỗi	loại	máy	bay,	cho	biết	số lượng	chuyến bay	đã	bay	trên	loại máy bay	đó		hạ cánh	
xuống	sân	bay	ORD.	Xuất	ra	mã	loại	máy	bay,	số lượng	chuyến	bay */
SELECT LB.MALOAI, COUNT(CB.MACB) AS SOLUONGCB
FROM CHUYENBAY CB
JOIN LICHBAY LB ON LB.MACB=CB.MACB
WHERE CB.SBDEN='ORD'
GROUP BY LB.MALOAI

/* .Cho	biết sân	bay	(SBDI)	và	số lượng	chuyến	bay	có	nhiều	hơn	2	chuyến	bay	xuất	phát	
trong	khoảng	10	giờ đến	22	giờ. */
SELECT CB.SBDI, COUNT(CB.MACB) AS SOLUONGCB
FROM CHUYENBAY CB
WHERE CB.GIODI BETWEEN '10:00' AND '22:00'
GROUP BY CB.SBDI
HAVING COUNT(CB.MACB)>2

/* .Cho	biết tên	phi	công	được phân	công	vào	ít	nhất	2	chuyến	bay	trong	cùng	một	ngày. */
SELECT NV.TEN
FROM NHANVIEN NV
JOIN PHANCONG PC ON PC.MANV=NV.MANV
WHERE NV.LOAINV=1
GROUP BY PC.NGAYDI, NV.TEN
HAVING COUNT(PC.MACB)>=2


/* .Cho	biết mã	chuyến	bay	và	ngày	đi	của	những	chuyến	bay	có	ít	hơn	3	hành	khách	đặt	chỗ. */

SELECT DC.MACB,DC.NGAYDI
FROM DATCHO DC
GROUP BY DC.MACB,DC.NGAYDI
HAVING COUNT(DC.MAKH) <3

/* Cho	biết số hiệu	máy	bay	và	loại	máy	bay	mà	phi	công	có mã 1001	được	phân	công	lái	
trên	2	lần */
SELECT LB.SOHIEU,LB.MALOAI
FROM LICHBAY LB JOIN PHANCONG PC ON ( PC.MACB=LB.MACB AND PC.NGAYDI=LB.NGAYDI)
WHERE PC.MANV='1001'
GROUP BY LB.SOHIEU,LB.MALOAI
HAVING COUNT(PC.MANV)>2


/* Với	mỗi	hãng	sản	xuất,	cho	biết	số lượng	loại	máy	bay	mà	hãng	đó	đã	sản	xuất.	Xuất	ra	
hãng	sản	xuất	và	số lượng */
SELECT LMB.HANGSX, COUNT(LMB.MALOAI) AS SOLUONG
FROM LOAIMB LMB
GROUP BY LMB.HANGSX

