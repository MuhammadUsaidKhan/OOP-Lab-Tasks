#ifndef BOOK
#define BOOK
#include <string>
using namespace std;
class Book
{
protected:
    string title, author, ISBN;
public:
    Book(string t, string a, string isbn):title(t), author(a), ISBN(isbn){}
    string getTitle();
    string getAuthor();
    string getISBN();
    // ~Book();
};
#endif
