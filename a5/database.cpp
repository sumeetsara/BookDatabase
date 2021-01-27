#include "database.h"

Database::Database()   // Default Constructor
{
    ReadIn();
}

void Database::sub(const string &in) { // Divides the string into 6 different parts eg. title, author, etc.
    string mod;
    int idx = 0;
    int prevIdx = 0;
    string sz;
    int p = 0;
    for (int i = 0; i < in.size(); i++) {
        if (in.at(i) == '~') {
            idx = i;
            mod = in.substr(prevIdx, idx - prevIdx);
            fields.push_back(mod);
            sz = fields.at(p);
            prevIdx = prevIdx + sz.size() + 1;
            p++;
        }
    }
}

void Database::ReadIn() { // Reads in from file containing parts of the book
    ifstream inFile;
    inFile.open("books.txt");
    string s;
    if (inFile.fail()) {
        cmpt::error("Can not open file");
    }
    while (true) {
        getline(inFile, s);
        if (inFile.fail() || s.empty()) {
            break;
        }
        sub(s);
        Book copy(fields.at(0), fields.at(1), fields.at(2), fields.at(3), fields.at(4), fields.at(5));
        content.push_back(copy); // Pushes a book object into a vector of books
        fields.clear();
    }
    inFile.close();
}

// Add a new book record
void Database::addNew(const string &name, const string &auth, const string &date, const string &bookType, const string &isbnNum,
            const string &numPages) {
    Book newRecord(name, auth, date, bookType, isbnNum, numPages);
    content.push_back(newRecord);
}

void Database::deleteOld(int i) { // Delete a book record
    content.erase(content.begin() + i);
}

void Database::update(const string &newField, int idx, int record) { // Update a book record

    if (record == 0) {
        content.at(idx).setTitle(newField);
    } else if (record == 1) {
        content.at(idx).setAuthor(newField);
    } else if (record == 2) {
        content.at(idx).setDOP(newField);
    } else if (record == 3) {
        content.at(idx).setBookType(newField);
    } else if (record == 4) {
        content.at(idx).setISBN(newField);
    } else if (record == 5) {
        content.at(idx).setNumPages(newField);
    }
}

void Database::readOut() {  // Reads back to the file
    ofstream outFile;
    outFile.open("books.txt");
    string s;
    for (int i = 0; i < content.size(); i++) {
        s += content.at(i).getTitle() + "~";
        s += content.at(i).getAuthor() + "~";
        s += content.at(i).getDOP() + "~";
        s += content.at(i).getBookType() + "~";
        s += content.at(i).getISBN() + "~";
        s += content.at(i).getNumPages() + "~" + "\n";
    }
    outFile << s << endl;
}

int Database::longestStr(const string &type) { // Finds the longest string of title, author, etc.
    int longest = 0;            // Finds longest string to format table
    int prev = 0;
    string cur;

    if (type == "title") {        // If formatting title section
        for (int i = 0; i < content.size(); i++) {
            cur = content.at(i).getTitle();
            longest = cur.size();
            if (longest > prev) {
                prev = longest;
            }
        }
    } else if (type == "author") {   // If formatting author section
        for (int i = 0; i < content.size(); i++) {
            cur = content.at(i).getAuthor();
            longest = cur.size();
            if (longest > prev) {
                prev = longest;
            }
        }
    } else if (type == "dop") { // If formatting date section
        for (int i = 0; i < content.size(); i++) {
            cur = content.at(i).getDOP();
            longest = cur.size();
            if (longest > prev) {
                prev = longest;
            }
        }
    } else if (type == "bType") {  // If formatting book type section
        for (int i = 0; i < content.size(); i++) {
            cur = content.at(i).getBookType();
            longest = cur.size();
            if (longest > prev) {
                prev = longest;
            }
        }
    } else if (type == "isbn") {   // If formatting isbn # section
        for (int i = 0; i < content.size(); i++) {
            cur = content.at(i).getISBN();
            longest = cur.size();
            if (longest > prev) {
                prev = longest;
            }
        }
    } else if (type == "pages") {   // If formatting # of pages section
        for (int i = 0; i < content.size(); i++) {
            cur = content.at(i).getNumPages();
            longest = cur.size();
            if (longest > prev) {
                prev = longest;
            }
        }
    }
    return prev;
}

void Database::displayBooks() {  // Displays books in a table
    int titleSpacer = longestStr("title");
    int authorSpacer = longestStr("author");
    int dateSpacer = longestStr("dop");
    int typeSpacer = longestStr("bType");
    int isbnSpacer = longestStr("isbn");
    int pagesSpacer = longestStr("pages");

    cout << setw(7) << left << "Line#" << setw(titleSpacer + 2) << left << "Title" << setw(authorSpacer + 3) << left
         << "Author"
         << setw(dateSpacer + 12) << left << "Date of Publication" << setw(typeSpacer + 3) << left << "Book Type"
         << setw(isbnSpacer + 2) << left << "ISBN#" << setw(pagesSpacer) << left << "Pages" << endl;

    int line = 1;
    for (int i = 0; i < content.size(); i++) {

        vector<string> months = {"january", "february", "march", "april", "may", "june", "july", "august", "september",
                                 "october", "november", "december"};

        int idx1 = 0;
        int idx2 = 0;

        string month; // Finds the month
        for (int j = 0; j < content.at(i).getDOP().size(); j++) {
            if (content.at(i).getDOP().at(j) == ' ' && j == 4) {
                idx2 = j + 1;
            }
            if (content.at(i).getDOP().at(j) == ' ' && j != 4) {
                idx1 = j;
                month = content.at(i).getDOP().substr(idx2, idx1 - idx2);
            }
        }

        string year; // Finds year
        for (int f = 0; f < content.at(i).getDOP().size(); f++) {
            if (content.at(i).getDOP().at(f) == ' ') {
                year = content.at(i).getDOP().substr(0, f);
                break;
            }
        }

        string day; // Finds day
        for (int a = content.at(i).getDOP().size() - 1; a > 0; a--) {
            if (content.at(i).getDOP().at(a) == ' ') {
                day = content.at(i).getDOP().substr(a + 1, content.at(i).getDOP().size() - 1);
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

        cout << setw(7) << left << line << setw(titleSpacer + 2) << left << content.at(i).getTitle()
             << setw(authorSpacer + 3) << left << content.at(i).getAuthor() <<
             setw(dateSpacer + 12) << left << year + " " + month + " " + day << setw(typeSpacer + 3) << left
             << content.at(i).getBookType() <<
             setw(isbnSpacer + 2) << left << content.at(i).getISBN() << setw(pagesSpacer) << left
             << content.at(i).getNumPages() << endl;
        line++;
    }
}

vector<Book> Database::getRecords() {   // Return vector of books
    return content;
}

Database::~Database()   // Destructor
{
    readOut();
}


