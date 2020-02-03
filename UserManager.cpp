#include <iostream>
#include "UserManager.h"

using namespace std;

int UserManager::getLoggedInUserId() {
    return loggedInUserId;
}

void UserManager::registerUser() {
    User user = getNewUserData();

    users.push_back(user);
    userFile.saveUserToFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

User UserManager::getNewUserData() {
    User user;

    user.setId(getNewUserId());
    do {
        cout << "Podaj login: ";
        user.setLogin(AuxiliaryMethods::getLine());
    } while(isLogin(user.getLogin()) == true);

    cout << "Podaj haslo: ";
    user.setPassword(AuxiliaryMethods::getLine());

    cout << "Podaj imie: ";
    user.setName(AuxiliaryMethods::convertFirstLetterToUppercaseAndOthersToLowercase(AuxiliaryMethods::getLine()));

    cout << "Podaj nazwisko: ";
    user.setSurname(AuxiliaryMethods::convertFirstLetterToUppercaseAndOthersToLowercase(AuxiliaryMethods::getLine()));

    return user;
}

int UserManager::getNewUserId() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager::isLogin(string login) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getLogin() == login) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

int UserManager::logInUser() {
    User user;
    string login = "", password = "";

    cout << endl << "Podaj login: ";
    login = AuxiliaryMethods::getLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end()) {
        if (itr -> getLogin() == login) {
            for (int attempt = 3; attempt > 0; attempt--) {
                cout << "Podaj haslo. Pozostalo prob: " << attempt << ": ";
                password = AuxiliaryMethods::getLine();
                if (itr -> getPassword() == password) {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    loggedInUserId = itr -> getId();
                    return loggedInUserId;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return 0;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");

    return 0;
}

bool UserManager::isUserLoggedIn() {
    if (loggedInUserId > 0) {
        return true;
    } else {
        return false;
    }
}

void UserManager::logOutUser() {
    loggedInUserId = 0;
}

void UserManager::changePassword() {
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    newPassword = AuxiliaryMethods::getLine();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
        if (itr -> getId() == loggedInUserId) {
            itr -> setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    userFile.changePassword(users, loggedInUserId);
}
