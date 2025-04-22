#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main(){
    ifstream file1("chapter1.txt", ios::in);
    ifstream file2("chapter2.txt", ios::in);
    ofstream file3("book.txt", ios::app);
    string line1, line2;
    while(getline(file1, line1)){
        file3<<line1;
    }
    file3<<endl;
    while(getline(file2, line2)){
        file3<<line2;
    }
    file1.close();
    file2.close();
    file3.close();
    return 0;
}
