#ifndef ADMIN_H
#define ADMIN_H

#include <string>
#include <iostream>
#include <fstream>
using namespace std;


class Admin {
private:
    string username;
    string password;

public:
    Admin();
    void Register(string fileName);
    bool isRegistered(string fileName);
    void removeAdmin(string name, string pass, string fileName);
};


#endif //ADMIN_H
