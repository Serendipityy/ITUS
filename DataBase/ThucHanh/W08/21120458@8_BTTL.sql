/****************Phần 1: SP Tính toán (câu a --> câu i)****************/
--a--
/* In ra câu chào “Hello World !!!”. */
create procedure printHelloWorld
as
	print 'Hello World'
go
exec printHelloWorld
go

--b--
/* In ra tổng 2 số. */
create procedure printSumTwoNumbers @a int, @b int
as
	print @a + @b
go
exec printSumTwoNumbers 11, 14
go

--c--
/* Tính tổng 2 số (sử dụng biến output để lưu kết quả trả về). */
create procedure sumTwoNumbers @a int, @b int, @kq int out
as
	set @kq = @a + @b
go
declare @sum int
exec sumTwoNumbers 20, 3, @sum out
print @sum
go

--d--
/* In ra tổng 3 số (Sử dụng lại stored procedure Tính tổng 2 số). */
create procedure printSumThreeNumbers @a int, @b int, @c int
as
	declare @temp int
	declare @kq int
	exec sumTwoNumbers @a, @b, @temp out
	exec sumTwoNumbers @temp, @c, @kq out
	print @kq
go
exec printSumThreeNumbers 20, 25, 30
go

--e--
/* In ra tổng các số nguyên từ m đến n. */
create procedure printSumOfList @m int, @n int
as
	declare @sum int, @i int
	set @sum = 0
	set @i = @m
	while (@i <= @n)
	begin
		set @sum = @sum + @i
		set @i = @i + 1
	end
	print @sum
go
exec printSumOfList 1, 100
go

--f--
/* Kiểm tra 1 số nguyên có phải là số nguyên tố hay không. */
create procedure checkPrime @x int, @kq int out
as
	if (@x < 2) begin set @kq = 0 return end
	declare @check int, @i int
	set @check = 1
	set @i = 2
	while (@i <= sqrt(@x))
	begin
		if (@x % @i = 0) begin set @check = 0 break end
		set @i = @i + 1		
	end
	set @kq = @check
go
declare @kq int
exec checkPrime 11, @kq out
if(@kq=1)
	print 'La so nguyen to'
else 
	print 'Khong la so nguyen to'
go

--g--
/* In ra tổng các số nguyên tố trong đoạn m, n. */
create procedure sumOfPrimes @m int, @n int
as 
	declare @sum int, @i int, @check int
	set @sum = 0
	set @i = @m
	while (@i <= @n)
	begin
		exec checkPrime @i, @check out
		if (@check = 1) set @sum = @sum + @i
		set @i = @i + 1
	end
	print @sum
go
exec sumOfPrimes 1, 10
go


--h--
/* Tính ước chung lớn nhất của 2 số nguyên. */
create procedure GCD @a int, @b int, @kq int out
as
	declare @bounder int, @i int
	if (@a > @b) set @bounder = @b
	else set @bounder = @a

	set @i = 1
	while (@i <= @bounder)
	begin
		if (@a % @i = 0 and @b % @i = 0) set @kq = @i
		set @i = @i + 1
	end
go
declare @kq int
exec GCD 60, 24, @kq out
print @kq
go

--i--
/* Tính bội chung nhỏ nhất của 2 số nguyên. */
create procedure LCM @a int, @b int, @kq int out
as
	declare @bounder int, @i int
	set @bounder = @a * @b
	set @i = @a
	 while (@i <= @bounder)
	 begin
		if (@i % @a = 0 and @i % @b = 0) 
		begin set @kq = @i break end
		set @i = @i + 1
	 end
go
declare @kq int
exec LCM 15, 12, @kq out
print @kq
go

-- Drop Section
drop procedure printHelloWorld
drop procedure printSumTwoNumbers
drop procedure sumTwoNumbers
drop procedure printSumThreeNumbers
drop procedure printSumOfList
drop procedure GCD
drop procedure LCM
drop procedure checkPrime
drop procedure sumOfPrimes

