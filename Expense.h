#ifndef EXPENSE_H
#define EXPENSE_H
#include <iostream>

using namespace std;

class Expense {
    int expenseId, userId, dateInt;
    string date, item;
    double amount;

public:
    void setExpenseId(int expenseId);
    void setUserId(int userId);
    void setDateInt(int dateInt);
    void setDate(string date);
    void setItem(string item);
    void setAmount(double amount);

    int getExpenseId();
    int getUserId();
    int getDateInt();
    string getDate();
    string getItem();
    double getAmount();
};

#endif
