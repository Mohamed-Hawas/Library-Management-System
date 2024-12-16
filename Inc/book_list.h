#ifndef BOOK_LIST_H_
#define BOOK_LIST_H_

#include <iostream>
#include <string>
#include "user.h"
#include "book.h"

using namespace std;

class BookList {
private:
    Book*books;
    int capacity;
    int booksCount;
 public:
 BookList();
 BookList(int );
 void addBook(const Book& ); // at the end of the array.
 Book& searchBook(string);
 Book& searchBook(int );
 void deleteBook(int ); //delete a book
 int getCapacity();
 Book getTheHighestRatedBook();
 void getBooksForUser(const User &); // get all books of this author
 Book& operator[] (int );
 friend ostream&operator<<(ostream &,const BookList & ); //to display all books
 ~BookList();
 
};

#endif /*BOOK_LIST_H_*/