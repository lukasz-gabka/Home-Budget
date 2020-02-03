#include <iostream>
#include "AuxiliaryMethods.h"

using namespace std;

char AuxiliaryMethods::getChar() {
    char choice;
    string text = "";

    while (true) {
        getline(cin, text);

        if (text.length() == 1) {
            choice = text[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return choice;
}

string AuxiliaryMethods::getLine() {
    string text = "";
    getline(cin, text);
    return text;
}

string AuxiliaryMethods::convertFirstLetterToUppercaseAndOthersToLowercase(string text) {
    if (!text.empty()) {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

int AuxiliaryMethods::convertDateToInt(string date) {
    string dateToConvert = "";
    int dateInt;
    char dash = '-';
    int firstDashPosition = date.find_first_of(dash);
    int lastDashPosition = date.find_last_of(dash);

    dateToConvert = date.substr(0, firstDashPosition).c_str();
    dateToConvert += date.substr(firstDashPosition+1, lastDashPosition - firstDashPosition - 1).c_str();
    dateToConvert += date.substr(lastDashPosition+1, sizeof(date)).c_str();

    dateInt = atoi(dateToConvert.c_str());

    return dateInt;
}

string AuxiliaryMethods::convertDoubleToString(double number) {
    ostringstream numberConversion;
    numberConversion << number;
    return numberConversion.str();
}

string AuxiliaryMethods::convertCommaToDot(string amount) {
    string comma = ",", dot = ".";
    size_t commaPosition = amount.find(comma);

    if (commaPosition != string::npos) {
        amount = amount.replace(commaPosition, 1, dot);
    }
    return amount;
}

bool AuxiliaryMethods::sortIncomes (Income x, Income y) {
    return x.getDateInt() < y.getDateInt();
}

bool AuxiliaryMethods::sortExpenses (Expense x, Expense y) {
    return x.getDateInt() < y.getDateInt();
}

string AuxiliaryMethods::convertIntToString(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

bool AuxiliaryMethods::isSecondNumberBiggerOrEqual(int number1, int number2) {
    if (number1 <= number2)
        return true;
    return false;
}

bool AuxiliaryMethods::checkDecimals(string number) {
    int dotPosition, length, numberOfDecimals;
    char dot = '.';

    dotPosition = number.find(dot);

    if (dotPosition == string::npos)
        return true;

    length = number.length();
    numberOfDecimals = length - dotPosition - 1;

    if (numberOfDecimals <= 2)
        return true;

    return false;
}
