#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H
#include <iostream>
#include "UserManager.h"
#include "OperationManager.h"
#include "AuxiliaryMethods.h"

using namespace std;

class BudgetManager {
    UserManager userManager;
    OperationManager *operationManager;
    char balanceChoice;

public:
    BudgetManager(int loggedInUserId)
        : userManager(loggedInUserId) {
        operationManager = NULL;
    };
    ~BudgetManager() {
        delete operationManager;
        operationManager = NULL;
    }
    int getLoggedInUserId();
    char chooseOptionFromMainMenu();
    char chooseOptionFromUserMenu();
    void registerUser();
    void logInUser();
    void logOutUser();
    void changePassword();
    void addIncome();
    void addExpense();
    void displayBalance();
    void setBalanceChoice(char balanceChoice);
};

#endif
