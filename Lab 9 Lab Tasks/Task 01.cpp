#include <iostream>
#include <string>
using namespace std;
class Vehicle{
    protected:
        string model;
        double rate;
    public:
        Vehicle(string m, double r):model(m), rate(r){}
        virtual double getDailyRate()=0;
        virtual void displayDetails()=0;
};
class Car: virtual public Vehicle{
    public:
    Car(string m, double r):Vehicle(m,r){}
    double getDailyRate(){
        return rate;
    }
    void displayDetails(){
        cout<<"Car's Daily rate is: "<<getDailyRate()<<endl;
        cout<<"Car's Model is: "<<model<<endl;
    }
};
class Bike: virtual public Vehicle{
    public:
    Bike(string m, double r):Vehicle(m,r){}
    double getDailyRate(){
        return rate;
    }
    void displayDetails(){
        cout<<"Bike's Daily rate is: "<<getDailyRate()<<endl;
        cout<<"Bike's Model is: "<<model<<endl;
    }
};
int main() {
    Car c1("2007Cultus", 2000);
    Bike b1("2022SuperStar", 500);
    c1.getDailyRate();
    c1.displayDetails();
    b1.getDailyRate();
    b1.displayDetails();
    return 0;
}
