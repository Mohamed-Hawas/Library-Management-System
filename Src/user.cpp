#include <iostream>
#include <string>
#include "../Inc/user.h"
using namespace std;
int User::count = 0;
// Default constructor
User::User():id(0), name(""), age(0), password(""), email("")
{
}
// Parameterized constructor
User::User(string name_, int age_, string password_, string email_)
    : id(count++), name(name_), age(age_), password(password_), email(email_)
{
}
// Copy constructor
User::User(const User &user_)
{
    this->name = user_.name;
    this->id = count++;
    this->age = user_.age;
    this->password = user_.password;
    this->email = user_.email;
}
// Equality operator
bool User::operator==(const User &user_)
{
    if (this->id == user_.id)
        return 1;
    else
        return 0;
}
// Setters
void User::setName(string name_)
{
    this->name = name_;
}

void User::setPassword(string password_)
{
    this->password = password_;
}

void User::setEmail(string email_)
{
    this->email = email_;
}

void User::setAge(int age_)
{
    this->age = age_;
}

void User::setId(int id_)
{
    this->id = id_;
}

// Getters
string User::getName() const
{
    return name;
}

string User::getPassword() const
{
    return password;
}

string User::getEmail() const
{
    return email;
}

int User::getAge()
{
    return age;
}

int User::getId()
{
    return id;
}
// Display method
void User::Display()
{
    cout << "User details :" << endl;
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Email: " << email << endl;
    cout << "Password: " << password << endl;
}
// Overloaded << operator
ostream &operator<<(ostream &out, const User &user_)
{
    out << "Name : " << user_.name << endl;
    out << "Age : " << user_.age << endl;
    out << "ID : " << user_.id << endl;
    out << "Email : " << user_.email << endl;
    out << "Password : " << user_.password << endl;

    return out;
}
// Overloaded >> operator
istream &operator>>(istream &in, User &user_)
{
    cout << "Enter Name : ";
    in >> user_.name;
    cout << "Enter Age : ";
    in >> user_.age;
    cout << "Enter Email : ";
    in >> user_.email;
    cout << "Enter Password : ";
    in >> user_.password;

    return in;
}