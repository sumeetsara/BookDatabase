#include <iostream>
#include "book.h"
#include "database.h"
#include "menu.h"

void run() { // Function runs the program based on if else statements ans user's decisions
    Database container;
    Menu interaction;
    while (true) {
        string replyToWelcome;
        interaction.menu();   // Welcome menu
        replyToWelcome = interaction.getReplyToWelcome(); // Displays menu options
        vector<Book> contents = container.getRecords();

        if (replyToWelcome == "0") {                                     // If user wants to display book records
            cout << "You have entered 'To View Book Records' " << endl << endl;
            container.displayBooks();
        } else if (replyToWelcome == "1") {                             // If user wants to create new book
            cout << "You have entered 'To Create New Book Records' " << endl << endl;
            string title = interaction.titleInfoForNew();               // Asks user for title
            string author = interaction.authorInfoForNew();             // Asks user for author

            string year = interaction.yearInfoForNew();                 // Asks user for year
            string month = interaction.monthInfoForNew();               // Asks user for month
            string day = interaction.dayInfoForNew();                   // Asks user for year
            string date = year + " " + month + " " + day;               // Concatenation

            string type = interaction.typeInfoForNew();                 // Asks user for type
            string isbn = interaction.isbnInfoForNew();                 // Asks user for isbn
            string pages = interaction.pagesInfoForNew();               // Asks user for pages

            interaction.outPutEdits(title, author, date, type, isbn, pages); // Shows user their new book
            container.addNew(title, author, date, type, isbn, pages);         // Adds the newly created book to database
            cout << endl;
            cout << "New entry created!" << endl;
        } else if (replyToWelcome == "2") {                       // If user wants to delete a record
            container.displayBooks();
            cout << endl;
            cout << "You have entered 'To Delete A Record enter' " << endl << endl;
            int number = interaction.bookRecordDeleteInfo(container.getRecords()); // Gets the index of the book to be deleted
            container.deleteOld(number - 1);                                 // Deletes record
            cout << endl;
            cout << "Book record deleted at line " << number << endl;
        } else if (replyToWelcome == "3") {                             // Edits record
            cout << "You have entered 'To Edit Existing Book Records' " << endl << endl;
            container.displayBooks();
            int field = interaction.topicInfoForEditing();                    // Asks user for field
            int lineNum = interaction.lineInfoForEditing(container.getRecords());    // Asks user for index
            string user = interaction.userInputForEditing(field);             // Gets input
            container.update(user, lineNum - 1, field - 1);                    // Updates record
            cout << endl;
            cout << "Book record edited!" << endl;
        } else if (replyToWelcome == "4") {                             // Sorts records depending on field
            cout << endl;
            cout << "You have entered 'To Sort Records' " << endl << endl;
            interaction.callSortOption(contents);                             // Sorts
        } else if (replyToWelcome == "5") {                             // If user wants to search
            cout << endl;
            cout << "You have entered 'To Search By' " << endl << endl;
            int road = interaction.askUserForSearchType();                    // Asks for a complex search or simple search
            if(road == 1) {                                             // Simple search
                vector<Book> output;
                interaction.callSimple(contents, output);
            } else {                                                    // Complex search
                vector<Book> results;
                vector<Book> temp;
                interaction.callComplex(contents, results, temp);
            }
        } else if (replyToWelcome == "Exit") {                          // Exits program
            break;
        }
    }
}

int main() {
    run();    // Function call
}
