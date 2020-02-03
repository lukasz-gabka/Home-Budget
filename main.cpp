#include <iostream>
#include "Markup.h"
#include "BudgetManager.h"

using namespace std;

int main() {
    BudgetManager budgetManager(0);
    char choice;
    while (true) {
        if (budgetManager.getLoggedInUserId() == 0) {
            choice = budgetManager.chooseOptionFromMainMenu();

            switch (choice) {
            case '1':
                budgetManager.registerUser();
                break;
            case '2':
                budgetManager.logInUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        } else {
            choice = budgetManager.chooseOptionFromUserMenu();

            switch (choice) {
            case '1':
                budgetManager.addIncome();
                break;
            case '2':
                budgetManager.addExpense();
                break;
            case '3':
                budgetManager.setBalanceChoice(choice);
                budgetManager.displayBalance();
                break;
            case '4':
                budgetManager.setBalanceChoice(choice);
                budgetManager.displayBalance();
                break;
            case '5':
                budgetManager.setBalanceChoice(choice);
                budgetManager.displayBalance();
                break;
            case '6':
                budgetManager.changePassword();
                break;
            case '7':
                budgetManager.logOutUser();
                break;
            }
        }
    }
}
