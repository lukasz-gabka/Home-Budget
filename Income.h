#ifndef INCOME_H
#define INCOME_H
#include <iostream>

using namespace std;

class Income {
    int incomeId, userId, dateInt;
    string date, item;
    double amount;

public:
    void setIncomeId(int incomeId);
    void setUserId(int userId);
    void setDateInt(int dateInt);
    void setDate(string date) ;
    void setItem(string item);
    void setAmount(double amount);

    int getIncomeId();
    int getUserId();
    int getDateInt();
    string getDate();
    string getItem();
    double getAmount();
};

#endif
