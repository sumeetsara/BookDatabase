#include "menu.h"

Menu::Menu() {   // Default Constructor
    welcome();
}

void Menu::welcome() {  // Welcome menu
    cout << setw(73) << "Welcome to the Book Database!" << endl;
    cout << setw(72) << "What would you like to do?" << endl;
}

void Menu::menu() {
    cout << endl;
    cout << setw(110)
         << " To View Book Records enter: 0 | To Create New Book Records enter: 1 | To Delete A Record enter: 2"
         << endl;
    cout << setw(106) << " To Edit Existing Book Records enter: 3 | To Sort Records enter: 4 | To Search By enter: 5"
         << endl;
    cout << setw(68) << " To Exit enter: Exit" << endl;
    cout << endl;
}

string Menu::getReplyToWelcome() { // Gets the user's reply based of welcome menu
    string reply;
    cout << "What would you like to do? ";
    while (true) {
        getline(cin, reply);
        if (reply != "0" && reply != "1" && reply != "2" && reply != "3" && reply != "4" && reply != "5" &&
            reply != "Exit") { // User inputs one of these
            cout << "Must enter one of the above choices" << endl; // If not keeps asking
        } else {
            break;
        }
    }
    return reply; // return input
}

bool Menu::valTitle(const string &name) {  // Validates user input title
    if (name.empty()) { // If title is empty return false
        return false;
    }
    return true;
}

string Menu::titleInfoForNew() {  // Gets the user's input of title
    string reply;
    cout << "What would you like the title to be?: ";
    while (true) {
        getline(cin, reply);
        if (!valTitle(reply)) { // Check title for validation
            cout << "Invalid title. Please try again: ";
        } else {
            break;
        }
    }
    return reply;  // Returns title
}

bool Menu::valAuthor(const string &name) { // Validates user input author
    if (name.empty()) { // If user input is empty return false
        return false;
    }
    for (int i = 0; i < name.size(); i++) {  // Author name must have letters in it
        if (((name.at(i) < 'a' || name.at(i) > 'z') && (name.at(i) < 'A' || name.at(i) > 'Z')) &&
            name.at(i) != ' ') {
            return false;
        }
    }
    return true;
}

string Menu::authorInfoForNew() { // Gets the user's input of author
    string reply;
    cout << "Who would you like the author to be?: ";
    while (true) {
        getline(cin, reply);
        if (!valAuthor(reply)) {
            cout << "Invalid author name. Please try again: ";
        } else {
            break;
        }
    }
    return reply;   // Return author
}

bool Menu::valMonth(const string &name) { // Validates user input for month
    if (name.empty()) {  // Checks if empty
        return false;
    }
    string month = name;

    //https://www.geeksforgeeks.org/conversion-whole-string-uppercase-lowercase-using-stl-c/
    transform(month.begin(), month.end(), month.begin(), ::tolower);
    if (month != "january" && month != "february" && month != "march" && month != "april" && month != "may" &&
        month != "june" && month != "july" && month != "august" && month != "september" && month != "october" &&
        month != "november" && month != "december") {
        return false; // If doesn't equal a month return false
    }
    return true;
}

bool Menu::valDay(const string &day) { // Validates user input for month
    for (int i = 0; i < day.size(); i++) {
        if (day.at(i) < '0' || day.at(i) > '9') {
            return false;
        }
    }
    transform(curMonth.begin(), curMonth.end(), curMonth.begin(), ::tolower);
    int num = stoi(day);
    if (num <= 0 || num > 31) { // If out of range return false
        return false;
    } else if (curMonth == "february" && (num > 29 || num <= 0)) {
        return false;
    } else if ((curMonth == months.at(3) || curMonth == months.at(5) || curMonth == months.at(8) ||
                curMonth == months.at(10)) && (num <= 0 || num > 30)) {
        return false;
    }
    return true;
}

bool Menu::valYear(const string &year) { // Validates user input for month
    if (year.empty()) {
        return false;
    }

    if (year.at(0) == '-') { // If negative throw an error
        return false;
    }

    if (year > "2020") { // If year is greater then 2020
        return false;
    }
    return true;
}

