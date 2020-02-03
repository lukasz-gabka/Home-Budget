#ifndef OPERATIONFILE_H
#define OPERATIONFILE_H
#include <iostream>
#include <vector>
#include "Markup.h"
#include "Income.h"
#include "Expense.h"
#include "AuxiliaryMethods.h"

using namespace std;

class OperationFile {
    int lastIncomeId;
    int lastExpenseId;

public:
    OperationFile() {
        lastIncomeId = 0;
        lastExpenseId = 0;
    }
    int getLastIncomeId();
    int getLastExpenseId();
    vector <Income> loadIncomesFromFile(int loggedInUserId);
    bool saveIncomeToFile(Income income);
    vector <Expense> loadExpensesFromFile(int loggedInUserId);
    bool saveExpenseToFile(Expense expense);
};

#endif
