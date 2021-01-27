#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "cmpt_error.h"
using namespace std;

class Book {  // Book class initialized
private:
    string title; // Private variables
    string author;
    string dop;
    string bookType;
    string isbnNum;
    string numPages;
public:
    //Constructor making a book object with 6 parameters
    Book(const string &name, const string &auth, const string &date, const string &type, const string &num,const string &pages);

    string getTitle() const;// Gets title of book

    string getAuthor() const; // Gets author of book

    string getDOP() const;  // Gets date of publication of book

    string getBookType() const;// Gets book type

    string getISBN() const;// Gets isbn # of book

    string getNumPages() const; // Gets pages of book

    void setTitle(const string &newTitle); // Sets a new title

    void setAuthor(const string &newAuthor); // Sets a new author

    void setDOP(const string &newDOP); // Sets a date of publication title

    void setBookType(const string &newType);// Sets a new book type

    void setISBN(const string &newISBN);// Sets a new isbn number

    void setNumPages(const string &newPages);// Sets a new number of pages

    ~Book();// Destructor
};

#endif //A5_BOOK_H