string Menu::monthInfoForNew() {  // Gets input from user for month
    string reply;
    cout << "What would you like the month of publication to be? (FULL MONTH): ";
    while (true) {
        getline(cin, reply);
        if (!valMonth(reply)) { // Checks month is true
            cout << "Invalid month. Please try again: ";
        } else {
            break;
        }
    }
    transform(reply.begin(), reply.end(), reply.begin(), ::tolower);
    if (reply == months.at(0)) {
        reply = "00";
    } else if (reply == months.at(1)) {
        reply = "01";
    } else if (reply == months.at(2)) {
        reply = "02";
    } else if (reply == months.at(3)) {
        reply = "03";
    } else if (reply == months.at(4)) {
        reply = "04";
    } else if (reply == months.at(5)) {
        reply = "05";
    } else if (reply == months.at(6)) {
        reply = "06";
    } else if (reply == months.at(7)) {
        reply = "07";
    } else if (reply == months.at(8)) {
        reply = "08";
    } else if (reply == months.at(9)) {
        reply = "09";
    } else if (reply == months.at(10)) {
        reply = "10";
    } else if (reply == months.at(11)) {
        reply = "11";
    }

    curMonth = reply;
    return reply; // Returns month
}

string Menu::dayInfoForNew() { // Gets input from user for day
    string day;
    cout << "What would you like the day of month to be?: ";
    while (true) {
        getline(cin, day);
        if (!valDay(day)) { // Checks is day is true
            cout << "Invalid day. Please try again: ";
        } else {
            break;
        }
    }
    return day; // Returns the day
}

string Menu::yearInfoForNew() { // Gets input from user for year
    string reply;
    cout << "What would you like the year to be?: ";
    while (true) {
        getline(cin, reply);
        if (!valYear(reply)) { // Check is the year is true
            cout << "Invalid year. Please try again: ";
        } else {
            break;
        }
    }
    yearOfBook = reply;
    return reply; // Returns year
}

bool Menu::valType(string name) {  // Validates user input for type
    if (name.empty()) { // Checks if empty
        return false;
    }
    //https://www.geeksforgeeks.org/conversion-whole-string-uppercase-lowercase-using-stl-c/
    transform(name.begin(), name.end(), name.begin(), ::tolower);

    //  Got the find("word") != string::pos from this website:  https://stackoverflow.com/questions/2340281/check-if-a-string-contains-a-string-in-c
    if (name.find("softcover") == string::npos && name.find("hardcover") == string::npos &&
        name.find("digital") == string::npos) {
        return false;
    }
    return true;
}

string Menu::typeInfoForNew() { // Gets the user input for type
    string reply;
    cout << "What would you like the book type to be?: ";
    while (true) {
        getline(cin, reply);
        if (!valType(reply)) { // Checks is type is true
            cout << "Invalid book type. Please try again: ";
        } else {
            break;
        }
    }
    transform(reply.begin(), reply.end(), reply.begin(), ::tolower);
    return reply; // Returns book type
}

string Menu::checkISBNL(
        const string &num) { // Returns if the isbn # is 13 characters or 10 characters based on first 3 characters
    string size;
    if (num.at(0) == '9' && num.at(1) == '7' && (num.at(2) == '8' || num.at(2) == '9')) {
        size = "13";
    } else {
        size = "10";
    }

    return size; // Returns number
}

bool Menu::isbnToDate(const string &date, const string &num) { // Checks if a 13 digit isbn# is used if the date is after 2007
    if (num.empty()) { // False is empty
        return false;
    }
    string sz = checkISBNL(num);
    if (date >= "2007" && sz != "13") { // False is condition is not met
        return false;
    } else if (date < "2007" && sz != "10") {
        return false;
    }

    int counter = 0;
    for (int i = 0; i < num.size(); i++) { // Counts number of elements in ISBN
        if (num.at(i) != '-') {
            counter++;
        }
    }
    if (sz == "13" && counter != 13) { // If numbers do not match up return false
        return false;
    } else if (sz == "10" && counter != 10) {
        return false;
    }
    return true;
}

bool Menu::ifDash(const string &date, const string &num) { // Checks is the isbn# has the correct amount of dashes
    if (num.empty()) {  // Checks is empty     	// Also checks if characters are in range
        return false;
    }
    if (num.at(0) == '-') { // If dash at the beginning or end throw an error
        return false;
    } else if (num.at(num.size() - 1) == '-') {
        return false;
    }

    int dashCounter = 0;
    for (int i = 0; i < num.size(); i++) { // Counts dashes and checks characters
        if (num.at(i) == '-') {
            dashCounter++;
        }
        if (num.at(i) < '0' && num.at(i) > '9' && num.at(i) != '-' && num.at(i) != 'x' && num.at(i) != 'X') {
            return false;
        }
    }
    if (dashCounter == 4 && date < "2007") { // Checks conditions
        return false;
    } else if (dashCounter == 3 && date >= "2007") {
        return false;
    } else if (dashCounter < 3) {
        return false;
    }
    return true;
}

string Menu::isbnInfoForNew() { // Gets the isbn number from user
    string num;
    cout << "What do you want the ISBN # to be?: ";
    while (true) {
        getline(cin, num);
        if (!ifDash(yearOfBook, num)) { // Checks is the number is correct
            cout << "Invalid ISBN#. Please try again: ";
        } else if (!isbnToDate(yearOfBook, num)) { // Checks is the number is correct
            cout << "Invalid ISBN#. Please try again: ";
        } else {
            break;
        }
    }
    return num; // Returns number
}


