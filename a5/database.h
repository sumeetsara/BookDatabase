#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "cmpt_error.h"
#include "book.h"
using namespace std;

class Database {  // Database class initialized
private:
    vector<Book> content; // Private variables
    vector<string> fields;
public:
    Database();   // Default Constructor

    void sub(const string &in);// Divides the string into 6 different parts eg. title, author, etc.

    void ReadIn(); // Reads in from file containing parts of the book

    void addNew(const string &name, const string &auth, const string &date, const string &bookType, const string &isbnNum,const string &numPages); // Add a new book record

    void deleteOld(int i); // Delete a book record

    void update(const string &newField, int idx, int record); // Update a book record

    void readOut(); // Reads back to the file

    int longestStr(const string &type); // Finds the longest string of title, author, etc.

    void displayBooks(); // Displays books in a table

    vector<Book> getRecords();   // Return vector of books

    ~Database();   // Destructor
};

#endif //A5_DATABASE_H
