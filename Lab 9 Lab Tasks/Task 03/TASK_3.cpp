#include<iostream>
#include <string>
#include "Book.h"
// #include "Library.h"
using namespace std;
int main(){
    Book b1("a","a","a");
    cout<<b1.getAuthor()<<endl;
    cout<<b1.getISBN()<<endl;
    cout<<b1.getTitle();
    return 0;
}