/*******************Phần 2: SP QLDT (câu j --> câu t)****************/
use QuanLyDeTai
go
--j--
/* Xuất ra toàn bộ danh sách giáo viên. */
create procedure xuatTatCaGV
as
	select * from GIAOVIEN
go
exec xuatTatCaGV
go

--k--
/* Tính số lượng đề tài mà một giáo viên đang thực hiện. */
create procedure SLDeTaiGVThucHien @magv varchar(5), @kq int out
as
	set @kq = (select count(distinct TG.MADT) 'SLDT'
	from GIAOVIEN GV join THAMGIADT TG on GV.MAGV = TG.MAGV
	where GV.MAGV = @magv
	group by GV.MAGV)
go
declare @kq int
exec SLDeTaiGVThucHien '003', @kq out
print @kq
go

--l--
/* In thông tin chi tiết của một giáo viên(sử dụng lệnh print): Thông tin cá
nhân, Số lượng đề tài tham gia, Số lượng thân nhân của giáo viên đó. */
create procedure xuatThongTinGV @magv varchar(5)
as
	if (exists (select MAGV from GIAOVIEN where MAGV = @magv))
	begin
		declare @ht nvarchar(40), @luong float, @gt nvarchar(3), @ns date, @dc nvarchar(100)
		set @ht = (select HOTEN from GIAOVIEN where @magv = MAGV)
		set @luong = (select LUONG from GIAOVIEN where @magv = MAGV)
		set @gt = (select PHAI from GIAOVIEN where @magv = MAGV)
		set @ns = (select NGSINH from GIAOVIEN where @magv = MAGV)
		set @dc = (select DIACHI from GIAOVIEN where @magv = MAGV)
		declare @sldt int, @sltn int
		exec SLDeTaiGVThucHien @magv, @sldt out
		set @sltn =(select count(distinct NT.TEN) 'SLTN'
					from GIAOVIEN GV join NGUOITHAN NT on NT.MAGV = GV.MAGV
					where GV.MAGV = @magv
					group by GV.MAGV)

		print 'Ho ten: ' + cast(@ht as nvarchar) + '. Luong: ' + cast(@luong as varchar) + '. Phai: ' + cast(@gt as nvarchar) 
		print 'Ngay sinh: ' + cast(@ns as varchar) + '. Dia chi: ' + cast(@dc as nvarchar(100)) 
		print 'So luong de tai tham gia: ' + cast(@sldt as varchar) 
		print 'So luong than nhan: ' + cast(@sltn as varchar)
	end
	else print 'Ma giao vien khong ton tai'
go
exec xuatThongTinGV '002'
go

--m--
/* Kiểm tra xem một giáo viên có tồn tại hay không (dựa vào MAGV). */
create procedure KTGVTonTai @magv varchar(5), @kq int out
as
	if (exists (select MAGV from GIAOVIEN where MAGV = @magv))
		set @kq = 1	-- 1 là tồn tại
	else
		set @kq = 0 -- 0 là không tồn tại
go

--n--
/* Kiểm tra quy định của một giáo viên: Chỉ được thực hiện các đề tài mà bộ
môn của giáo viên đó làm chủ nhiệm. */
create procedure KTQuyDinhGV @magv varchar(5), @kq int out
as
	declare @mabm nvarchar(5)
	set @mabm = (select MABM from GIAOVIEN where @magv = MAGV)	-- lấy MABM của GV truyền vào

	if(not exists(select * from THAMGIADT TG join DETAI DT on TG.MADT = DT.MADT join GIAOVIEN GV on DT.GVCNDT = GV.MAGV
	where @magv = TG.MAGV and @mabm != GV.MABM))
	-- Tìm những dòng mà tại đó, MABM của GVCNDT khác với MABM của @magv tham gia
	-- Nếu không tồn tại dòng nào, tức là không có đề tài nào mà GVCNDT khác MABM với MABM của @magv, nghĩa là đúng quy định
	-- 1 là đúng, 0 là sai
		set @kq = 1	
	else
		set @kq = 0	
go

