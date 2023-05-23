#include "QLThuVien.h"
QLThuVien::QLThuVien() {
	size = 0;
	dsdg = NULL;
}

QLThuVien::QLThuVien(int n) {
	size = n;
	dsdg = new DocGia[n];
	for (int i = 0; i < n; i++) {
		dsdg[i] = DocGia();
	}
}

QLThuVien::~QLThuVien() {
	delete[] dsdg;
	dsdg = NULL;
}

void QLThuVien::NhapDSDG() {
	cout << "Nhap so luong doc gia: ";
	cin >> size;
	dsdg = new DocGia[size];
	for (int i = 0; i < size; i++) {
		cout << "\n\n\tNHAP THONG TIN DOC GIA THU " << i + 1 << endl;
		dsdg[i].Nhap();
	}
}

void QLThuVien::XuatDSDG() {
	for (int i = 0; i < size; i++) {
		cout << "\n\n\tTHONG TIN DOC GIA THU " << i + 1 << endl;
		dsdg[i].Xuat();
	}
}

float QLThuVien::tinhTongTien() {
	float sum = 0;
	for (int i = 0; i < size; i++) {
		sum += dsdg[i].TinhPhi();
	}
	return sum;
}

void QLThuVien::lietKeDocGiaHetHan() {
	string ngayCanKiemTra = "5/5/2023";
	cout << "Danh sach doc gia het han truoc ngay 5/5/2023: " << endl;
	for (int i = 0; i < size; i++) {
		if (dsdg[i].kiemTraHetHan(ngayCanKiemTra)) {
			dsdg[i].Xuat();
		}
	}
}

//void QLThuVien::themDocGia() {
//	DocGia dgMoi;
//	cout << "\nNhap thong tin doc gia can them: ";
//	dgMoi.Nhap();
//
//	// Tìm vị trí thích hợp để chèn đối tượng mới vào danh sách
//	int vitriThem = 0;
//	for (int i = 0; i < size; i++) {
//		if (strcmp(dsdg[i].getMaDG(), dgMoi.getMaDG()) > 0) {
//			vitriThem = i;
//			break;
//		}
//		else {
//			vitriThem = i + 1;
//		}
//	}
//
//	// Dịch chuyển các đối tượng phía sau vị trí chèn sang phải một vị trí
//	for (int i = size; i > vitriThem; i--) {
//		dsdg[i] = dsdg[i - 1];
//	}
//
//	// Chèn đối tượng mới vào vị trí thích hợp
//	dsdg[vitriThem] = dgMoi;
//	size++;
//
//}



//
//void QLThuVien::themDocGia() {
//	// Tạo một độc giả mới
//	DocGia dg;
//	dg.Nhap();
//
//	// Tìm vị trí thích hợp để chèn độc giả mới vào mảng
//	int i = 0;
//	while (i < size && strcmp(dg.getMaDG(), dsdg[i].getMaDG()) > 0) {
//		i++;
//	}
//
//	// Cấp phát một mảng mới với kích thước lớn hơn mảng hiện tại một đơn vị
//	DocGia* newDSDG = new DocGia[size + 1];
//
//	// Sao chép toàn bộ dữ liệu từ mảng hiện tại sang mảng mới
//	for (int j = 0; j < i; j++) {
//		newDSDG[j] = dsdg[j];
//	}
//	newDSDG[i] = dg;
//	for (int j = i + 1; j < size + 1; j++) {
//		newDSDG[j] = dsdg[j - 1];
//	}
//
//	// Giải phóng mảng cũ và trỏ mảng cũ đến mảng mới
//	delete[] dsdg;
//	dsdg = newDSDG;
//	size++;
//}
