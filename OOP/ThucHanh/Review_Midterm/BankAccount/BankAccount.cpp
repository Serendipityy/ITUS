#include <iostream>
#include <iomanip>
#include <string>
#include<sstream>
using namespace std;

class Account {
private:
    long accountNumber;
    string accountName;
    double balance;
    const double INTEREST_RATE = 0.035;

public:
    Account() {
        accountNumber = 0;
        accountName = "";
        balance = 0;
    }

    Account(long num, string name, double bal = 50) {
        accountNumber = num;
        accountName = name;
        balance = bal;
    }

    void setAccountNumber(long num) {
        accountNumber = num;
    }

    void setAccountName(string name) {
        accountName = name;
    }

    void setBalance(double bal) {
        balance = bal;
    }

    long getAccountNumber() {
        return accountNumber;
    }

    string getAccountName() {
        return accountName;
    }

    double getBalance() {
        return balance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful." << endl;
        }
        else {
            cout << "Invalid amount. Please try again." << endl;
        }
    }

    void withdraw(double amount) {
        double fee = 0.05 * amount;
        if (amount > 0 && amount + fee <= balance) {
            balance -= amount + fee;
            cout << "Withdrawal successful." << endl;
        }
        else {
            cout << "Invalid amount. Please try again." << endl;
        }
    }

    void addInterest() {
        balance += balance * INTEREST_RATE;
    }

    void transfer(Account& other, double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            other.deposit(amount);
            cout << "Transfer successful." << endl;
        }
        else {
            cout << "Invalid amount. Please try again." << endl;
        }
    }

    string toString() {
        ostringstream output;
        output << fixed << setprecision(2);
        output << "Account number: " << accountNumber << endl;
        output << "Account name: " << accountName << endl;
        output << "Balance: $" << balance << endl;
        return output.str();
    }
};

int main() {
    Account myAccount(123456, "John Doe", 1000);

    // Test deposit method
    myAccount.deposit(500);
    cout << myAccount.toString();

    // Test withdraw method
    myAccount.withdraw(200);
    cout << myAccount.toString();

    // Test addInterest method
    myAccount.addInterest();
    cout << myAccount.toString();

    // Test transfer method
    Account yourAccount(654321, "Jane Smith", 500);
    myAccount.transfer(yourAccount, 300);
    cout << myAccount.toString();
    cout << yourAccount.toString();
    return 0;
}
