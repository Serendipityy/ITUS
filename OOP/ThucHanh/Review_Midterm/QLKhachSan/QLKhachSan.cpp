#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

// Khai báo lớp cha
class HoaDon {
protected:
    string maHoaDon;
    int ngay, thang, nam;
    string tenKhachHang;
    string maPhong;
    float donGia;
public:
    // Hàm tạo
    HoaDon() {
        maHoaDon = "";
        ngay = thang = nam = 0;
        tenKhachHang = "";
        maPhong = "";
        donGia = 0.0;
    }
    HoaDon(string ma, int ng, int th, int nm, string ten, string maP, float gia) {
        maHoaDon = ma;
        ngay = ng;
        thang = th;
        nam = nm;
        tenKhachHang = ten;
        maPhong = maP;
        donGia = gia;
    }

    // Hàm tính thành tiền (virtual)
    virtual float tinhThanhTien() = 0;

    virtual void nhapThongTin() {
        cout << "Nhap ma hoa don: ";
        cin.ignore();
        getline(cin, maHoaDon);
        cout << "Nhap ngay thang nam: ";
        cin >> ngay >> thang >> nam;
        cout << "Nhap ten khach hang: "; 
        cin.ignore(); 
        getline(cin, tenKhachHang);
        cout << "Nhap ma phong: "; 
        getline(cin, maPhong);
        cout << "Nhap don gia: "; 
        cin >> donGia;
    }

    // Hàm xuất thông tin hóa đơn
    virtual void xuatThongTin() {
        cout << "Ma hoa don: " << maHoaDon << endl;
        cout << "Ngay hoa don: " << ngay << "/" << thang << "/" << nam << endl;
        cout << "Ten khach hang: " << tenKhachHang << endl;
        cout << "Ma phong: " << maPhong << endl;
        cout << "Don gia: " << donGia << endl;
    }
    int getThang() { return thang; }
    int getNam() { return nam; }
};

// Khai báo lớp con HoaDonTheoGio kế thừa từ lớp cha HoaDon
class HoaDonTheoGio : public HoaDon {
private:
    int soGio;
public:
    HoaDonTheoGio() : HoaDon() {
        soGio = 0;
    }
    // Hàm tạo
    HoaDonTheoGio(string ma, int ng, int th, int nm, string ten, string maP, float gia, int gio) : HoaDon(ma, ng, th, nm, ten, maP, gia) {
        soGio = gio;
    }

    // Hàm tính thành tiền
    float tinhThanhTien() {
        if (soGio > 30) {
            return 0;
        }
        else if (soGio > 24) {
            return 24 * donGia;
        }
        else {
            return soGio * donGia;
        }
    }

    void nhapThongTin() {
        HoaDon::nhapThongTin();
        cout << "Nhap so gio thue: ";
        cin >> soGio;
    }

    // Hàm xuất thông tin hóa đơn
    void xuatThongTin() {
        HoaDon::xuatThongTin();
        cout << "So gio thue: " << soGio << endl;
        cout << "Thanh tien: " << tinhThanhTien() << endl;
    }
};

// Khai báo lớp con HoaDonTheoNgay kế thừa từ lớp cha HoaDon
class HoaDonTheoNgay : public HoaDon {
private:
    int soNgay;
public:
    // Hàm tạo
    HoaDonTheoNgay() : HoaDon() {
        soNgay = 0;
    }
    HoaDonTheoNgay(string ma, int ng, int th, int nm, string ten, string maP, float gia, int ngayThue) : HoaDon(ma, ng, th, nm, ten, maP, gia) {
        soNgay = ngayThue;
    }

    // Hàm tính thành tiền
    float tinhThanhTien() {
        if (soNgay > 7) {
            return (soNgay * donGia) - ((soNgay - 7) * donGia * 0.2);
        }
        else {
            return soNgay * donGia;
        }
    }
    void nhapThongTin() {
        HoaDon::nhapThongTin();
        cout << "Nhap so ngay thue: ";
        cin >> soNgay;
    }

    // Hàm xuất thông tin hóa đơn
    void xuatThongTin() {
        HoaDon::xuatThongTin();
        cout << "So ngay thue: " << soNgay << endl;
        cout << "Thanh tien: " << tinhThanhTien() << endl;
    }
};

class QLHoaDon {
private:
    vector<HoaDon*> dsHoaDon;
public:
    void nhapDS() {
        int n;
        cout << "Nhap so luong hoa don: ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            cout << "\n\n\t NHAP THONG TIN HOA DON THU " << i + 1 << endl;
            cout << "Nhap loai hoa don (1: theo gio, 2: theo ngay): ";
            int choice;
            cin >> choice;
            if (choice == 1) {
                HoaDon* hd = new HoaDonTheoGio;
                hd->nhapThongTin();
                dsHoaDon.push_back(hd);

            }
            else if (choice == 2) {
                HoaDon* hd = new HoaDonTheoNgay;
                hd->nhapThongTin();
                dsHoaDon.push_back(hd);
            }
            else {
                cout << "Lua chon khong hop le!";
                i--;
            }
        }
    }
    void xuatDS() {
        cout << endl << "Danh sach hoa don: " << endl;

        for (int i = 0; i < dsHoaDon.size(); i++) {
            dsHoaDon[i]->xuatThongTin();
            cout << endl;
        }
    }
    void tongSoLuong() {
        int soLuongTheoGio = 0, soLuongTheoNgay = 0;
        for (int i = 0; i < dsHoaDon.size(); i++) {
            if (dynamic_cast<HoaDonTheoGio*>(dsHoaDon[i]) != NULL) {
                soLuongTheoGio++;
            }
            else if (dynamic_cast<HoaDonTheoNgay*>(dsHoaDon[i]) != NULL) {
                soLuongTheoNgay++;
            }
        }
        cout << "Tong so luong theo gio: " << soLuongTheoGio << endl;
        cout << "Tong so luong theo ngay: " << soLuongTheoNgay << endl;
    }

    void tongTBThanhTienT9() {
        // Tính trung bình thành tiền của hóa đơn thuê phòng trong tháng 9/2013
        float tongThanhTien = 0;
        int soLuongHoaDon = 0;
        for (int i = 0; i < dsHoaDon.size(); i++) {
            if (dsHoaDon[i]->getThang() == 9 && dsHoaDon[i]->getNam() == 2013) {
                tongThanhTien += dsHoaDon[i]->tinhThanhTien();
                soLuongHoaDon++;
            }
        }
        if (soLuongHoaDon > 0) {
            float trungBinhThanhTien = tongThanhTien / soLuongHoaDon;
            cout << "Trung binh thanh tien cua hoa don thue phong trong thang 9/2013 la: " << fixed << setprecision(2) << trungBinhThanhTien << endl;
        }
        else {
            cout << "Khong co hoa don thue phong nao trong thang 9/2013" << endl;
        }
    }
};

int main() {
    QLHoaDon ds;
    ds.nhapDS();
    ds.xuatDS();
    ds.tongSoLuong();
    ds.tongTBThanhTienT9();
    return 0;
}