bool Menu::valPages(const string &name) { // Validates user input for type
    if (name.empty()) { // Checks if empty
        return false;
    } else if (name.at(0) == '-') { // Checks is negative
        return false;
    }
    if (name.at(0) == '0') {
        return false;
    }

    for (int i = 0; i < name.size(); i++) { // Checks if the page is in range
        if (name.at(i) < '0' || name.at(i) > '9') {
            return false;
        }
    }
    return true;
}

string Menu::pagesInfoForNew() { // Gets the user input for type
    string reply;
    cout << "What would you like the # of pages to be?: ";
    while (true) {
        getline(cin, reply);
        if (!valPages(reply)) { // Checks is input is true
            cout << "Invalid # of pages. Please try again: ";
        } else {
            break;
        }
    }
    return reply; // Returns pages
}

int Menu::bookRecordDeleteInfo(const vector<Book> &contents) { // Delete a book record
    string number;
    int num = 0;
    cout << "Which book record would you like to delete? , eg. Delete first book record = line 1" << endl;
    cout << "Enter in the line number you want to delete: ";
    while (true) {
        getline(cin, number); // Gets the line number to be deleted
        if (!valLineForEditing(number, contents)) { // Checks condition
            cout << "Please enter the line number in range: ";
        } else {
            break;
        }
    }
    num = stoi(number);
    return num;  // Returns line number to be deleted
}

bool Menu::valTopicForEditing(const string &num) { // Validates topic to be edited
    if (num > "6" || num <= "0") {
        return false;
    }
    int number = stoi(num);
    if (number > 6 || number <= 0) { // If is out of range return false
        return false;
    }
    return true;
}

int Menu::topicInfoForEditing() { // Gets user's input of topic to be edited
    string field;
    int num = 0;
    cout << endl;
    cout << "Which field would you like to edit?" << endl;
    cout << "Title =       	    1" << endl;
    cout << "Author =      	    2" << endl;
    cout << "Publication Date = 3" << endl;
    cout << "Book Type =   	    4" << endl;
    cout << "ISBN # =      	    5" << endl;
    cout << "# of Pages =  	    6" << endl << endl;
    cout << "Enter the number corresponding to the field you want to edit: ";

    while (true) {
        getline(cin, field);
        if (!valTopicForEditing(field)) { // Checks if user input is valid
            cout << "Please enter the field number in range: ";
        } else {
            break;
        }
    }
    num = stoi(field);
    return num; // Returns the field
}

bool Menu::valLineForEditing(const string &num, const vector<Book> &contents) { // Validates row number
    for (int i = 0; i < num.size(); i++) {
        if (num.at(i) < '0' || num.at(i) > '9') {
            return false;
        }
    }
    int number = stoi(num);
    if (number > contents.size() || number <= 0) { // If out of range return false
        return false;
    }
    return true;
}

int Menu::lineInfoForEditing(const vector<Book> &contents) { // Get's user input for row number to be edited
    string number;
    int num = 0;
    cout << "Which book record would you like to edit? , eg. Edit first book record = line 1" << endl;
    cout << "Enter in the line number you want to edit: ";
    while (true) {
        getline(cin, number);
        if (!valLineForEditing(number, contents)) { // Checks is user input for row is true
            cout << "Please enter the line number in range: ";
        } else {
            break;
        }
    }
    num = stoi(number);
    return num;  // Returns row number
}

string Menu::userInputForEditing(int field) {  // Gets the user's input to edit a title, author, etc.
    string phrase;
    if (field == 1) {                // For editing the title
        phrase = titleInfoForNew();
    } else if (field == 2) {            // For editing the author
        phrase = authorInfoForNew();
    } else if (field == 3) {            // For editing the date
        string one = monthInfoForNew();
        string two = dayInfoForNew();
        string three = yearInfoForNew();
        phrase = one + " " + two + " " + three;
    } else if (field == 4) {            // For editing the book type
        phrase = typeInfoForNew();
    } else if (field == 5) {            // For editing the isbn#
        phrase = isbnInfoForNew();
    } else {
        phrase = pagesInfoForNew();        // For editing the the date
    }
    return phrase;                    // Return phrase
}


void Menu::outPutEdits(const string &title, const string &author, const string &date, const string &type, const string &isbn, const string &pages) { // Outputs the edits made by the user
    cout << endl;
    cout << "This is what you have entered " << endl;
    cout << "Title:   	  " << title << endl;
    cout << "Author:  	  " << author << endl;
    cout << "Date:    	  " << date << endl;
    cout << "Book Type:   " << type << endl;
    cout << "ISBN#:   	  " << isbn << endl;
    cout << "# of Pages:  " << pages << endl;
}

