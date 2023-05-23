USE [QLLopHoc]
GO
/****** Object:  Table [dbo].[GIAOVIEN]    Script Date: 3/10/2023 2:57:23 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[GIAOVIEN](
	[magv] [char](10) NOT NULL,
	[hoten] [nvarchar](50) NULL,
	[gioitinh] [nchar](3) NULL,
	[ngaysinh] [date] NULL,
	[diachi] [nvarchar](100) NULL,
 CONSTRAINT [PK_GIAOVIEN] PRIMARY KEY CLUSTERED 
(
	[magv] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[HOCSINH]    Script Date: 3/10/2023 2:57:23 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[HOCSINH](
	[mahs] [char](10) NOT NULL,
	[hoten] [nvarchar](50) NULL,
	[gioitinh] [nchar](3) NULL,
	[ngaysinh] [date] NULL,
	[diachi] [nvarchar](100) NULL,
	[malop] [char](10) NULL,
 CONSTRAINT [PK_HOCSINH] PRIMARY KEY CLUSTERED 
(
	[mahs] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[LOPHOC]    Script Date: 3/10/2023 2:57:23 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[LOPHOC](
	[malop] [char](10) NOT NULL,
	[tenlop] [nvarchar](50) NULL,
	[nam] [nchar](4) NULL,
	[gvcn] [char](10) NULL,
	[loptruong] [char](10) NULL,
 CONSTRAINT [PK_LOPHOC] PRIMARY KEY CLUSTERED 
(
	[malop] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
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
ALTER TABLE [dbo].[HOCSINH]  WITH CHECK ADD  CONSTRAINT [FK_HOCSINH_LOPHOC] FOREIGN KEY([malop])
REFERENCES [dbo].[LOPHOC] ([malop])
GO
ALTER TABLE [dbo].[HOCSINH] CHECK CONSTRAINT [FK_HOCSINH_LOPHOC]
GO
ALTER TABLE [dbo].[LOPHOC]  WITH CHECK ADD  CONSTRAINT [FK_LOPHOC_GIAOVIEN] FOREIGN KEY([gvcn])
REFERENCES [dbo].[GIAOVIEN] ([magv])
GO
ALTER TABLE [dbo].[LOPHOC] CHECK CONSTRAINT [FK_LOPHOC_GIAOVIEN]
GO
ALTER TABLE [dbo].[LOPHOC]  WITH CHECK ADD  CONSTRAINT [FK_LOPHOC_HOCSINH] FOREIGN KEY([loptruong])
REFERENCES [dbo].[HOCSINH] ([mahs])
GO
ALTER TABLE [dbo].[LOPHOC] CHECK CONSTRAINT [FK_LOPHOC_HOCSINH]
GO
