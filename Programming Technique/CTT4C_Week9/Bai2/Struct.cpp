struct Ngay
{
    int ng, th, nam;
};

struct SinhVien
{
    char maso[9] = {'\0'};
    char hoten[30] = {'\0'};
    bool gioitinh = true;
    Ngay ngaysinh;
    float diem;
};

struct Node
{
    SinhVien data;
    Node *next;
};

struct List
{
    Node *Head;
    Node *Tail;
};
