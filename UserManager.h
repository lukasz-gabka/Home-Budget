#ifndef USERMANAGER_H
#define USERMANAGER_H
#include <iostream>
#include <vector>
#include "User.h"
#include "UserFile.h"
#include "AuxiliaryMethods.h"

using namespace std;

class UserManager {
    User user;
    UserFile userFile;
    vector <User> users;
    int loggedInUserId;

    User getNewUserData();
    int getNewUserId();
    bool isLogin(string login);

public:
    UserManager(int loggedInUserId):loggedInUserId(loggedInUserId) {
        users = userFile.loadUsersFromFile();
    };
    int getLoggedInUserId();
    void registerUser();
    int logInUser();
    bool isUserLoggedIn();
    void logOutUser();
    void changePassword();
};

#endif
