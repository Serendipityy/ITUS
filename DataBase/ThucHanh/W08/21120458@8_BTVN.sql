/*******************Phần 3: QLKS****************/
use master
go
if DB_ID('QLKS') is not null 
drop database QLKS
go

create database QLKS
go

use QLKS
go
create table PHONG
(
	MAPHONG varchar(5),
	TINHTRANG nvarchar(5) check (TINHTRANG = N'Rảnh' or TINHTRANG = N'Bận'),
	LOAIPHONG nvarchar(10),
	DONGIA float

	constraint PK_PHONG 
	primary key (MAPHONG)
)
create table KHACHHANG
(
	MAKH varchar(5),
	HOTEN nvarchar(40),
	DIACHI nvarchar(60),
	DTH varchar(11)

	constraint PK_KHACHHANG
	primary key (MAKH)
)
create table DATPHONG
(
	MADP int,
	MAKH varchar(5),
	MAPHONG varchar(5),
	NGAYDP date,
	NGAYTRA date,
	THANHTIEN float

	constraint PK_DATPHONG 
	primary key (MADP)
)

insert PHONG
values ('B0101', N'Bận', N'Thường', 200000), ('B0102', N'Rảnh', N'Thường', 200000), ('B0103', N'Rảnh', N'Thường', 200000), 
('P0101', N'Rảnh', N'Cao cấp', 350000), ('P0102', N'Rảnh', N'Cao cấp', 350000), ('P0103', N'Bận', N'Cao cấp', 350000), 
('V0101', N'Rảnh', N'VIP', 500000), ('V0102', N'Bận', N'VIP', 500000), ('V0103', N'Bận', N'VIP', 500000), ('V0104', N'Rảnh', N'VIP', 500000)

insert KHACHHANG
values ('AA001', N'Đoàn Ngọc Minh Tâm', N'Quận 1, TPHCM', '0984827849'),
('AA002', N'Lê Nguyễn Tâm Nhi', N'Gò Vấp, TP HCM', '0376837581'),
('AA003', N'Lâm Chấn Thiên', N'Quận 9, TP HCM', '0919274574'),
('AA004', N'Đường Khả Nhi', N'Cầu Giấy, Hà Nội', '0383978473'),
('AA005', N'Mã Anh Trúc', N'Đống Đa, Hà Nội', '0838461794')

insert DATPHONG values (0, null, null, null, null, null)

alter table DATPHONG
add
	constraint FK_MAKH
	foreign key (MAKH) 
	references KHACHHANG(MAKH),
	constraint FK_MAPHONG 
	foreign key (MAPHONG) 
	references PHONG(MAPHONG)
go

--1--
create procedure spDatPhong @makh varchar(5), @maph varchar(5), @ngaydat date
as
	declare @check int = 1
	-- Nếu không tồn tại dòng nào có MAKH trùng với mã truyền vào, check = 0
	if (not exists(select * from KHACHHANG where @makh = MAKH)) set @check = 0

	-- Nếu không tồn tại phòng nào có MAPHONG trùng với mã truyền vào, check = 0
	if (not exists(select * from PHONG where @maph = MAPHONG)) set @check = 0

	-- Nếu phòng muốn đặt bận, check = 0
	if ((select TINHTRANG from PHONG where @maph = MAPHONG) = N'Bận') set @check = 0

	-- Nếu check vẫn là 1, tức dữ liệu truyền vào hợp lệ
	if (@check = 1)
	begin
		-- MADP mới = max MADP trong bảng + 1
		declare @madp int = (select max(MADP) from DATPHONG) + 1
		-- Insert dữ liệu mới vào bảng DATPHONG
		insert DATPHONG values (@madp, @makh, @maph, @ngaydat, null, null)
		-- Update tình trạng phòng cho phòng được đặt
		update PHONG set TINHTRANG = N'Bận' where @maph = MAPHONG
	end
	else print 'Du lieu khong hop le. Khong the dat phong!' -- Báo lỗi khi check = 0
go

--2--
create procedure spTraPhong @madp varchar(5), @makh varchar(5)
as
	declare @check int = 1

	-- Kiểm tra xem trong bảng DATPHONG có MADP và MAKH truyền vào hay không, nếu không check = 0
	if (not exists(select * from DATPHONG where @madp = MADP and @makh = MAKH)) set @check = 0

	-- Nếu check = 1 tức là hợp lệ, thực hiện trả phòng
	if (@check = 1)
	begin
		-- Lấy ngày đặt phòng và ngày trả phòng
		declare @ngaytra date = getdate(), @ngaydat date = (select NGAYDP from DATPHONG where @madp = MADP and @makh = MAKH)
		-- Tính số ngày mượn phòng
		declare @songay int = datediff(day, @ngaydat, @ngaytra)
		-- Lấy mã phòng để sau này dễ tính toán và cập nhật
		declare @maph varchar(5) = (select MAPHONG from DATPHONG where @madp = MADP and @makh = MAKH)
		-- Thành tiền = Số ngày mượn * Đơn giá phòng
		declare @thanhtien float = @songay * (select DONGIA from PHONG where MAPHONG = @maph)

		-- Cập nhật ngày trả và thành tiền trong bảng DATPHONG
		update DATPHONG set NGAYTRA = @ngaytra, THANHTIEN = @thanhtien where @madp = MADP and @makh = MAKH
		-- Cập nhật tình trạng phòng trong bảng PHONG
		update PHONG set TINHTRANG = N'Rảnh' where MAPHONG = @maph
	end
	else print 'Du lieu khong hop le. Khong the tra phong!' -- Báo lỗi khi check = 0
go
exec spDatPhong '12345', '49589', '4/6/2021' -- Lỗi: MAKH, MAPHONG ko tồn tại
exec spDatPhong 'AA001', 'B0101', '4/6/2021' -- Lỗi: phòng bận
exec spDatPhong 'AA001', 'B0102', '4/6/2021' -- Hợp lệ
select * from PHONG		-- Dễ thấy, phòng B0101 đã thành bận
select * from DATPHONG	-- Bảng DATPHONG có thêm dòng mới

exec spTraPhong 1, 'AA002'	-- Lỗi: MAKH không tồn tại trong bảng DATPHONG
exec spTraPhong 2, 'AA001'	-- Lỗi: MADP không tồn tại trong bảng DATPHONG
exec spTraPhong 1, 'AA001'
select * from PHONG		-- Dễ thấy, phòng B0101 đã thành rảnh
select * from DATPHONG	-- Bảng DATPHONG có thêm NGAYTRA và THANHTIEN


go
drop procedure spDatPhong
drop procedure spTraPhong