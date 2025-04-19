#include <iostream>
#include <string>
using namespace std;
class Activity{
    public:
        Activity(){}
        virtual double calculateCaloriesBurned()=0;
};
class Running:public Activity{
    double distance;
    double time;
    public:
        Running(double d, double t): distance(d), time(t){}
        double calculateCaloriesBurned(){
            double calories = distance * time;
            cout<<"Total Calories burned after running a distance of "<<distance<<" km for "<<time<<" minutes are "<<calories<<endl;
            return calories;
        }
};
class Cycling:public Activity{
    double speed;
    double time;
    public:
        Cycling(double s, double t):speed(s), time(t){}
        double calculateCaloriesBurned(){
            double calories = speed * time;
            cout<<"Total Calories burned after cycling with a speed of "<<speed<<" km/h for "<<time<<" hours are "<<calories<<endl;
            return calories;
        }
};

int main() {
    Running r1(25, 5);
    r1.calculateCaloriesBurned();
    Cycling c1(7, 2);
    c1.calculateCaloriesBurned();
    return 0;
}
