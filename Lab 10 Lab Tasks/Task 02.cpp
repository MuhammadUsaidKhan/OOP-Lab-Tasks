#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main(){
    string name,email,summary;
    int yearsOfExperience;
    cout<<"Enter Name: "<<endl;
    cin>>name;
    cout<<"Enter Email: "<<endl;
    cin>>email;
    cout<<"Enter Years of Experience: "<<endl;
    cin>>yearsOfExperience;
    cout<<"Enter Summary: "<<endl;
    cin>>summary;
    ofstream file("resume.txt", ios::trunc);
    if(!file){
        cout<<"Error in opening the file!"<<endl;
        exit(0);
    }
    file<<name<<" "<<email<<" "<<yearsOfExperience<<" "<<summary<<endl;
    file.close();
    ifstream file1("resume.txt", ios::in);
    if(!file1){
        cout<<"Error in opening the file!"<<endl;
        exit(0);
    }
    string line;
    while(getline(file1, line)){
        cout<<line<<endl;
    }
    file1.close();
    return 0;
}