int Menu::askUserSort() { // Asks the user how they want to sort
    string phrase;
    int num = 0;
    cout << "Which field would you like to sort by? " << endl // Choices
         << "Title =        	 1" << endl
         << "Author =       	 2" << endl
         << "Publication Date =  3" << endl
         << "Book Type =    	 4" << endl
         << "ISBN # =       	 5" << endl
         << "# of Pages =   	 6" << endl << endl
         << "Enter the number corresponding to the field you want to sort by: ";
    while (true) {
        getline(cin, phrase); // Checks for validity
        if (!valTopicForEditing(phrase)) {
            cout << "Invalid Reply. Please try again ";
        } else {
            break;
        }
    }
    num = stoi(phrase);
    return num; // Returns corresponding number
}

int Menu::sortOrReverse() { // Asks user if they want to sort alphabetically or descending
    string phrase;
    int num = 0;
    cout << endl;
    cout << "Would you like to sort the field in ascending order or sort in descending order? " << endl;
    cout << "Sort in ascending order  =   1" << endl;
    cout << "Sort in descending order =   2" << endl;
    cout << endl;
    cout << "Enter the number corresponding to the choice of sorting: ";
    while (true) {
        getline(cin, phrase); // Checks for validity
        if (phrase != "1" && phrase != "2") {
            cout << "Invalid Reply. Please try again ";
        } else {
            break;
        }
    }
    num = stoi(phrase); // Returns choice number corresponding to choice
    return num;
}

bool Menu::sortByTitle(const Book &one, const Book &two) { // Sort by title
    return one.getTitle() < two.getTitle();
}

bool Menu::sortByAuthor(const Book &one, const Book &two) { // Sort by author
    return one.getAuthor() < two.getAuthor();
}

bool Menu::sortByDate(const Book &one, const Book &two) { // Sort by date
    return one.getDOP() < two.getDOP();
}

bool Menu::sortByType(const Book &one, const Book &two) { // Sort by book type
    return one.getBookType() < two.getBookType();
}

bool Menu::sortByISBN(const Book &one, const Book &two) { // Sort by isbn#
    return one.getISBN() < two.getISBN();
}

bool Menu::sortByPages(const Book &one, const Book &two) { // Sort by pages
    return one.getNumPages() < two.getNumPages();
}

void Menu::titleSorted(vector<Book> &contents) {  // Calls sort title
    std::sort(contents.begin(), contents.end(), sortByTitle);
}

void Menu::authorSorted(vector<Book> &contents) { // Calls sort author
    std::sort(contents.begin(), contents.end(), sortByAuthor);
}

void Menu::dateSorted(vector<Book> &contents) { // Calls sort date
    std::sort(contents.begin(), contents.end(), sortByDate);
}

void Menu::typeSorted(vector<Book> &contents) { // Calls sort Book type
    std::sort(contents.begin(), contents.end(), sortByType);
}

void Menu::isbnSorted(vector<Book> &contents) { // Calls sort isbn#
    std::sort(contents.begin(), contents.end(), sortByISBN);
}

void Menu::pagesSorted(vector<Book> &contents) { // Calls sort page#
    std::sort(contents.begin(), contents.end(), sortByPages);
}

void Menu::sortBy(vector<Book> &contents, int num) { // Calls the sort functions based on which field to be sorted
    if (num == 1) {                     // If by title
        titleSorted(contents);
    } else if (num == 2) {              // If by author
        authorSorted(contents);
    } else if (num == 3) {              // If by date
        dateSorted(contents);
    } else if (num == 4) {              // If by book type
        typeSorted(contents);
    } else if (num == 5) {              // If by isbn#
        isbnSorted(contents);
    } else {                            // If by page#
        pagesSorted(contents);
    }
}

void Menu::printSortMsg(int num) { // Prints a helpful message letting know user how data was sorted
    if (num == 1) {                      // If by title
        cout << endl;
        cout << "Sorted By Title" << endl;
    } else if (num == 2) {               // If by author
        cout << endl;
        cout << "Sorted By Author" << endl;
    } else if (num == 3) {                // If by date
        cout << endl;
        cout << "Sorted By Date of Publication" << endl;
    } else if (num == 4) {               // If by book type
        cout << endl;
        cout << "Sorted By Book Type" << endl;
    } else if (num == 5) {               // If by isbn#
        cout << endl;
        cout << "Sorted By ISBN#" << endl;
    } else if (num == 6) {               // If by page#
        cout << endl;
        cout << "Sorted By # of Pages" << endl;
    }
}

