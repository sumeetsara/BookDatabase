#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "cmpt_error.h"
#include "book.h"
using namespace std;

class Menu {   // Menu class initialized
private:
    string yearOfBook;
    string curMonth;
    vector<string> months = {"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};
public:
    Menu();  // Default Constructor

    void welcome(); // Welcome menu

    void menu();

    string getReplyToWelcome(); // Gets the user's reply based of welcome menu

    bool valTitle(const string &name); // Validates user input title

    string titleInfoForNew();  // Gets the user's input of title

    bool valAuthor(const string &name); // Validates user input author

    string authorInfoForNew(); // Gets the user's input of author

    bool valMonth(const string &name);// Validates user input for month

    bool valDay(const string &day); // Validates user input for month

    bool valYear(const string &year); // Validates user input for month

    string monthInfoForNew(); // Gets input from user for month

    string dayInfoForNew(); // Gets input from user for day

    string yearInfoForNew();// Gets input from user for year

    bool valType(string name);  // Validates user input for type

    string typeInfoForNew(); // Gets the user input for type

    string checkISBNL(const string &num); // Returns if the isbn # is 13 characters or 10 characters based on first 3 characters

    bool isbnToDate(const string &date, const string &num); // Checks if a 13 digit isbn# is used if the date is after 2007

    bool ifDash(const string &date, const string &num); // Checks is the isbn# has the correct amount of dashes

    string isbnInfoForNew();// Gets the isbn number from user

    bool valPages(const string &name);// Validates user input for type

    string pagesInfoForNew(); // Gets the user input for type

    int bookRecordDeleteInfo(const vector<Book> &contents); // Delete a book record

    bool valTopicForEditing(const string &num); // Validates topic to be edited

    int topicInfoForEditing();// Gets user's input of topic to be edited

    bool valLineForEditing(const string &num, const vector<Book> &contents); // Validates row number

    int lineInfoForEditing(const vector<Book> &contents); // Get's user input for row number to be edited

    string userInputForEditing(int field); // Gets the user's input to edit a title, author, etc.

    void outPutEdits(const string &title, const string &author, const string &date, const string &type, const string &isbn, const string &pages); // Outputs the edits made by the user

    int askUserSort();// Asks the user how they want to sort

    int sortOrReverse(); // Asks user if they want to sort alphabetically or descending

    static bool sortByTitle(const Book &one, const Book &two); // Sort by title

    static bool sortByAuthor(const Book &one, const Book &two);// Sort by author

    static bool sortByDate(const Book &one, const Book &two); // Sort by date

    static bool sortByType(const Book &one, const Book &two); // Sort by book type

    static bool sortByISBN(const Book &one, const Book &two);// Sort by isbn#

    static bool sortByPages(const Book &one, const Book &two); // Sort by pages

    void titleSorted(vector<Book> &contents);  // Calls sort title

    void authorSorted(vector<Book> &contents); // Calls sort author

    void dateSorted(vector<Book> &contents);// Calls sort date

    void typeSorted(vector<Book> &contents); // Calls sort Book type

    void isbnSorted(vector<Book> &contents); // Calls sort isbn#

    void pagesSorted(vector<Book> &contents); // Calls sort page#

    void sortBy(vector<Book> &contents, int num); // Calls the sort functions based on which field to be sorted

    void printSortMsg(int num);// Prints a helpful message letting know user how data was sorted

    void reverseBy(vector<Book> &contents, int num); // Reverses the ordering

    int longestSort(const string &type, const vector<Book> &contents); // Finds the longest string of title, author, etc.

    void printSorted(const vector<Book> contents); // Displays books in a table

    int askUserSearch(); // Asks the user how they want to sort

    string getInputSearch(int num); // Gets the input from user on which value to find

    string getType(int idx,int type, const vector<Book>& contents); // Gets the field at a certain index of the database vector

    // Got the following linear searches and binary searches from the notes: https://www2.cs.sfu.ca/CourseCentral/135/tjd/basic_sorting.html
    int binary_search(const string& x, const vector<Book>& v, int begin, int end, int type); // Returns the index of the value found

    void linear_searchUp(const vector<Book>& v, const string& x, vector<Book>& nums, int type);// Finds more values of the same incrementing up from the middle

    void linear_searchDown(const vector<Book>& v, const string& x, vector<Book>& nums, int type); // Finds more values of the same decrementing down up from the middle

    void linear_searchUpExclusive(const vector<Book>& v, const string& x, vector<Book>& nums, int type); // Finds more values of the same incrementing up from the middle

    void linear_searchDownExclusive(const vector<Book>& v, const string& x, vector<Book>& nums, int type); // Finds more values of the same decrementing down up from the middle

    void askMoreThenOneSearch(const string& phrase, vector<Book>& contents);  // Asks user how to display searches found

    void callSortOption(vector<Book> contents); // Asks user how they want to sort

    void callSimple(vector<Book> contents,vector<Book> outPut);// Does the simple search

    int askUserForSearchType();// Asks the user if they will want to search by 1 field (simple search) or muliple fields(complex search)

    string exIn(const string &field); // Asks the user if they want to search inclusively or exclusively

    string userComplexSearch(int num);// Asks the user if they want to search a specific field inclusively or exclusively

    void callComplex(vector<Book>& contents,vector<Book>& results, vector<Book>& temp);// Calls the complex searching

    ~Menu(); // Destructor
};

#endif //A5_MENU_H
