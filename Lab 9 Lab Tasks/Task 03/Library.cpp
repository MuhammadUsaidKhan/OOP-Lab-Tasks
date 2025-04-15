#include "Library.h"
#include <string>
#include <iostream>
using namespace std;
void Library::addBook(const Book& book) {
    if (bookCount < MAX_BOOKS) {
        books[bookCount] = book;
        bookCount++;
    }
}

bool Library::removeBook(const std::string& ISBN) {
    for (int i = 0; i < bookCount; i++) {
        if (books[i].getISBN() == ISBN) {
            // Shift remaining books left
            for (int j = i; j < bookCount - 1; j++) {
                books[j] = books[j + 1];
            }
            bookCount--;
            return true;
        }
    }
    return false;
}

const Book* Library::searchBook(const std::string& query) const {
    for (int i = 0; i < bookCount; i++) {
        if (books[i].getTitle().find(query) != std::string::npos ||
            books[i].getAuthor().find(query) != std::string::npos ||
            books[i].getISBN().find(query) != std::string::npos) {
            return &books[i];
        }
    }
    return nullptr;
}