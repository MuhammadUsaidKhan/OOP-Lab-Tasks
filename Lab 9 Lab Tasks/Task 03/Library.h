#ifndef LIBRARY
#define LIBRARY

#include "Book.h"

class Library {
private:
    static const int MAX_BOOKS = 100; 
    Book books[MAX_BOOKS];
    int bookCount = 0; 

public:
    void addBook(const Book& book);
    bool removeBook(const std::string& ISBN);
    const Book* searchBook(const std::string& query) const;
    int getBookCount() const { return bookCount; }
};

#endif 
