#include<iostream>
#include<string.h>
#include<fstream>
#include "Struct.cpp";

void init(List &l)
{
    l.Head = l.Tail = NULL;
}

Node* createNode(SinhVien data)
{
    Node *node = new Node();
    node->data = data;
    node->next = NULL;
    return node;
}

void Them_SV(List &l, Node *node)
{
    if(l.Head == NULL)
    {
        l.Head = node; 
        l.Tail = node;
    }
    else
    {
        l.Tail->next = node;
        l.Tail = node;
    }
}

// Ham nhap thong tin sinh vien
void Nhap_SV(SinhVien& SV)
{
    std::cout << "Nhap ma so: ";
    std::cin >> SV.maso;
    std::cin.ignore();
    std::cout << "Nhap ho ten: ";
    std::cin.getline(SV.hoten, 30);
    std::cout << "Nhap gioi tinh (1-Nam, 0-Nu): ";
    std::cin >> SV.gioitinh;
    std::cout << "Nhap ngay sinh: ";
    std::cin >> SV.ngaysinh.ng;
    std::cout << "Nhap thang sinh: ";
    std::cin >> SV.ngaysinh.th;
    std::cout << "Nhap nam sinh: ";
    std::cin >> SV.ngaysinh.nam;
    std::cout << "Nhap diem: ";
    std::cin >> SV.diem;
    std::cout << std::endl;
}

// Ham  xuat danh sach SV
void Xuat_SV(SinhVien SV)
{
    std::cout << "ID: " << SV.maso << std::endl;
    std::cout << "Ho ten: " << SV.hoten << std::endl;
    if(SV.gioitinh == true)
        std::cout << "Gioi tinh: Nam" << std::endl;
    else
        std::cout << "Gioi tinh: Nu" << std::endl;
    std::cout << "Ngay sinh: " << SV.ngaysinh.ng << "/" << SV.ngaysinh.th << "/" << SV.ngaysinh.nam << std::endl;
    std::cout << "Diem: " << SV.diem << std::endl;
}

void Nhap_DSSV(List &l, int &n)
{
    std::cout << "Nhap so luong sinh vien: ";
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::cout << "\nNhap thong tin sinh vien thu " << i + 1 << ": " << std::endl;
        SinhVien data;
        Nhap_SV(data);
        Node *node = createNode(data);
        Them_SV(l, node);
    }
}

void Xuat_DS_SV(List l)
{
    Node *node_cur = l.Head;
    while(node_cur != NULL)
    {
        Xuat_SV(node_cur->data);
        std::cout << std::endl;
        node_cur = node_cur->next;
    }
}



int Ghi_file(char *filename, List l)
{
    std::ofstream fout(filename);
    if(!fout) return 0;
    Node *node_cur = l.Head;
    int so_luong_SV = 0;
    while (node_cur != NULL)
    {
        so_luong_SV++;
        node_cur = node_cur->next;
    }
    fout.write((char*)&so_luong_SV, 4);
    node_cur = l.Head;
    while(node_cur != NULL)
    {
        fout.write((char*)&node_cur->data, sizeof(node_cur->data));
        node_cur = node_cur->next;
    }
    fout.close();
    return 1;
}

int Doc_file(char* filename, List &l)
{   
    std::ifstream fin(filename, std::ios::in);
    if(!fin) return 0;
    int so_luong_SV = 0;
    fin.read((char*)&so_luong_SV, 4);
    for(int i = 0; i < so_luong_SV; i++)
    {
        SinhVien data;
        Node *node = createNode(data);
        Them_SV(l, node);
    }
    Node *node_cur = l.Head;
    while(node_cur != NULL)
    {
        fin.read((char*)&node_cur->data, sizeof(node_cur->data));
        node_cur = node_cur->next;
    }
    fin.close();
    return 1;
}

void Sap_xep_DSSV(List &l)
{
    SinhVien data_temp;         // sinh vien tam
    Node *node_curr = l.Head;   // node hien tai dang tro toi
    bool increasing = false;    // kiem tra ma so trong danh sach da tang dan chua
    while(node_curr->next != NULL && increasing == false)
    {
        increasing = true;
        if(strcmp(node_curr->data.maso, node_curr->next->data.maso) == 1)
        {
            data_temp = node_curr->data;
            node_curr->data = node_curr->next->data;
            node_curr->next->data = data_temp;
            increasing = false;
        }
        node_curr = node_curr->next;
        if(node_curr->next == NULL && increasing == false)
        {
            node_curr = l.Head;
        }
    }
}   

List SV_duoi5(List l)
{
    List SVduoi5;
    init(SVduoi5);
    Node *node_curr = l.Head;
    while(node_curr != NULL)
    {
        if(node_curr->data.diem < 5)
        {
            Them_SV(SVduoi5, node_curr);
        }
        node_curr = node_curr->next;
    }
    SVduoi5.Tail->next = NULL;
    return SVduoi5;
}

int Ghi_file_SV_duoi5(char *filename, List l)
{
    List duoi5 = SV_duoi5(l);
    if(duoi5.Head == NULL)
        return 0;
    std::ofstream fout(filename);
    Node *node_cur = duoi5.Head;
    fout << "DANH SACH SINH VIEN DIEM TB DUOI 5" << std::endl;
    while (node_cur != NULL)
    {   
        fout << "ID       : " << node_cur->data.maso << std::endl;
        fout << "Ho ten   : " << node_cur->data.hoten << std::endl;
        fout << "Gioi tinh: "; node_cur->data.gioitinh == true ? fout << "Nam" << std::endl : fout << "Nu" << std::endl;
        fout << "Ngay sinh: " << node_cur->data.ngaysinh.ng << "/" << node_cur->data.ngaysinh.th << "/" << node_cur->data.ngaysinh.nam << std::endl;
        fout << "Diem     : " << node_cur->data.diem << std::endl;
        fout << "\n";
        node_cur = node_cur->next;
    }
    
    fout.close();
    return 1;
}

int Xoa_SV(List &l, char maso[9])
{
    Node *node_temp;
    Node *node_curr = l.Head;
    if(strcmp(l.Head->data.maso, maso) == 0)
    {
        Node *node_tam = l.Head;
        l.Head = l.Head->next;
        delete[] node_tam;
        return 1;
    }
    while (node_curr != NULL)
    {
        if(strcmp(node_curr->data.maso, maso) == 0)
        {
            Node *node_tam ;
            node_tam->data = node_curr->data;
            node_curr->data = node_curr->next->data;
            node_curr->next->data = node_tam->data;
            node_tam = node_curr->next;
            node_curr->next = node_tam->next;
            delete[] node_tam;
        }
        node_curr = node_curr->next;
    }
    return 0;
}