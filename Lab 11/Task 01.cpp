#include <iostream>
#include <string>
#include <exception>
using namespace std;
class InvalidValueException:public exception{
    public:
        const char* what() const noexcept override{
            return "InvalidValueException - Age cannot be negative or exceed 125.";
        }
};
void validateAge(int age){
    if(age<=0 || age>125){
        throw InvalidValueException();
    }
}
int main()
{
    int age;
    cout<<"Enter Age: ";
    cin>>age;
    try{
        validateAge(age);
        cout<<"Age is valid: "<<age<<endl;
    }
    catch(const InvalidValueException& e){
        cerr<<"Error: "<<e.what()<<endl;
    }
    catch(...){
        cerr<<"An unknown error occured."<<endl;
    }
    return 0;
}