void Menu::reverseBy(vector<Book> &contents, int num) { // Reverses the ordering
    sortBy(contents, num);
    std::reverse(contents.begin(), contents.end());
}

int Menu::longestSort(const string &type, const vector<Book> &contents) { // Finds the longest string of title, author, etc.
    int longest = 0;            // Finds longest string to format table
    int prev = 0;
    string cur;

    if (type == "title") {        // If formatting title section
        for (int i = 0; i < contents.size(); i++) {
            cur = contents.at(i).getTitle();
            longest = cur.size();
            if (longest > prev) {
                prev = longest;
            }
        }
    } else if (type == "author") {   // If formatting author section
        for (int i = 0; i < contents.size(); i++) {
            cur = contents.at(i).getAuthor();
            longest = cur.size();
            if (longest > prev) {
                prev = longest;
            }
        }
    } else if (type == "dop") { // If formatting date section
        for (int i = 0; i < contents.size(); i++) {
            cur = contents.at(i).getDOP();
            longest = cur.size();
            if (longest > prev) {
                prev = longest;
            }
        }
    } else if (type == "bType") {  // If formatting book type section
        for (int i = 0; i < contents.size(); i++) {
            cur = contents.at(i).getBookType();
            longest = cur.size();
            if (longest > prev) {
                prev = longest;
            }
        }
    } else if (type == "isbn") {   // If formatting isbn # section
        for (int i = 0; i < contents.size(); i++) {
            cur = contents.at(i).getISBN();
            longest = cur.size();
            if (longest > prev) {
                prev = longest;
            }
        }
    } else if (type == "pages") {   // If formatting # of pages section
        for (int i = 0; i < contents.size(); i++) {
            cur = contents.at(i).getNumPages();
            longest = cur.size();
            if (longest > prev) {
                prev = longest;
            }
        }
    }
    return prev;
}

void Menu::printSorted(const vector<Book> contents) {  // Displays books in a table
    int titleSpacer = longestSort("title", contents);
    int authorSpacer = longestSort("author", contents);
    int dateSpacer = longestSort("dop", contents);
    int typeSpacer = longestSort("bType", contents);
    int isbnSpacer = longestSort("isbn", contents);
    int pagesSpacer = longestSort("pages", contents);

    cout << setw(7) << left << "Line#" << setw(titleSpacer + 2) << left << "Title" << setw(authorSpacer + 3) << left
         << "Author"
         << setw(dateSpacer + 12) << left << "Date of Publication" << setw(typeSpacer + 3) << left << "Book Type"
         << setw(isbnSpacer + 2) << left << "ISBN#" << setw(pagesSpacer) << left << "# of Pages" << endl;

    int p = 1;
    for (int i = 0; i < contents.size(); i++) {

        int idx1 = 0;
        int idx2 = 0;

        string month; // Finds the month

        for (int j = 0; j < contents.at(i).getDOP().size(); j++) {
            if (contents.at(i).getDOP().at(j) == ' ' && j == 4) {
                idx2 = j + 1;
            }
            if (contents.at(i).getDOP().at(j) == ' ' && j != 4) {
                idx1 = j;
                month = contents.at(i).getDOP().substr(idx2, idx1 - idx2);
            }
        }

        string year; // Finds year
        for (int f = 0; f < contents.at(i).getDOP().size(); f++) {
            if (contents.at(i).getDOP().at(f) == ' ') {
                year = contents.at(i).getDOP().substr(0, f);
                break;
            }
        }

        string day; // Finds day
        for (int a = contents.at(i).getDOP().size() - 1; a > 0; a--) {
            if (contents.at(i).getDOP().at(a) == ' ') {
                day = contents.at(i).getDOP().substr(a + 1, contents.at(i).getDOP().size() - 1);
                break;
            }
        }

        if (month == "00") {
            month = "January";
        } else if (month == "01") {
            month = "February";
        } else if (month == "02") {
            month = "March";
        } else if (month == "03") {
            month = "April";
        } else if (month == "04") {
            month = "May";
        } else if (month == "05") {
            month = "June";
        } else if (month == "06") {
            month = "July";
        } else if (month == "07") {
            month = "August";
        } else if (month == "08") {
            month = "September";
        } else if (month == "09") {
            month = "October";
        } else if (month == "10") {
            month = "November";
        } else if (month == "11") {
            month = "December";
        }

        cout << setw(7) << left << p << setw(titleSpacer + 2) << left << contents.at(i).getTitle()
             << setw(authorSpacer + 3) << left << contents.at(i).getAuthor() <<
             setw(dateSpacer + 12) << left << year + " " + month + " " + day << setw(typeSpacer + 3) << left
             << contents.at(i).getBookType() <<
             setw(isbnSpacer + 2) << left << contents.at(i).getISBN() << setw(pagesSpacer) << left
             << contents.at(i).getNumPages() << endl;
        p++;
    }
}

