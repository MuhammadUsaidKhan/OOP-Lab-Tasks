#include "Book.h"
#include <iostream>
#include <string>
using namespace std;
string Book::getAuthor(){
    cout<<"Its is returning Author."<<endl;
    return author;
}
string Book::getTitle(){
    cout<<"It is returning Title."<<endl;
    return title;
}
string Book::getISBN(){
    cout<<"It is returning ISBN Number."<<endl;
    return ISBN;
}