--o--
/* Thực hiện thêm một phân công cho giáo viên thực hiện một công việc của
đề tài:
o Kiểm tra thông tin đầu vào hợp lệ: giáo viên phải tồn tại, công việc
phải tồn tại, thời gian tham gia phải >0
o Kiểm tra quy định ở câu n. */
create procedure ThemPhanCongGV @magv varchar(5),@madt varchar(3), @stt int, @phucap float, @kq nvarchar(40)
as
	declare @checkGV int, @checkCV int, @checkTG int
	
	-- Kiểm tra tồn tại GV
	exec KTGVTonTai @magv, @checkGV out
	
	-- Kiểm tra tồn tại CV
	if(exists(select * from CONGVIEC where @madt = MADT and @stt = SOTT))
		set @checkCV = 1
	else
		set @checkCV = 0
	
	-- Nếu 2 cái trên thỏa, kiểm tra ngày BD và ngày KT hợp lệ hay ko
	-- Bằng cách coi coi có dòng nào mà khớp MADT, STT và thgian tham gia > 0
	if(@checkGV = 1 and @checkCV = 1)
	begin
		if(exists(select * from CONGVIEC where @madt = MADT and @stt = SOTT and datediff(day, NGAYBD, NGAYKT) > 0))
			set @checkTG = 1
		else
			set @checkTG = 0
	end
	
	-- Nếu tất cả thỏa, tiến hành thêm. Nếu không, in thông báo lỗi
	if(@checkGV = 1 and @checkCV = 1 and @checkTG = 1)
	begin
		insert THAMGIADT values (@magv, @madt, @stt, @phucap, @kq)
		print 'Them phan cong cho giao vien thanh cong'
	end
	else print 'Khong the them phan cong cho giao vien nay'
go

--p--
/* Thực hiện xoá một giáo viên theo mã. Nếu giáo viên có thông tin liên quan
(Có thân nhân, có làm đề tài, ...) thì báo lỗi. */
create procedure XoaGV @magv varchar(5)
as
	declare @checkGV int
	exec KTGVTonTai @magv, @checkGV out
	if (@checkGV = 0) print 'Khong the xoa do ma giao vien khong ton tai'
	else
		begin
			declare @sldt int, @sltn int
			exec SLDeTaiGVThucHien @magv, @sldt out
			set @sltn =(select count(distinct NT.TEN) 'SLTN'
						from GIAOVIEN GV join NGUOITHAN NT on NT.MAGV = GV.MAGV
						where GV.MAGV = @magv group by GV.MAGV)
			if(@sldt > 0) print 'Khong the xoa do giao vien co tham gia de tai'
			if(@sltn > 0) print 'Khong the xoa do giao vien co than nhan'
			if(@sldt = 0 and @sltn = 0)
			begin
				delete GIAOVIEN where @magv = MAGV
				print 'Xoa giao vien thanh cong'
			end
		end
go

--q--
/* In ra danh sách giáo viên của một phòng ban nào đó cùng với số lượng đề
tài mà giáo viên tham gia, số thân nhân, số giáo viên mà giáo viên đó quản
lý nếu có, ... */
create procedure sp_dsgv_phong_ban @magv varchar(5)
as
	--Xét magv tồn tại
	if(exists (select * from GIAOVIEN where @magv = MAGV))
	--Magv đó phảo thuộc về 1 phòng ban
	begin
		if(@magv in (select MAGV from (GIAOVIEN GV join BOMON BM on GV.MABM = BM.MABM) join KHOA KH on BM.MAKHOA = KH.MAKHOA))
			declare @hoten nvarchar(30)
			set @hoten = (select HOTEN from GIAOVIEN WHERE @magv = MAGV)
			declare @sldetai int
			declare @slthannhan int
			declare @slgv_gvql int
			set @sldetai  = (select count(distinct TGDT.MADT)
						from GIAOVIEN GV join THAMGIADT TGDT on GV.MAGV = TGDT.MAGV
						where @magv=GV.MAGV
						group by GV.MAGV)
			set @slthannhan = (select count(*) 
						   from GIAOVIEN join NGUOITHAN on GIAOVIEN.MAGV = NGUOITHAN.MAGV
						   where @MAGV = GIAOVIEN.MAGV
						   group by GIAOVIEN.MAGV)
			set @slgv_gvql = (select count(GVQL.MAGV)
							 from GIAOVIEN GV, GIAOVIEN GVQL 
							 where GV.GVQLCM= GVQL.MAGV and @MAGV=GVQL.MAGV
							 group by GVQL.MAGV)
	--Xuất thông tin: sldetai tham gia, slthannhan, slgv_gvql
			print @magv
			print @hoten
			print N'Số lượng đề tài: '
			print @sldetai
			print N'Số lượng thân nhân: '
			print @slthannhan
			print N'Số lượng giáo viên ma gv đó quản lý: '
			print @slgv_gvql
	end
	else
		print N'Gv không tồn tại '

