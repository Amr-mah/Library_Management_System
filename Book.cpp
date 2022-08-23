#include "Book.h"


Book::Book(string isbn, string title, string author, float cost) {
    this->isbn = isbn;
    this->title = title;
    this->author = author;
    this->cost = cost;
}

Book::Book() {
    isbn = "";
    title = "";
    author = "";
    cost = 0.0;
}

string Book::getIsbn() {
    return isbn;
}

string Book::getTitle() {
    return title;
}

string Book::getAuthor() {
    return author;
}

float Book::getCost() {
    return cost;
}

void Book::setIsbn(string isbn) {
    this->isbn = isbn;
}

void Book::setTitle(string title) {
    this->title = title;
}

void Book::setAuthor(string author) {
    this->author = author;
}

void Book::setCost(float cost) {
    this->cost = cost;
}
