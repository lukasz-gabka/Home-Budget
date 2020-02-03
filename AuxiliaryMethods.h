#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H
#include <iostream>
#include <sstream>
#include <algorithm>
#include <time.h>
#include "Income.h"
#include "Expense.h"

using namespace std;

class AuxiliaryMethods {
public:
    static char getChar();
    static string getLine();
    static string convertFirstLetterToUppercaseAndOthersToLowercase(string text);
    static int convertDateToInt(string date);
    static string convertDoubleToString(double number);
    static string convertCommaToDot(string amount);
    static bool sortIncomes(Income x, Income y);
    static bool sortExpenses(Expense x, Expense y);
    static string convertIntToString(int number);
    static bool isSecondNumberBiggerOrEqual(int number1, int number2);
    static bool checkDecimals(string number);
};

#endif
