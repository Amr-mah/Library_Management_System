#ifndef _BOOK_H
#define _BOOK_H
#include <string>
using namespace std;


class Book {
private:
    string isbn;
    string title;
    string author;
    float cost;

public:
    Book(string a, string b, string c, float e);
    Book();
    string getIsbn();
    string getTitle();
    string getAuthor();
    float getCost();
    void setIsbn(string isbn);
    void setTitle(string title);
    void setAuthor(string author);
    void setCost(float cost);
};


#endif //BOOK_H
