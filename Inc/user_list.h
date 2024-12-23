#ifndef USER_LIST_H_
#define USER_LIST_H_

#include <iostream>
#include <string>
#include "user.h"

using namespace std;

class UserList
{
private:
        User *users;
        int capacity;
        int usersCount;

public:
        UserList();
        UserList(int);
        void addUser(User &);
        User &searchUser(string);
        User &searchUser(int);
        void deleteUser(int);
        friend ostream &operator<<(ostream &, const UserList &);
        ~UserList();
};

#endif /*USER_LIST_H_*/