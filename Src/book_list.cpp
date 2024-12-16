#include <iostream>
#include <string>
#include "../Inc/book_list.h"
using namespace std;

BookList::BookList() : BookList(0)
{
    books = nullptr;
}
BookList::BookList(int capacity_) 
{
    books = new Book [20];
    booksCount = 0 ;
}
void BookList::addBook(const Book &book_)
{
    books[booksCount++] = book_;
}
Book &BookList::searchBook(string title_)
{
    for (int i = 0; i < booksCount - 1; i++)
    {
        if (books[i].getTitle() == title_)
        {
            return books[i];
        }
    }
    throw std::runtime_error("User not found with name: " + title_);
}
Book &BookList::searchBook(int id_)
{
    for (int i = 0; i < booksCount - 1; i++)
    {
        if (books[i].getId() == id_)
        {
            return books[i];
        }
    }
    throw std::runtime_error("Book not found"); // Handle book not found
}
void BookList::deleteBook(int id_)
{
    for (int i = 0; i < booksCount; ++i)
    {
        if (books[i].getId() == id_)
        {
            // Shift books to fill the gap
            for (int j = i; j < booksCount - 1; ++j)
            {
                books[j] = books[j + 1];
            }
            --booksCount;
            cout << "Book with ID " << id_ << " deleted." << endl;
            return;
        }
    }
    cout << "Book with ID " << id_ << " not found." << endl;
}
int BookList::getCapacity()
{
    return capacity;
}
Book BookList::getTheHighestRatedBook()
{
    if (booksCount == 0)
    {
        throw runtime_error("BookList is empty!");
    }
    Book highestRatedBook = books[0];
    for (int i = 1; i < booksCount; ++i)
    {
        if (books[i].getAverageRating() > highestRatedBook.getAverageRating())
        {
            highestRatedBook = books[i];
        }
    }
    return highestRatedBook;
}

void BookList::getBooksForUser(const User &user_)
{
    cout << "Books for user " << user_.getName() << ":" << endl;
    for (int i = 0; i < booksCount; i++)
    {
        if (books[i].getAuthor() == user_)
        {
            cout << books[i] << endl;
        }
    }
}
// Operator overloading
Book &BookList::operator[](int index)
{
    if (index < 0 || index > booksCount)
    {
        throw out_of_range("Index out of range");
    }
    return books[index];
}
// Operator overloading
ostream &operator<<(ostream &out, const BookList &bookList_)
{
    cout << "Book List :" << endl;
    for (int i = 0; i < bookList_.booksCount; i++)
    {
        out << bookList_.books[i] << endl;
    }
    return out;
}
// Destructor
BookList::~BookList()
{
    delete[] books;
}