exec sp_dsgv_phong_ban '007'
go
--r--
/* Kiểm tra quy định của 2 giáo viên a, b: Nếu a là trưởng bộ môn c của b thì
lương của a phải cao hơn lương của b. (a, b: mã giáo viên) */
create procedure KT2GV @magv1 varchar(5), @magv2 varchar(5), @kq int out
as
	declare @checkTBM int
	-- Kiểm tra xem GV1 có là trưởng bm của GV2 ko
	if(@magv1 = (select TRUONGBM from BOMON where MABM = (select MABM from GIAOVIEN where @magv2 = MAGV))) 
	begin
		declare @luong1 float, @luong2 float
		-- Lấy lương của GV1 và GV2, nếu lương1 > lương2 thì kq = 1 (đúng), ngược lại = 0 (sai)
		set @luong1 = (select LUONG from GIAOVIEN where @magv1 = MAGV)
		set @luong2 = (select LUONG from GIAOVIEN where @magv2 = MAGV)
		if (@luong1 > @luong2)
			set @kq = 1
		else
			set @kq = 0
	end
go

--s--
/* Thêm một giáo viên: Kiểm tra các quy định: Không trùng tên, tuổi > 18,
lương > 0 */
create procedure ThemGV @magv varchar(5), @ht nvarchar(40), @l float, @gt nvarchar(3), @ns datetime, 
						@dc nvarchar(100), @gvql varchar(5), @mabm nvarchar(5)
as
	if(not exists (select * from GIAOVIEN where HOTEN = @ht) and @l > 0 and datediff(year, getdate(), @ns) > 18)
		insert GIAOVIEN values (@magv, @ht, @l, @gt, @ns, @dc, @gvql, @mabm)
	else
		print 'Khong the them giao vien nay'
go

--t--
/* Mã giáo viên được xác định tự động theo quy tắc: Nếu đã có giáo viên 001,
002, 003 thì MAGV của giáo viên mới sẽ là 004. Nếu đã có giáo viên 001,
002, 005 thì MAGV của giáo viên mới là 003. */
--t--
go
create procedure DienMagvTuDong @magv char(5) out
as
begin
    declare @i int = 1
    declare @magv_new int

    while (1 = 1)
    begin
        --Kiểm tra xem MAGV có tồn tại trong bảng GIAOVIEN hay không--
        if not exists (select 1 from GIAOVIEN WHERE MAGV = RIGHT('00' + CAST(@i AS varchar(3)), 3))
        begin
            --Nếu không tồn tại, gán MAGV mới và thoát khỏi vòng lặp--
            set @magv_new = @i
            break
        end
        set @i = @i + 1
    end

    --Xác định MAGV mới dựa trên kết quả của vòng lặp--
    set @MAGV = right('00' + cast(@magv_new as varchar(3)), 3);
end
go
declare @magv char(5)
exec DienMagvTuDong @magv out
print @magv

-- Drop Section
drop procedure xuatTatCaGV
drop procedure SLDeTaiGVThucHien
drop procedure xuatThongTinGV
drop procedure KTGVTonTai
drop procedure KTQuyDinhGV
drop procedure ThemPhanCongGV
drop procedure XoaGV
drop procedure sp_dsgv_phong_ban
drop procedure KT2GV
drop procedure ThemGV
drop procedure DienMagvTuDong

