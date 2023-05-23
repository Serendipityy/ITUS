#include<iostream>
#include<fstream>
#include<string.h>
#include"Function.h"


int main()
{
    List DS_SV;     // danh sach sv ban dau
    List DS_File;   // danh sach sv doc tu file
    List DS_SVduoi5;
    init(DS_SVduoi5);
    init(DS_File);
    init(DS_SV);
    int n = 0;
    int lc = -1;
    std::cout << "NHAP DANH SACH SINH VIEN" << std::endl;
    Nhap_DSSV(DS_SV, n);
    while (lc != 0)
    {
        std::cout << "\n----------MENU----------";
        std::cout << "\n1. Them sinh vien.";
        std::cout << "\n2. Ghi danh sach sinh vien vao tep tin output.txt.";
        std::cout << "\n3. Doc danh sach sinh vien tu tep tin input.txt.";
        std::cout << "\n4. Sap xep danh sach sinh vien theo ma so sinh vien.";
        std::cout << "\n5. Tim va xuat danh sach sinh vien ra tep tin Sinh_vien_duoi5.txt.";
        std::cout << "\n6. Xoa sinh vien co ma so da cho. ";
        std::cout << "\n7. Xuat danh sach sinh vien. ";
        std::cout << "\n0. Thoat." << std::endl;
        std::cin >> lc;
        switch (lc)
        {
            case 1:
            {
                SinhVien data;
                Nhap_SV(data);
                Node *node = createNode(data);
                Them_SV(DS_SV, node);
                break;
            }
            //case 2:
            //{
            //    int n = Ghi_file("output.txt", DS_SV);
            //    if(n == 1)
            //        std::cout << "\nGhi file thanh cong.";
            //    else
            //        std::cout << "\nGhi file that bai.";
            //        break;
            //}
            case 3:
            {
                int n = Doc_file("input.txt", DS_File);
                if(n == 1)
                    std::cout << "\nDoc file thanh cong.";
                else
                    std::cout << "\nDoc file that bai.";
                    break;
            }
            case 4:
            {
                int n = 0;
                std::cout << "\n1. Sap xep danh sach ban dau.";
                std::cout << "\n2. Sap xep danh sach doc duoc tu file.";
                std::cout << "\n3. Sap xep danh sach SV duoi 5." << std::endl;
                std::cin >> n;
                if(n == 1)
                    Sap_xep_DSSV(DS_SV);
                if(n == 2)
                    Sap_xep_DSSV(DS_File);
                if(n == 3)
                    Sap_xep_DSSV(DS_SVduoi5);
                std::cout << "\nDa tien danh sap xep.";
                break;
            }
          /*  case 5:
            {
                DS_SVduoi5 = SV_duoi5(DS_SV);
                int n = Ghi_file_SV_duoi5("Sinh_vien_duoi5.txt", DS_SVduoi5);
                if(n == 0)
                    std::cout << "\nGhi vao file that bai.";
                else
                    std::cout << "\nDa ghi danh sach sinh vien duoi 5 vao file Sinh_vien_duoi5.txt";
                break;
            }*/
            case 6:
            {
                int n = 0;
                char maso[9];
                std::cout << "\nNhap ma so sinh vien can xoa: ";
                std::cin.ignore();
                std::cin.getline(maso, 9);
                n = Xoa_SV(DS_SV, maso);
                if(n == 0)
                    std::cout << "\nXoa that bai.";
                else
                    std::cout << "\nXoa thanh cong.";
                break;
            }
            case 7:
            {
                int n = 0;
                std::cout << "\n1. Xuat danh sach ban dau.";
                std::cout << "\n2. Xuat danh sach doc duoc tu file.";
                std::cout << "\n3. Xuat danh sach SV duoi 5." << std::endl;
                std::cin >> n;
                if(n == 1)
                    Xuat_DS_SV(DS_SV);
                if(n == 2)
                    Xuat_DS_SV(DS_File);
                if(n == 3)
                    Xuat_DS_SV(DS_SVduoi5);
            }
            case 0:
                break;
        }

    }
    

}