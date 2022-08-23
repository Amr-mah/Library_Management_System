#include "Library.h"

Library::Library() {
    name = "none";
}

void Library::openLibrary() {
    cout << "Enter the name of the Library:";
    getline(cin, name);
}

void Library::selectionMenu() {
    cout << "----------Welcome to " << name << "----------\n\n";
    cout << "Eligible services for " << name << endl;
    cout << "\t1 - Add a book\n";
    cout << "\t2 - Remove a book\n";
    cout << "\t3 - Edit a book\n";
    cout << "\t4 - View all books\n";
    cout << "\t5 - Exit\n";
    cout << "Please enter your selection:";
}

void Library::selectionInput() {
    int selection;
    selectionMenu();
    cin >> selection;
    while(selection != 5) {
        switch(selection) {
            case 1:
                addBook();
                break;
            case 2:
                removeBook();
                break;
            case 3:
                editBook();
                break;
            case 4:
                viewAllBooks();
                break;
            default:
                cout << "\tInvalid selection" << endl;
        }
        selectionMenu();
        cin >> selection;
    }
    cout << "\tEnd of service for " << name << endl;
}

void Library::addBook() {
    string isbn,title,author;
    float cost;
    cout << "Enter the ISBN number of the book:";
    getline(cin >> ws,isbn);
    cout << "Enter the title of the book:";
    getline(cin,title);
    cout << "Enter the author of the book:";
    getline(cin,author);
    cout << "Enter the cost of the book:";
    cin >> cost;

    Book newBook(isbn,title,author,cost);

    cout << "\tBook added successfully\n\n" << endl;
    v.push_back(newBook);

}

void Library::removeBook() {
    string isbn;
    if (v.size() == 0) {
        cout << "There is no book to remove\n";
        return;
    }
    cout << "Enter the ISBN of the book to remove:";
    getline(cin >> ws,isbn);
    vector<Book>::iterator i = v.begin();
    while (i != v.end()) {
        if (i->getIsbn() == isbn) {
            cout << "Book removed: " << i->getTitle() << endl;
            v.erase(i);
            return;
        }
        i++;
    }
    cout << "ISBN not found in library" << endl;
}

void Library::editBook() {
    string isbn,title,author;
    float cost;
    char choice;
    if (v.size() == 0) {
        cout << "There is no book to edit" << endl;
        return;
    }
    cout << "\nEnter the isbn of the book to edit:";
    getline(cin >> ws,isbn);
    vector<Book>::iterator i = v.begin();
    while (i != v.end()) {
        if (i->getIsbn() == isbn) {
            cout << "Book found!\n";
            cout << "ISBN: " << i->getIsbn() << endl;
            cout << "Title: " << i->getTitle() << endl;
            cout << "Author: " << i->getAuthor() << endl;
            cout << "Cost: " << i->getCost() << endl;
            cout << "Do you want to edit?(y/n):";
            cin >> choice;
            if (choice == 'y' || choice == 'Y') {
                cout << "Enter ISBN:";
                getline(cin >> ws, isbn);
                cout << "Enter Title:";
                getline(cin, title);
                cout << "Enter Author:";
                getline(cin, author);
                cout << "Enter cost:";
                cin >> cost;
                i->setIsbn(isbn);
                i->setTitle(title);
                i->setAuthor(author);
                i->setCost(cost);
            }
            else if (choice == 'n' || choice == 'N')
                return;
            else {
                cout << "Invalid input" << endl;
            }
            return;
        }
        i++;
    }
    cout << "\nISBN not found in library" << endl;
}

void Library::viewAllBooks() {
    cout << "Book details:\n\n";
    vector<Book>::iterator i = v.begin();
    while (i != v.end()) {
        cout << "ISBN: " << i->getIsbn() << endl;
        cout << "Title: " << i->getTitle() << endl;
        cout << "Author: " << i->getAuthor() << endl;
        cout << "Cost: " << i->getCost() << endl << endl;
        i++;
    }
}