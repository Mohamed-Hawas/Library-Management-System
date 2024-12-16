#include <iostream>
#include <string>
#include "../Inc/user.h"
#include "../Inc/book.h"
using namespace std;
User u ;
int Book::count = 0;
Book::Book() : id(0), title(""), isbn(""), category(""), averageRating(0.0)
{
}
Book::Book(string title_, string isbn_, string category_,User author_)
    : id(count++), title(title_), isbn(isbn_), category(category_), averageRating(0.0), author(author_)
{
}
Book::Book(const Book &book_)
    : title(book_.title),
      isbn(book_.isbn),
      id(book_.id),
      category(book_.category),
      averageRating(book_.averageRating),
      author(book_.author)
{
}

// Setters
void Book::setTitle(string title)
{
    this->title = title;
}

void Book::setIsbn(string isbn)
{
    this->isbn = isbn;
}

void Book::setId(int id)
{
    this->id = id; // Be cautious about modifying IDs; this is usually discouraged.
}

void Book::setCategory(string category)
{
    this->category = category;
}

void Book::setAuthor(const User &author)
{
    this->author = author;
}

// Getters
string Book::getTitle() const
{
    return title;
}

string Book::getIsbn() const
{
    return isbn;
}

int Book::getId() const
{
    return id;
}

string Book::getCategory() const
{
    return category;
}

User Book::getAuthor() const
{
    return author;
}

void Book::rateBook(double averageRating_)
{
    if (averageRating_ < 0.0 || averageRating_ > 5.0)
    {
        std::cout << "Invalid rating! Ratings should be between 0 and 5." << std::endl;
        return;
    }
    // Update the average rating (simplified approach; doesn't consider multiple ratings)
    averageRating = averageRating_;
}
double Book::getAverageRating() const
{
    return averageRating;
}
bool Book::operator==(const Book &book_)
{
    return (id == book_.id);
}
// Overloaded output operator
ostream &operator<<(ostream &out, const Book &book) {
    out << "Title: " << book.title << "\n"
        << "ISBN: " << book.isbn << "\n"
        << "ID: " << book.id << "\n"
        << "Category: " << book.category << "\n"
        << "Average Rating: " << book.averageRating << "\n"
        << "Author: " << book.author.getName() << std::endl; 
    return out;
}

// Overloaded input operator
istream &operator>>(istream &in, Book &book) {
    std::cout << "Enter book title: ";
    in >> ws; // To handle leading whitespace
    getline(in, book.title);

    std::cout << "Enter book ISBN: ";
    in >> book.isbn;

    std::cout << "Enter book category: ";
    in >> ws;
    getline(in, book.category);

    return in;
}
