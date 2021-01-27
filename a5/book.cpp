#include "book.h"

//Constructor making a book object with 6 parameters
Book::Book(const string &name, const string &auth, const string &date, const string &type, const string &num,const string &pages)
: title(name), author(auth), dop(date), bookType(type), isbnNum(num), numPages(pages) {
}

string Book::getTitle() const { // Gets title of book
    return title;
}

string Book::getAuthor() const { // Gets author of book
    return author;
}

string Book::getDOP() const {  // Gets date of publication of book
    return dop;
}

string Book::getBookType() const { // Gets book type
    return bookType;
}

string Book::getISBN() const {  // Gets isbn # of book
    return isbnNum;
}

string Book::getNumPages() const {  // Gets pages of book
    return numPages;
}

void Book::setTitle(const string &newTitle) {  // Sets a new title
    title = newTitle;
}

void Book::setAuthor(const string &newAuthor) { // Sets a new author
    author = newAuthor;
}

void Book::setDOP(const string &newDOP) {  // Sets a date of publication title
    dop = newDOP;
}

void Book::setBookType(const string &newType) { // Sets a new book type
    bookType = newType;
}

void Book::setISBN(const string &newISBN) {  // Sets a new isbn number
    isbnNum = newISBN;
}

void Book::setNumPages(const string &newPages) { // Sets a new number of pages
    numPages = newPages;
}

Book::~Book() {} // Destructor

