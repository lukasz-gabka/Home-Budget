#ifndef OPERATIONMANAGER_H
#define OPERATIONMANAGER_H
#include <iostream>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include "Income.h"
#include "Expense.h"
#include "OperationFile.h"
#include "AuxiliaryMethods.h"


using namespace std;

class OperationManager {
    int LOGGED_IN_USER_ID;
    Income income;
    Expense expense;
    OperationFile operationFile;
    vector <Income> incomes;
    vector <Expense> expenses;

    Income addIncomeData();
    Expense addExpenseData();
    string getTodayDate();
    bool checkDate(string date);
    string getYearAndMonth();
    string getYear(string date);
    string getMonth(string date);
    int getDay(string date);
    bool checkDateFormat(string date);
    bool checkDateRange(string date);
    bool checkForLeapYear(int year);
    bool checkMonth(int month);
    bool checkDay(int day, int month, bool isLeapYear);
    double sortIncomesByDate(int firstDate, int secondDate);
    double sortExpensesByDate(int firstDate, int secondDate);
    bool checkAmount(string amount);
    string getDateRange(char balanceChoice);
    void checkFirstDate(string firstDateString);
    void checkSecondDate(string firstDateString, string secondDateString);
    void displayBalance(char balanceChoice, string firstDateString, string secondDateString);

public:
    OperationManager(int loggedInUserId)
        : LOGGED_IN_USER_ID(loggedInUserId) {
        incomes = operationFile.loadIncomesFromFile(LOGGED_IN_USER_ID);
        expenses = operationFile.loadExpensesFromFile(LOGGED_IN_USER_ID);
    };
    void addIncome();
    void addExpense();
    void getDataForBalance(char balanceChoice);

};

#endif
