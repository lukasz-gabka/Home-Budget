#include <iostream>
#include <cstdlib>
#include "BudgetManager.h"

using namespace std;

int BudgetManager::getLoggedInUserId() {
    return userManager.getLoggedInUserId();
}

char BudgetManager::chooseOptionFromMainMenu() {
    char choice;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::getChar();

    return choice;
}

char BudgetManager::chooseOptionFromUserMenu() {
    char choice;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::getChar();

    return choice;
}

void BudgetManager::registerUser() {
    userManager.registerUser();
}

void BudgetManager::logInUser() {
    userManager.logInUser();
    if(userManager.isUserLoggedIn()) {
        operationManager = new OperationManager(userManager.getLoggedInUserId());
    }
}

void BudgetManager::logOutUser() {
    userManager.logOutUser();
    delete operationManager;
    operationManager = NULL;
}

void BudgetManager::changePassword() {
    userManager.changePassword();
}

void BudgetManager::addIncome() {
    operationManager->addIncome();
}

void BudgetManager::addExpense() {
    operationManager->addExpense();
}

void BudgetManager::displayBalance() {
    operationManager->getDataForBalance(balanceChoice);
}

void BudgetManager::setBalanceChoice(char balanceChoice) {
    this -> balanceChoice = balanceChoice;
}
