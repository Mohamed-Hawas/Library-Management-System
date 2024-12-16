#include <iostream>
#include <string>
#include "../Inc/user.h"
#include "../Inc/user_list.h"
using namespace std;
// Default constructor
UserList::UserList():users(nullptr),capacity(0),usersCount(0)
{
}
// Parameterized constructor
UserList::UserList(int capacity_):users(new User[capacity_]),capacity(capacity_),usersCount(0)
{
}
// Add user to the list
void UserList::addUser(User &user_)
{
    if (usersCount < capacity) {
        users[usersCount] = user_; 
        usersCount++;
    } else {
        cout << "UserList is full. Cannot add more users." << endl;
    }
}

// Search for a user using name
User &UserList::searchUser(string name_)
{
    for (int i = 0; i < usersCount; i++)
    {
        if (users[i].getName() == name_)
        return users[i] ;
    }
}
// Search for a user using id
User &UserList::searchUser(int id_)
{
    for (int i = 0; i < usersCount; i++)
    {
        if (users[i].getId() == id_)
        return users[i] ;
    }
}
// Delete user form the list using id
void UserList::deleteUser(int id_)
{
    for (int i = 0; i < usersCount; i++)
    {
        if (users[i].getId() == id_)
        {
            for (int j = i; j < usersCount-1; j++)
            {
                users[j] = users[j+1];
            }
            usersCount-- ;
            cout << "Use with ID "<< id_ << "deleted" <<endl ;
            return ;
        }
    }
    cout <<"User with ID " << id_ << "not found" << endl ;
}
// Operator overloading to print
ostream &operator<<(ostream &out, const UserList &userlist_)
{
    cout <<"Users list details :" <<endl ;
    for (int i = 0; i < userlist_.usersCount-1; i++)
    {
        out << userlist_.users[i] << endl ;
    }
    return out ;
}
// Destructor
UserList::~UserList()
{
    delete [] users ;
}