#include <iostream>
#include <string>
using namespace std;
class SmartDevice{
    public:
        virtual void turnOn()=0;
        virtual void turnOff()=0;
        virtual bool getStatus()=0;
};
class LightBulb: virtual public SmartDevice{
    protected:
        bool isOn;
        int brightness;
    public:
        LightBulb(bool io, int b):isOn(io), brightness(b){}
        void turnOn(){
            isOn = true;
        }
        void turnOff(){
            isOn = false;
        }
        bool getStatus(){
            return isOn;
        }
};
class Thermostat: virtual public SmartDevice{
    protected:
        bool isOn;
        double temperature;
    public:
        Thermostat(bool io, double t):isOn(io), temperature(t){}
        void turnOn(){
            isOn = true;
        }
        void turnOff(){
            isOn = false;
        }
        bool getStatus(){
            return isOn;
        }
};
int main() {
    LightBulb lb1(true, 80);
    Thermostat t1(false, 25);
    lb1.turnOff();
    cout<<"Status for Light Bulb is: "<<lb1.getStatus()<<endl;
    t1.turnOn();
    cout<<"Status for Thermostat is: "<<t1.getStatus()<<endl;
    return 0;
}
