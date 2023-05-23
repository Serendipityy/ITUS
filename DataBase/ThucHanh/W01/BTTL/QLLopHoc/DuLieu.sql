USE [QLLopHoc]
GO
INSERT [dbo].[GIAOVIEN] ([magv], [hoten], [gioitinh], [ngaysinh], [diachi]) VALUES (N'GV01      ', N'Lương Hán Cơ', N'Nam', CAST(N'1985-01-01' AS Date), N'Phường Bến Thành, Quận 1, TP.HCM')
INSERT [dbo].[GIAOVIEN] ([magv], [hoten], [gioitinh], [ngaysinh], [diachi]) VALUES (N'GV02      ', N'Đinh Bá Tiến', N'Nam', CAST(N'1980-04-04' AS Date), N'1106 Võ Văn Kiệt, Phường 6, Quận 5, TP.HCM')
INSERT [dbo].[GIAOVIEN] ([magv], [hoten], [gioitinh], [ngaysinh], [diachi]) VALUES (N'GV03      ', N'Lê Hà Minh', N'Nam', CAST(N'1990-02-03' AS Date), N'Đường Nguyễn Huệ, Quận 1, TP.HCM')
INSERT [dbo].[GIAOVIEN] ([magv], [hoten], [gioitinh], [ngaysinh], [diachi]) VALUES (N'GV04      ', N'Nguyễn Cao Đẳng', N'Nam', CAST(N'1991-06-19' AS Date), N'Bùi Viện, Phạm Ngũ Lão, Đề Thám, Quận 1, TP.HCM')
INSERT [dbo].[GIAOVIEN] ([magv], [hoten], [gioitinh], [ngaysinh], [diachi]) VALUES (N'GV05      ', N'Chung Thùy Linh', N'Nữ ', CAST(N'1992-09-17' AS Date), N'Quận Bình Tân, TP.HCM')
GO
INSERT [dbo].[HOCSINH] ([mahs], [hoten], [gioitinh], [ngaysinh], [diachi], [malop]) VALUES (N'HS01      ', N'Nguyễn Huy Hoàng', N'Nữ ', CAST(N'2003-03-04' AS Date), N'Công xã Paris, Quận 1, TP.HCM', N'L01       ')
INSERT [dbo].[HOCSINH] ([mahs], [hoten], [gioitinh], [ngaysinh], [diachi], [malop]) VALUES (N'HS02      ', N'Nguyễn Ngọc Như Huyền', N'Nữ ', CAST(N'2003-06-18' AS Date), N'Số 7, công trường Lam Sơn, Bến Nghé, Quận 1', N'L02       ')
INSERT [dbo].[HOCSINH] ([mahs], [hoten], [gioitinh], [ngaysinh], [diachi], [malop]) VALUES (N'HS03      ', N'Trần Nam Phương', N'Nam', CAST(N'2003-02-01' AS Date), N'Vinhomes Central Park, Phường 22, Bình Thạnh', N'L03       ')
INSERT [dbo].[HOCSINH] ([mahs], [hoten], [gioitinh], [ngaysinh], [diachi], [malop]) VALUES (N'HS04      ', N'Vi Lý Duy Trường', N'Nam', CAST(N'2003-05-24' AS Date), N'120 Xa lộ Hà Nội, Phường Tân Phú, Quận 9, TP.HCM', N'L04       ')
INSERT [dbo].[HOCSINH] ([mahs], [hoten], [gioitinh], [ngaysinh], [diachi], [malop]) VALUES (N'HS05      ', N'Vương Huỳnh Khải', N'Nam', CAST(N'2003-08-16' AS Date), N'208 Nguyễn Hữu Cảnh, phường 22, Quận Bình Thạnh', N'L05       ')
GO
INSERT [dbo].[LOPHOC] ([malop], [tenlop], [nam], [gvcn], [loptruong]) VALUES (N'L01       ', N'21CTT1', N'2021', N'GV01      ', N'HS01      ')
INSERT [dbo].[LOPHOC] ([malop], [tenlop], [nam], [gvcn], [loptruong]) VALUES (N'L02       ', N'21CTT2', N'2021', N'GV02      ', N'HS02      ')
INSERT [dbo].[LOPHOC] ([malop], [tenlop], [nam], [gvcn], [loptruong]) VALUES (N'L03       ', N'21CTT3', N'2021', N'GV03      ', N'HS03      ')
INSERT [dbo].[LOPHOC] ([malop], [tenlop], [nam], [gvcn], [loptruong]) VALUES (N'L04       ', N'21CTT4', N'2021', N'GV04      ', N'HS04      ')
INSERT [dbo].[LOPHOC] ([malop], [tenlop], [nam], [gvcn], [loptruong]) VALUES (N'L05       ', N'21CTT5', N'2021', N'GV05      ', N'HS05      ')
GO