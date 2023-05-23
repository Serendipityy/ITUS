#include <iostream>
#include <iomanip>

class Vehicle {
private:
    std::string make;
    std::string model;
    int year;
    double value;
    double engineSize;

public:
    Vehicle(std::string make, std::string model, int year, double value, double engineSize) {
        this->make = make;
        this->model = model;
        this->year = year;
        this->value = value;
        this->engineSize = engineSize;
    }

    double calculateTax() {
        if (engineSize < 100) {
            return value * 0.01;
        }
        else if (engineSize <= 200) {
            return value * 0.03;
        }
        else {
            return value * 0.05;
        }
    }

    std::string getMake() {
        return make;
    }

    std::string getModel() {
        return model;
    }

    int getYear() {
        return year;
    }

    double getValue() {
        return value;
    }

    double getEngineSize() {
        return engineSize;
    }
};

int main() {
    Vehicle xe1("Honda", "Wave Alpha", 2020, 25000000, 97);
    Vehicle xe2("Yamaha", "Exciter 150", 2022, 50000000, 149);
    Vehicle xe3("Kawasaki", "Z1000", 2021, 400000000, 1000);

    int choice;
    do {
        std::cout << std::endl << "Menu:" << std::endl;
        std::cout << "1. Nhap thong tin va tao cac doi tuong xe1, xe2, xe3" << std::endl;
        std::cout << "2. Xuat bang ke khai tien thue truoc ba cua cac xe" << std::endl;
        std::cout << "3. Thoat" << std::endl;
        std::cout << "Nhap lua chon cua ban: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string make, model;
            int year;
            double value, engineSize;

            std::cout << "Nhap thong tin xe 1:" << std::endl;
            std::cout << "Hang san xuat: ";
            std::cin >> make;
            std::cout << "Model: ";
            std::cin >> model;
            std::cout << "Nam san xuat: ";
            std::cin >> year;
            std::cout << "Gia tri: ";
            std::cin >> value;
            std::cout << "Dung tich xi-lanh: ";
            std::cin >> engineSize;
            xe1 = Vehicle(make, model, year, value, engineSize);

            std::cout << "Nhap thong tin xe 2:" << std::endl;
            std::cout << "Hang san xuat: ";
            std::cin >> make;
            std::cout << "Model: ";
            std::cin >> model;
            std::cout << "Nam san xuat: ";
            std::cin >> year;
            std::cout << "Gia tri: ";
            std::cin >> value;
            std::cout << "Dung tich xi-lanh: ";
            std::cin >> engineSize;
            xe2 = Vehicle(make, model, year, value, engineSize);

            std::cout << "Nhap thong tin xe 3:" << std::endl;
            std::cout << "Hang san xuat: ";
            std::cin >> make;
            std::cout << "Model: ";
            std::cin >> model;
            std::cout << "Nam san xuat: ";
            std::cin >> year;
            std::cout << "Gia tri: ";
            std::cin >> value;
            std::cout << "Dung tich xi-lanh: ";
            std::cin >> engineSize;
            xe3 = Vehicle(make, model, year, value, engineSize);
            break;
        }
        case 2: {
            std::cout << std::endl << std::setw(10) << "Hang SX" << std::setw(20) << "Model" << std::setw(10) << "Nam SX" << std::setw(20) << "Gia tri" << std::setw(20) << "Dung tich xi-lanh" << std::setw(20) << "Tien thue truoc ba" << std::endl;
            std::cout << std::setw(10) << xe1.getMake() << std::setw(20) << xe1.getModel() << std::setw(10) << xe1.getYear() << std::setw(20) << xe1.getValue() << std::setw(20) << xe1.getEngineSize() << std::setw(20) << xe1.calculateTax() << std::endl;
            std::cout << std::setw(10) << xe2.getMake() << std::setw(20) << xe2.getModel() << std::setw(10) << xe2.getYear() << std::setw(20) << xe2.getValue() << std::setw(20) << xe2.getEngineSize() << std::setw(20) << xe2.calculateTax() << std::endl;
            std::cout << std::setw(10) << xe3.getMake() << std::setw(20) << xe3.getModel() << std::setw(10) << xe3.getYear() << std::setw(20) << xe3.getValue() << std::setw(20) << xe3.getEngineSize() << std::setw(20) << xe3.calculateTax() << std::endl;
            break;
        }

        case 3: {
            std::cout << "Thoat chuong trinh." << std::endl;
            break;
        }

        default: {
            std::cout << "Lua chon khong hop le. Vui long chon lai." << std::endl;
            break;
        }
        }
    } while (choice != 3);

    return 0;
}
