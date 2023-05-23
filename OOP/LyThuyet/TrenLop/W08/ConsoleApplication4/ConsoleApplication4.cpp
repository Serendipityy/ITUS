#include <iostream>
#include <string>
using namespace std;

class Gate {
public:
    virtual bool enter(int& money, int& iq, int& strength) = 0;
};

class BusinessGate : public Gate {
private:
    int price; // don gia hang hoa
    int stock; // so luong hang hoa con lai
public:
    BusinessGate(int p, int s) : price(p), stock(s) {}
    bool enter(int& money, int& iq, int& strength) {
        if (money >= price && stock > 0) {
            money -= price;
            stock--;
            return true;
        }
        else {
            return false;
        }
    }
};

class AcademicGate : public Gate {
private:
    int iq; // chi so tri tue cua nha hien triet
public:
    AcademicGate(int i) : iq(i) {}
    bool enter(int& money, int& iq, int& strength) {
        if (iq >= this->iq) {
            return true;
        }
        else {
            return false;
        }
    }
};

class PowerGate : public Gate {
private:
    int strength; // chi so suc manh cua dung sy
public:
    PowerGate(int s) : strength(s) {}
    bool enter(int& money, int& iq, int& strength) {
        if (strength >= this->strength) {
            strength -= this->strength;
            return true;
        }
        else {
            return false;
        }
    }
};

class Castle {
private:
    Gate** gates; // mang cac con tro toi cac cua
    int numGates; // so luong cua trong castle
public:
    Castle(int numGates) {
        this->numGates = numGates;
        gates = new Gate * [numGates];
    }
    ~Castle() {
        for (int i = 0; i < numGates; i++) {
            delete gates[i];
        }
        delete[] gates;
    }
    void addGate(int index, Gate* gate) {
        gates[index] = gate;
    }
    bool enterCastle(int& money, int& iq, int& strength) {
        for (int i = 0; i < numGates; i++) {
            if (!gates[i]->enter(money, iq, strength)) {
                return false;
            }
        }
        return true;
    }

    bool rescuePrincess(int& money, int& iq, int& strength) {
        bool canRescue = enterCastle(money, iq, strength);
        if (canRescue) {
            // kiểm tra xem các thông số đã được cập nhật hay chưa
            if (money == 0 || iq == 0 || strength == 0) {
                return false;
            }
            else {
                return true;
            }
        }
        else {
            return false;
        }
    }

};

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
            cout << "Nhap chi so tri tue cua ban: ";
            cin >> iq;
            
            castle.addGate(i, new AcademicGate(iq));
            break;
        }
        case 3: {
            int strength;
            cout << "Nhap chi so suc manh cua ban: ";
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
        cout << "Hoang tu khong the cuu cong chua. Roi cuoc.\n";
    }

    return 0;
}