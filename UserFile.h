#ifndef USERFILE_H
#define USERFILE_H
#include <iostream>
#include <vector>
#include "Markup.h"
#include "User.h"

using namespace std;

class UserFile {
public:
    void saveUserToFile(User user);
    vector <User> loadUsersFromFile();
    void changePassword(vector <User> users, int loggedInUserId);
};

#endif
