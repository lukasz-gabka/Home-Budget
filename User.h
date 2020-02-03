#ifndef USER_H
#define USER_H
#include <iostream>

using namespace std;

class User {
    int id;
    string login, password, name, surname;

public:
    void setId(int id);
    void setLogin(string login);
    void setPassword(string password);
    void setName(string name);
    void setSurname(string surname);
    int getId();
    string getLogin();
    string getPassword();
    string getName();
    string getSurname();
};

#endif
