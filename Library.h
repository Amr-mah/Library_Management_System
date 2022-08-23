#ifndef Library_H
#define Library_H
#include <string>
#include <vector>
#include "Book.h"
#include <iostream>
using namespace std;

class Library {
private:
    string name;
    vector<Book> v;

public:
    Library();
    string getName();
    void setName(string name);
    void openLibrary();
    void selectionMenu();
    void selectionInput();
    void addBook();
    void removeBook();
    void editBook();
    void searchBook();
    void viewAllBooks();
    void closeLibrary();

};


#endif //Library_H
