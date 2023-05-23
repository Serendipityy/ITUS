#include "HandleGame.h"

int main() {
    int numGates;
    cout << "Nhap so luong cua trong castle: ";
    cin >> numGates;

    Castle castle(numGates);

    // them cac cua vao castle
    for (int i = 0; i < numGates; i++) {
        int gateType;
        cout << "Nhap loai cua thu " << i + 1 << ": ";
        cin >> gateType;
        switch (gateType) {
        case 1: {
            double price;
            int numItems;
            cout << "Nhap don gia: ";
            cin >> price;
            cout << "Nhap so luong mat hang: ";
            cin >> numItems;
            castle.addGate(i, new BusinessGate(price, numItems));
            break;
        }
        case 2: {
            int iq;
            cout << "Nhap chi so tri tue cua cau hoi: ";
            cin >> iq;

            castle.addGate(i, new AcademicGate(iq));
            break;
        }
        case 3: {
            int strength;
            cout << "Nhap chi so suc manh: ";
            cin >> strength;
            castle.addGate(i, new PowerGate(strength));
            break;
        }
        default:
            cout << "Loai cua khong hop le, vui long nhap lai.\n";
            i--; // nhap lai cua nay
            break;
        }
    }
    // nhap thong so ban dau cua hoang tu
    int initialMoney;
    int initialIQ, initialStrength;
    cout << "Nhap so tien ban dau cua hoang tu: ";
    cin >> initialMoney;
    cout << "Nhap chi so tri tue ban dau cua hoang tu: ";
    cin >> initialIQ;
    cout << "Nhap chi so suc manh ban dau cua hoang tu: ";
    cin >> initialStrength;

    // kiem tra xem co the cuu cong chua khong
    if (castle.rescuePrincess(initialMoney, initialIQ, initialStrength)) {
        cout << "Hoang tu co the cuu cong chua!\n";
        // in ra thong so con lai cua hoang tu
        cout << "So tien con lai cua hoang tu: " << initialMoney << endl;
        cout << "Chi so tri tue con lai cua hoang tu: " << initialIQ << endl;
        cout << "Chi so suc manh con lai cua hoang tu: " << initialStrength << endl;
    }
    else {
        cout << "Hoang tu khong the cuu cong chua. Thua cuoc.\n";
    }

    return 0;
}