#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct Student{
        int id;
        string name;
        float gpa;
        Student(){}
        Student(int id, string name, float gpa){
            this->id=id;
            this->name=name;
            this->gpa=gpa;
        }
        void getData(){
            cout<<"Enter ID of Student: ";
            cin>>id;
            cout<<"Enter Name of Student: ";
            cin>>name;
            cout<<"Enter GPA of Student: ";
            cin>>gpa;
        }
};
int main(){
    Student student[6];
    fstream file("students.txt", ios::out);
    if(!file){
        cout<<"Error in opening file!!"<<endl;
        exit(0);
    }
    for(int i=0; i<5; i++){
        student[i].getData();
        file<< student[i].id<<" "<<student[i].name<<" "<<student[i].gpa<<endl;
        file.flush();
    }
    file.close();
    file.open("students.txt", ios::app);
    student[5].getData();
    file<< student[5].id<<" "<<student[5].name<<" "<<student[5].gpa<<endl;
    file.close();
    file.open("students.txt", ios::in);
    string line;
    while(getline(file, line)){
        cout<<line<<endl;
    }
    file.close();
    return 0;
}