int Menu::askUserSearch() { // Asks the user how they want to sort
    string phrase;
    int num = 0;
    cout << endl;
    cout << "Which field would you like to search by? " << endl // Choices
         << "Title =        	 1" << endl
         << "Author =       	 2" << endl
         << "Publication Date =  3" << endl
         << "Book Type =    	 4" << endl
         << "ISBN # =       	 5" << endl
         << "# of Pages =   	 6" << endl << endl
         << "Enter the number corresponding to the field you want to search by: ";
    while (true) {
        getline(cin, phrase); // Checks for validity
        if (!valTopicForEditing(phrase)) {
            cout << "Invalid Reply. Please try again ";
        } else {
            break;
        }
    }
    num = stoi(phrase);
    return num; // Returns number corresponding to choice made
}

string Menu::getInputSearch(int num) {  // Gets the input from user on which value to find
    string field;
    if (num == 1) {                                              // If they want to search a specific title
        field = "What Title will you like to search by: ";
    } else if (num == 2) {                                       // If they want to search a specific author
        field = "Which Author will you like to search by: ";
    } else if (num == 3) {                                       // If they want to search a specific date
        field = "What Date of Publication will you like to search by: ";
    } else if (num == 4) {                                      // If they want to search a specific book type
        field = "What Book Type will you like to search by: ";
    } else if (num == 5) {                                       // If they want to search a specific isbn#
        field = "What ISBN# will you like to search by: ";
    } else if (num == 6) {                                       // If they want to search a specific page#
        field = "What # of pages will you like to search by: ";
    }
    string phrase;
    cout << field;
    getline(cin, phrase);
    return phrase;
}

string Menu::getType(int idx, int type, const vector<Book> &contents) { // Gets the field at a certain index of the database vector
    if (type == 1) {
        return contents.at(idx).getTitle(); // Returns a specific title of idx
    } else if (type == 2) {
        return contents.at(idx).getAuthor(); // Returns a specific author of idx
    } else if (type == 3) {
        return contents.at(idx).getDOP(); // Returns a specific date of idx
    } else if (type == 4) {
        return contents.at(idx).getBookType(); // Returns a specific book type of idx
    } else if (type == 5) {
        return contents.at(idx).getISBN(); // Returns a specific isbn# of idx
    } else {
        return contents.at(idx).getNumPages(); // Returns a specific page # of idx
    }
}

// Got the following linear searches and binary searches from the notes: https://www2.cs.sfu.ca/CourseCentral/135/tjd/basic_sorting.html
int Menu::binary_search(const string &x, const vector<Book> &v, int begin, int end,int type) { // Returns the index of the value found
    while (begin < end) {
        int mid = (begin + end) / 2;
        if (getType(mid, type, v) == x) { // Item found
            return mid;
        } else if (x < getType(mid, type, v)) {
            end = mid;
        } else if (x > getType(mid, type, v)) {
            begin = mid + 1;
        }
    }
    return -1;  // If item not found
}

void Menu::linear_searchUp(const vector<Book> &v, const string &x, vector<Book> &nums,int type) { // Finds more values of the same incrementing up from the middle
    int idx = binary_search(x, v, 0, v.size(), type);
    for (int i = idx; i < v.size(); i++) {
        if (x == getType(i, type, v)) { // Value found
            nums.push_back(v.at(i)); // Pushes back value indexes into a new vector<Book>
        } else {
            break;
        }
    }
}

void Menu::linear_searchDown(const vector<Book> &v, const string &x, vector<Book> &nums,int type) { // Finds more values of the same decrementing down up from the middle
    int idx = binary_search(x, v, 0, v.size(), type) - 1;
    for (int i = idx; i >= 0; i--) {
        if (x == getType(i, type, v)) { // Value found
            nums.push_back(v.at(i)); // Pushes back value indexes into a new vector<Book>
        } else {
            break;
        }
    }
}

void Menu::linear_searchUpExclusive(const vector<Book> &v, const string &x, vector<Book> &nums,int type) { // Finds more values of the same incrementing up from the middle
    int idx = binary_search(x, v, 0, v.size(), type);
    if(idx < 0) {
        nums = v;
    }
    for (int i = idx; i < v.size(); i++) {
        if (x != getType(i, type, v)) { // Value found
            nums.push_back(v.at(i)); // Pushes back value indexes into a new vector<Book>
        }
    }
}

