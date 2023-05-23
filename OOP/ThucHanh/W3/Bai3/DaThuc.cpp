#include "DaThuc.h"

DaThuc::DaThuc() {
    num_of_monomials = 0;
    list_of_monomials = NULL;
}

void DaThuc::nhap() {
    cout << "Nhap so luong don thuc: "; cin >> num_of_monomials;
    list_of_monomials = new DonThuc[num_of_monomials];
    for (int i = 0; i < num_of_monomials; i++) {
        cout << "Nhap don thuc " << i + 1 << endl;
        list_of_monomials[i].nhap();
    }
}
void DaThuc::xuat() {
    for (int i = 0; i < num_of_monomials; i++) {
        if (i == 0) list_of_monomials[i].xuat();
        else {
            if (list_of_monomials[i].tinhGiaTri(1) >= 0) cout << "+";
            list_of_monomials[i].xuat();
        }
    }
}
float DaThuc::tinhGiaTri(float x) {
    float result = 0;
    for (int i = 0; i < num_of_monomials; i++) {
        result += list_of_monomials[i].tinhGiaTri(x);
    }
    return result;
}

DaThuc DaThuc::operator + (const DaThuc& p2) {
    DaThuc p;
    int i = 0, j = 0, k = 0;
    p.num_of_monomials = 0;
    p.list_of_monomials = new DonThuc[num_of_monomials + p2.num_of_monomials];
    while (i < this->num_of_monomials && j < p2.num_of_monomials) {
        if (this->list_of_monomials[i].getDegree() == p2.list_of_monomials[j].getDegree()) {
            p.list_of_monomials[k++] = this->list_of_monomials[i++] + p2.list_of_monomials[j++];
        }
        else if (this->list_of_monomials[i].getDegree() > p2.list_of_monomials[j].getDegree()) {
            p.list_of_monomials[k++] = this->list_of_monomials[i++];
        }
        else {
            p.list_of_monomials[k++] = p2.list_of_monomials[j++];
        }
        p.num_of_monomials++;
    }
    while (i < this->num_of_monomials) {
        p.list_of_monomials[k++] = this->list_of_monomials[i++];
        p.num_of_monomials++;
    }
    while (j < p2.num_of_monomials) {
        p.list_of_monomials[k++] = p2.list_of_monomials[j++];
        p.num_of_monomials++;
    }
    return p;
}
DaThuc DaThuc::operator - (const DaThuc& p2) {
    DaThuc p;
    int i = 0, j = 0, k = 0;
    p.num_of_monomials = 0;
    p.list_of_monomials = new DonThuc[num_of_monomials + p2.num_of_monomials];
    while (i < this->num_of_monomials && j < p2.num_of_monomials) {
        if (this->list_of_monomials[i].getDegree() == p2.list_of_monomials[j].getDegree()) {
            p.list_of_monomials[k++] = this->list_of_monomials[i++] - p2.list_of_monomials[j++];
        }
        else if (this->list_of_monomials[i].getDegree() > p2.list_of_monomials[j].getDegree()) {
            p.list_of_monomials[k++] = this->list_of_monomials[i++];
        }
        else {
            p.list_of_monomials[k++] = -p2.list_of_monomials[j++];
        }
        p.num_of_monomials++;
    }
    while (i < this->num_of_monomials) {
        p.list_of_monomials[k++] = this->list_of_monomials[i++];
        p.num_of_monomials++;
    }
    while (j < p2.num_of_monomials) {
        p.list_of_monomials[k++] = -p2.list_of_monomials[j++];
        p.num_of_monomials++;
    }
    return p;
}

DaThuc DaThuc::operator * (const DaThuc& p2) {
    DaThuc p;
    p.num_of_monomials = this->num_of_monomials * p2.num_of_monomials;
    p.list_of_monomials = new DonThuc[p.num_of_monomials];
    int k = 0;
    for (int i = 0; i < this->num_of_monomials; i++) {
        for (int j = 0; j < p2.num_of_monomials; j++) {
            p.list_of_monomials[k++] = this->list_of_monomials[i] * p2.list_of_monomials[j];
        }
    }
    return p;
}

DaThuc DaThuc::operator / (const DaThuc& p2) {
    DaThuc p;
    DaThuc r = *this;
    int n = r.num_of_monomials;
    int m = p2.num_of_monomials;
    p.num_of_monomials = 0;
    p.list_of_monomials = new DonThuc[n];

    for (int i = n - m; i >= 0; i--) {
        DonThuc q = r.list_of_monomials[i + m - 1] / p2.list_of_monomials[m - 1];
        p.list_of_monomials[i] = q;
        for (int j = 0; j < m; j++) {
            r.list_of_monomials[i + j] = r.list_of_monomials[i + j] - q * p2.list_of_monomials[j];
        }
    }
    p.num_of_monomials = n - m + 1;
    return p;
}