#include <iostream>
#include "UserFile.h"

using namespace std;

vector <User> UserFile::loadUsersFromFile() {
    CMarkup xml;
    string element;
    User user;
    vector <User> users;

    if (xml.Load("Users.xml")) {
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem("User")) {
            xml.IntoElem();

            xml.FindElem("Id");
            element = xml.GetData();
            user.setId(atoi(element.c_str()));

            xml.FindElem("Login");
            element = xml.GetData();
            user.setLogin(element);

            xml.FindElem("Password");
            element = xml.GetData();
            user.setPassword(element);

            xml.FindElem("Name");
            element = xml.GetData();
            user.setName(element);

            xml.FindElem("Surname");
            element = xml.GetData();
            user.setSurname(element);

            users.push_back(user);
            xml.OutOfElem();
        }
    }
    xml.OutOfElem();
    return users;
}

void UserFile::saveUserToFile(User user) {
    CMarkup xml;

    if(!xml.Load("Users.xml")) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Id", user.getId());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());
    xml.AddElem("Name", user.getName());
    xml.AddElem("Surname", user.getSurname());
    xml.OutOfElem();
    xml.OutOfElem();

    xml.Save("Users.xml");
}

void UserFile::changePassword(vector <User> users, int loggedInUserId) {
    CMarkup xml;
    string idFromXml;

    if (xml.Load("Users.xml")) {
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem("User")) {
            xml.IntoElem();
            xml.FindElem("Id");
            idFromXml = xml.GetData();
            if (loggedInUserId == atoi(idFromXml.c_str())) {
                xml.FindElem("Password");
                xml.SetData(users[loggedInUserId-1].getPassword().c_str());
                xml.OutOfElem();
                xml.OutOfElem();
                xml.OutOfElem();
                xml.Save("Users.xml");
                return;
            }
            xml.OutOfElem();
        }
    }
}