void Menu::linear_searchDownExclusive(const vector<Book> &v, const string &x, vector<Book> &nums,int type) { // Finds more values of the same decrementing down up from the middle
    int idx = binary_search(x, v, 0, v.size(), type) - 1;
    if(idx < 0) {
        nums = v;
    }
    for (int i = idx; i >= 0; i--) {
        if (x != getType(i, type, v)) { // Value found
            nums.push_back(v.at(i)); // Pushes back value indexes into a new vector<Book>
        }
    }
}

void Menu::askMoreThenOneSearch(const string &phrase, vector<Book> &contents) {  // Asks user how to display searches found
    cout << "There is more then one item with the search '" << phrase << "'" << endl << endl;
    int ask = askUserSort();
    int number = sortOrReverse();       // Sorts the searches in a specific way
    if (number == 1) {                   // Sorts alphabetically
        sortBy(contents, ask);
        printSorted(contents);
    } else if (number == 2) {            // Sorts in descending order
        reverseBy(contents, ask);
        printSorted(contents);
    }
    printSortMsg(ask);
}

void Menu::callSortOption(vector<Book> contents) { // Asks user how they want to sort
    int reply = askUserSort();               // Gets the reply for how they want to sort
    int choice = sortOrReverse();            // Asks to sort in ascending or descending
    if (choice == 1) {                       // Sort in ascending
        sortBy(contents, reply);
        printSortMsg(reply);
    } else if (choice == 2) {                 // Sort in descending
        reverseBy(contents, reply);
        printSortMsg(reply);
    }
    printSorted(contents);
}

void Menu::callSimple(vector<Book> contents, vector<Book> outPut) { // Does the simple search
    int reply = askUserSearch();                                    // Asks user for field
    string phrase = getInputSearch(reply);                          // Asks user for input
    sortBy(contents, reply);                                    // Sorts and finds
    linear_searchUp(contents, phrase, outPut, reply);
    linear_searchDown(contents, phrase, outPut, reply);
    if (outPut.size() > 1) {                                        // Displays search
        askMoreThenOneSearch(phrase, outPut);
    } else if (outPut.size() == 1) {
        printSorted(outPut);
    } else if (outPut.empty()) {
        cout << "No search yielded for '" << phrase << "'" << endl;
    }
}

int Menu::askUserForSearchType() { // Asks the user if they will want to search by 1 field (simple search) or muliple fields(complex search)
    string phrase;
    int num = 0;
    cout << "Would you like to do a Simple Search or a Complex Search " << endl;
    cout << "Simple Search =  1" << endl;
    cout << "Complex Search = 2" << endl;
    cout << endl;
    cout << "Enter the number corresponding to the choice of searching: ";
    while (true) {
        getline(cin, phrase); // Checks for validity
        if (phrase != "1" && phrase != "2") {
            cout << "Invalid Reply. Please try again ";
        } else {
            break;
        }
    }
    num = stoi(phrase); // Returns choice number corresponding to choice
    return num;
}


string Menu::exIn(const string &field) { // Asks the user if they want to search inclusively or exclusively
    cout << endl;
    string phrase;
    cout << "Is '" << field << "' going to be searched inclusive or exclusive?" << endl;
    cout << "Inclusive = 1" << endl;
    cout << "Exclusive = 2" << endl;
    cout << "Enter the number corresponding to the choice: ";
    while (true) {
        getline(cin, phrase);
        if (phrase != "1" && phrase != "2") {  // Checks validity
            cout << "Invalid entry. PLease try again: ";
        } else {
            break;
        }
    }
    return phrase; // Returns user's decision
}

string Menu::userComplexSearch(int num) { // Asks the user if they want to search a specific field inclusively or exclusively
    string phrase;
    if (num == 1) {  // Search title inclusively or exclusively
        cout << "Enter the title you want to search inclusively or exclusively by, if not hit enter: ";
        getline(cin, phrase);
    } else if (num == 2) { // Search author inclusively or exclusively
        cout << "Enter the author you want to search inclusively or exclusively by, if not hit enter: ";
        getline(cin, phrase);
    } else if (num == 3) { // Search date inclusively or exclusively
        cout
                << "Enter the date of publication (YEAR MONTH DAY) you want to search inclusively or exclusively by, if not hit enter: ";
        getline(cin, phrase);
    } else if (num == 4) { // Search book type inclusively or exclusively
        cout << "Enter the book type you want to search inclusively or exclusively by, if not hit enter: ";
        getline(cin, phrase);
    } else if (num == 5) { // Search isbn# inclusively or exclusively
        cout << "Enter the ISBN# you want to search inclusively or exclusively by, if not hit enter: ";
        getline(cin, phrase);
    } else if (num == 6) { // Search page# inclusively or exclusively
        cout << "Enter the # of pages you want to search inclusively or exclusively by, if not hit enter: ";
        getline(cin, phrase);
    }
    return phrase;
}

