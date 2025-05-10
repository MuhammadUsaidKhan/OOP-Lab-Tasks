#include <iostream>
#include <exception>
#include <string>
#include <iomanip>

using namespace std;

class InsufficientFundsException : public exception {
    double deficit;
    string currencySymbol;
public:
    InsufficientFundsException(double def, const string& symbol = "$") 
        : deficit(def), currencySymbol(symbol) {}
        
    const char* what() const noexcept override {
        static string msg;
        msg = "InsufficientFundsException - Deficit: " + currencySymbol + 
              to_string(deficit);
        
        size_t dotPos = msg.find('.');
        if (dotPos != string::npos && msg.length() > dotPos + 3) {
            msg = msg.substr(0, dotPos + 3);
        }
        return msg.c_str();
    }
};

template<typename T>
class BankAccount {
private:
    T balance;
    string currencySymbol;
    
public:
    BankAccount(T initialBalance = 0, const string& symbol = "$") 
        : balance(initialBalance), currencySymbol(symbol) {}
        
    T getBalance() const {
        return balance;
    }
    
    void deposit(T amount) {
        if (amount <= 0) {
            throw invalid_argument("Deposit amount must be positive");
        }
        balance += amount;
    }
    
    void withdraw(T amount) {
        if (amount <= 0) {
            throw invalid_argument("Withdrawal amount must be positive");
        }
        
        if (amount > balance) {
            throw InsufficientFundsException(amount - balance, currencySymbol);
        }
        
        balance -= amount;
    }
    
    string getCurrencySymbol() const {
        return currencySymbol;
    }
};

int main() {
    try {
        BankAccount<double> account(500.0);
        
        cout << fixed << setprecision(2);
        cout << "Balance: " << account.getCurrencySymbol() << account.getBalance() << endl;
        
        cout << "Withdraw $600: ";
        account.withdraw(600.0);
        cout << "Successfully withdrew $600" << endl;
        
    } catch (const InsufficientFundsException& e) {
        cout << e.what() << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
    
    try {
        BankAccount<int> euroAccount(1000, "€");
        cout << "\nBalance: " << euroAccount.getCurrencySymbol() 
             << euroAccount.getBalance() << endl;
        
        cout << "Withdraw €1200: ";
        euroAccount.withdraw(1200);
        cout << "Successfully withdrew €1200" << endl;
        
    } catch (const InsufficientFundsException& e) {
        cout << e.what() << endl;
    }
    
    return 0;
}
