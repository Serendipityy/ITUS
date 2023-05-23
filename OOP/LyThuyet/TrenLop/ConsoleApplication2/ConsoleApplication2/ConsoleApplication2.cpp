#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MachinePart {
private:
    string code;
    double price;
    int quantity;
    vector<MachinePart> subparts; // danh sách các chi tiết con 
                                  //(nếu là chi tiết phức)

public:
    string getCode() const {
        return code; 
    }
    MachinePart(string code, double price, int quantity = 1)
        : code(code), price(price), quantity(quantity) {}

    void addSubpart(MachinePart subpart) {
        subparts.push_back(subpart);
    }

    double getTotalPrice() const {
        double total = price * quantity;
        for (const auto& subpart : subparts) {
            total += subpart.getTotalPrice();
        }
        return total;
    }

    void printDetails(int indentLevel = 0) const {
        for (int i = 0; i < indentLevel; i++) {
            cout << "  ";
        }
        cout << "- " << code << " x" << quantity << " ($" << price << ")" << endl;
        for (const auto& subpart : subparts) {
            subpart.printDetails(indentLevel + 1);
        }
    }

    const MachinePart* findPart(string code) const {
        if (this->code == code) {
            return this;
        }
        for (const auto& subpart : subparts) {
            const MachinePart* found = subpart.findPart(code);
            if (found != nullptr) {
                return found;
            }
        }
        return nullptr;
    }

    int countSimpleParts() const {
        int count = subparts.empty() ? 1 : 0; // nếu là chi tiết đơn thì count = 1,
                                              // nếu là chi tiết phức thì count = 0
        for (const auto& subpart : subparts) {
            count += subpart.countSimpleParts();
        }
        return count;
    }
};

int main() {
    // Tạo một chi tiết máy phức
    MachinePart machine("MACHINE", 100);

    // Thêm các chi tiết con vào chi tiết máy phức
    MachinePart part1("PART1", 20, 3);
    MachinePart part2("PART2", 30, 2);
    MachinePart part3("PART3", 50);
    MachinePart part4("PART4", 10, 4);
    part1.addSubpart(part3);
    machine.addSubpart(part1);
    machine.addSubpart(part2);
    machine.addSubpart(part4);

    // Tính tiền của máy và xuất chi tiết của máy
    double total = machine.getTotalPrice() * 2.0;
    cout << "Total price: $" << total << endl;
    cout << "Machine details:" << endl;
    machine.printDetails();

    // Tìm kiếm chi tiết có mã số tương ứng
    const MachinePart* foundPart = machine.findPart("PART3");
    if (foundPart != nullptr) {
        cout << "Found part: " << foundPart->getCode() << endl;
    }
    else {
        cout << "Part not found" << endl;
    }

    // Đếm số lượng chi tiết đơn
    int simplePartCount = machine.countSimpleParts();
    cout << "Number of simple parts: " << simplePartCount << endl;

    return 0;

}