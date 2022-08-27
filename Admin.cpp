#include "Admin.h"

Admin::Admin() {
    username = "";
    password = "";
}

void Admin::Register(string fileName) {
    cout << "Enter a new username:";
    cin >> username;
    cout << "Enter a new password:";
    cin >> password;
    ofstream file;
    file.open(fileName + "-Admin.txt", fstream::app);
    file << username << endl << password << endl << endl;
    file.close();

}

bool Admin::isRegistered(string fileName) {
    cout << "Enter Username:";
    cin >> username;
    cout << "Enter Password:";
    cin >> password;
    string fullName = fileName + "-Admin.txt";
    ifstream file;
    file.open(fullName,fstream::app);

    string line;
    bool userFound = false;
    bool passFound = false;

    while (getline(file,line)) {
        if (line == username) {
            userFound = true;
        }
        if (line == password) {
            passFound = true;
        }
    }

    file.close();

    if (userFound && passFound) {
        cout << "User Found" << endl;
        return true;
    }
    else
        cout << "User was not found" << endl;
        return false;

}

void Admin::removeAdmin(string name, string pass, string fileName) {
    username = name;
    password = pass;

    ifstream file;
    file.open(fileName + "-Admin.txt", fstream::app);
    ofstream temp;
    temp.open("temp.txt");
    string line;
    int newLineCount = 0;
    bool isFound = false;

    while (getline(file, line)) {
        if (line == username) {
            isFound = true;
            cout << "Admin account was successfully removed" << endl;
        }
        if (line != username && line != password) {
            temp << line << endl;
        }
    }

    temp.close();
    file.close();
    string f = name + "-Admin.txt";
    const char* p = f.c_str();
    remove(p);
    rename("temp.txt", p);

    if (!isFound) {
        cout << "User not found" << endl;
    }
}