void Menu::callComplex(vector<Book> &contents, vector<Book> &results, vector<Book> &temp) { // Calls the complex searching
    string inputTitle = userComplexSearch(1);
    if (!inputTitle.empty()) {   // Asks for user's input for title
        sortBy(contents, 1);
        string optionTitle = exIn(inputTitle);
        if (optionTitle == "1") {   // If title is searched inclusively then use this linear search
            linear_searchUp(contents, inputTitle, results, 1);
            linear_searchDown(contents, inputTitle, results, 1);
        } else if (optionTitle == "2") {   // If title is searched exclusively then use this linear search
            linear_searchUpExclusive(contents, inputTitle, results, 1);
            linear_searchDownExclusive(contents, inputTitle, results, 1);
        }
    } else {  // If empty
        results = contents;
    }

    string inputAuthor = userComplexSearch(2); // Asks for user's input for author
    if (!inputAuthor.empty()) {
        sortBy(results, 2);
        string optionAuthor = exIn(inputAuthor);
        if (optionAuthor == "1") {   // If author is searched inclusively then use this linear search
            linear_searchUp(results, inputAuthor, temp, 2);
            linear_searchDown(results, inputAuthor, temp, 2);
        } else if (optionAuthor == "2") {   // If author is searched exclusively then use this linear search
            linear_searchUpExclusive(results, inputAuthor, temp, 2);
            linear_searchDownExclusive(results, inputAuthor, temp, 2);
        }
    } else {
        temp = results; // If empty
    }

    string inputDate = userComplexSearch(3); // Asks for user's input for date
    if (!inputDate.empty()) {
        contents = temp;
        results.clear();
        sortBy(contents, 3);
        string optionDate = exIn(inputDate);
        if (optionDate == "1") {   // If date is searched inclusively then use this linear search
            linear_searchUp(contents, inputDate, results, 3);
            linear_searchDown(contents, inputDate, results, 3);
        } else if (optionDate == "2") {  // If date is searched exclusively then use this linear search
            linear_searchUpExclusive(contents, inputDate, results, 3);
            linear_searchDownExclusive(contents, inputDate, results, 3);
        }
    } else { // If empty
        contents = temp;
        results = contents;
    }

    string inputType = userComplexSearch(4);  // Asks for user's input for book type
    if (!inputType.empty()) {
        temp.clear();
        sortBy(results, 4);
        string optionType = exIn(inputType);
        if (optionType == "1") {   // If type is searched inclusively then use this linear search
            linear_searchUp(results, inputType, temp, 4);
            linear_searchDown(results, inputType, temp, 4);
        } else if (optionType == "2") {  // If type is searched exclusively then use this linear search
            linear_searchUpExclusive(results, inputType, temp, 4);
            linear_searchDownExclusive(results, inputType, temp, 4);
        }
    } else {
        temp = results;
    }


    string inputISBN = userComplexSearch(5);  // Asks for user's input for isbn#
    if (!inputISBN.empty()) {
        contents = temp;
        results.clear();
        sortBy(contents, 5);
        string optionISBN = exIn(inputISBN);
        if (optionISBN == "1") {   // If isbn# is searched inclusively then use this linear search
            linear_searchUp(contents, inputISBN, results, 5);
            linear_searchDown(contents, inputISBN, results, 5);
        } else if (optionISBN == "2") {  // If isbn# is searched exclusively then use this linear search
            linear_searchUpExclusive(contents, inputISBN, results, 5);
            linear_searchDownExclusive(contents, inputISBN, results, 5);
        }
    } else {
        contents = temp;
        results = contents;
    }


    string inputPages = userComplexSearch(6); // Asks for user's input for pages
    if (!inputPages.empty()) {
        temp.clear();
        sortBy(results, 6);
        string optionPages = exIn(inputPages);
        if (optionPages == "1") {    // If # of pages is searched inclusively then use this linear search
            linear_searchUp(results, inputPages, temp, 6);
            linear_searchDown(results, inputPages, temp, 6);
        } else if (optionPages == "2") { // If # of pages is searched exclusively then use this linear search
            linear_searchUpExclusive(results, inputPages, temp, 6);
            linear_searchDownExclusive(results, inputPages, temp, 6);
        }
    } else {
        temp = results;
    }

    cout << endl;
    if (temp.size() > 1) { // If more then one item in the result then ask user how they want it sorted
        askMoreThenOneSearch(
                inputTitle + " " + inputAuthor + " " + inputDate + " " + inputType + " " + inputISBN + " " + inputPages,
                temp);
    } else if (temp.size() == 1) { // Print the 1 item in the result
        printSorted(temp);
    } else if (temp.empty()) { // If empty
        cout << "No search yielded with that search" << endl;
    }
}

Menu::~Menu() {} // Destructor





