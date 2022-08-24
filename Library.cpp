#include "Library.h"

Library::Library() {
    name = "none";
}

void Library::openLibrary() {
    cout << "Enter the name of the Library:";
    getline(cin, name);
    createFile(name);

}

void Library::createFile(string name) {
    fstream file;
    file.open(name + ".txt");
    if (!file)  {
        ofstream ofile;
        ofile.open(name + ".txt");
        ofile.close();
    }
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
    while(cin.fail()) {
        cout << "Error\n";
        cout << "Enter a valid option:";
        cin.clear();
        cin.ignore(256,'\n');
        cin >> selection;
    }
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
    while(cin.fail()) {
        cout << "Error\n";
        cout << "Enter a valid cost:";
        cin.clear();
        cin.ignore(256,'\n');
        cin >> cost;
    }

    cout << "\tBook added successfully\n\n" << endl;

    fstream file;
    file.open(name + ".txt", fstream::app);
    file << isbn << endl << title << endl << author << endl << cost << endl << endl;

}

void Library::removeBook() {
    string isbn;
    cout << "Enter the ISBN of the book to remove:";
    getline(cin >> ws,isbn);

    int newLineCount = 0;
    string line;
    ifstream file;
    file.open(name + ".txt", fstream::app);
    ofstream temp;
    temp.open("temp.txt");
    char c;
    bool isFound;
    bool exists;

    while (getline(file,line)) {
        if (line == isbn) {
            isFound = true;
            exists = true;
            cout << "Book was successfully removed" << endl;
        }

        if (line != isbn && !isFound)
            temp << line << endl;

        if (line != isbn && isFound) {
            while (file.get(c)) {
                if (c == '\n')
                    newLineCount++;
                if (newLineCount == 3)
                    isFound = false;
                if (!isFound)
                    break;
            }
        }
    }
    temp.close();
    file.close();
    string fileName = name + ".txt";
    const char* p = fileName.c_str();
    remove(p);
    rename("temp.txt", p);

    if (!exists) {
        cout << "ISBN not found in library" << endl;
    }
}

void Library::editBook() {
    string isbn, title, author;
    float cost;
    char choice;
    cout << "\nEnter the isbn of the book to edit:";
    getline(cin >> ws, isbn);

    int newLineCount1 = 0;
    int newLineCount2 = 0;
    string line;
    ifstream file;
    file.open(name + ".txt", fstream::app);
    ofstream temp;
    temp.open("temp.txt");
    char c;
    bool finished = false;
    bool isFound = false;
    bool exists;

    while (getline(file, line)) {
        if (line == isbn) {
            exists = true;
            cout << "Book found!" << endl;

            cout << "Book details:\n\n";
            char myChar;
            while (file && !finished) {
                myChar = file.get();
                cout << myChar;
                if (myChar == '\n') {
                    newLineCount1++;
                }
                if (newLineCount1 == 3)
                    finished = true;
            }
            cout << "Would you like to edit?(Y/N):";
            cin >> choice;
            break;
        }
    }

    if (choice == 'Y' || choice == 'y') {
        ifstream file;
        file.open(name + ".txt", fstream::app);
        while (getline(file,line)) {
            if (line == isbn) {
                isFound = true;
            }

            if (line != isbn && !isFound)
                temp << line << endl;

            if (line != isbn && isFound) {
                while (file.get(c)) {
                    if (c == '\n')
                        newLineCount2++;
                    if (newLineCount2 == 3)
                        isFound = false;
                    if (!isFound)
                        break;
                }
            }
        }
        cout << "Enter the ISBN number of the book:";
        getline(cin >> ws,isbn);
        cout << "Enter the title of the book:";
        getline(cin,title);
        cout << "Enter the author of the book:";
        getline(cin,author);
        cout << "Enter the cost of the book:";
        cin >> cost;
        while(cin.fail()) {
            cout << "Error\n";
            cout << "Enter a valid cost:";
            cin.clear();
            cin.ignore(256,'\n');
            cin >> cost;
        }

    }

    if (exists) {
        temp.close();
        file.close();
        string fileName = name + ".txt";
        const char* p = fileName.c_str();
        remove(p);
        rename("temp.txt", p);
        ofstream fs;
        fs.open(name + ".txt", fstream::app);
        fs << isbn << endl << title << endl << author << endl << cost << endl << endl;
        fs.close();
    }

    if (!exists)
        cout << "ISBN not found" <<
        endl;
}

void Library::viewAllBooks() {
    cout << "Book details:\n\n";
    ifstream file;
    file.open(name + ".txt", fstream::app);
    if (file.is_open()) {
        char myChar;
        while (file) {
            myChar = file.get();
            cout << myChar;
        }
    }
}