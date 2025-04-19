#include <iostream>
#include <string>
using namespace std;
class PaymentMethod{
    public:
        PaymentMethod(){}
        virtual bool processPayment(double amount)=0;
};
class CreditCard:public PaymentMethod{
    string cardNumber;
    public:
        CreditCard(string cn): cardNumber(cn){}
        bool processPayment(double amount){
            if(amount<=0){
                cout<<"Invalid Payment amount for credit card."<<endl;
                return false;
            }
            cout<<"Processing Credit Card Payment of $"<<amount<<endl;
            return true;
        }
};
class DigitalWallet:public PaymentMethod{
    double balance;
    public:
        DigitalWallet(double b):balance(b){}
        bool processPayment(double amount){
            if(amount<0){
                cout<<"Invalid Payment amount for Digital Wallet."<<endl;
                return false;
            }
            if(balance<amount){
                cout<<"Insufficient funds in digital wallet. Current balance: $" << balance << ", attempted payment: $" << amount<<endl;
                return false;
            }
            balance -=amount;
            cout << "Processed digital wallet payment of $" << amount 
                  << ". Remaining balance: $" << balance <<endl;
            return true;}
};

int main() {
    CreditCard c1("4210150157041");
    c1.processPayment(-300);
    c1.processPayment(100);
    DigitalWallet dw1(1000);
    dw1.processPayment(-325);
    dw1.processPayment(1500);
    dw1.processPayment(700);
    return 0;
}
