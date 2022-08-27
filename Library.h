#ifndef Library_H
#define Library_H
#include <string>
#include <vector>
// #include "Book.h"
#include "Admin.h"
#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

class Library {
private:
    string name;

public:
    Library();
    void createFile(string name);
    void openLibrary();
    void loginMenu();
    void selectionMenu();
    void selectionInput();
    void addBook();
    void removeBook();
    void editBook();
    void viewAllBooks();

};


#endif //Library_H
