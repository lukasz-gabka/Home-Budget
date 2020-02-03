#include <iostream>
#include "OperationManager.h"

using namespace std;

void OperationManager::addIncome() {
    Income income;

    system("cls");
    cout << " >>> DODAWANIE PRZYCHODU <<<" << endl << endl;
    income = addIncomeData();

    incomes.push_back(income);
    if(operationFile.saveIncomeToFile(income))
        cout << "Przychod zostal dodany" << endl;
    else
        cout << "Blad. Nie udalo sie dodac przychodu do pliku" << endl;
    system("pause");
}

Income OperationManager::addIncomeData() {
    Income income;
    string date, item, amount;
    int dateInt;
    char choice;

    income.setIncomeId(operationFile.getLastIncomeId()+1);
    income.setUserId(LOGGED_IN_USER_ID);

    while (true) {
        cout << "Czy przychod dotyczy dnia dzisiejszego? <t/n>: ";
        choice = AuxiliaryMethods::getChar();
        if (choice == 't') {
            date = getTodayDate();
            break;
        } else if (choice == 'n') {
            cout << "Podaj date przychodu(w formacie rrrr-mm-dd): ";
            date = AuxiliaryMethods::getLine();
            while (!checkDate(date)) {
                cout << endl << "Wprowadzona data jest niepoprawna. Wpisz date ponownie: ";
                date = AuxiliaryMethods::getLine();
            }
            break;
        }
    }
    dateInt = AuxiliaryMethods::convertDateToInt(date);

    cout << "Podaj czego dotyczy przychod: ";
    item = AuxiliaryMethods::getLine();

    cout << "Podaj kwote przychodu(w zl): ";
    amount = AuxiliaryMethods::getLine();
    while (!checkAmount(amount)) {
        cout << "Niepoprawna wartosc. Wpisz kwote przychodu ponownie: ";
        amount = AuxiliaryMethods::getLine();
    }
    amount = AuxiliaryMethods::convertCommaToDot(amount);

    income.setDate(date);
    income.setDateInt(dateInt);
    income.setItem(item);
    income.setAmount(atof(amount.c_str()));

    return income;
}

void OperationManager::addExpense() {
    Expense expense;

    system("cls");
    cout << " >>> DODAWANIE WYDATKU <<<" << endl << endl;
    expense = addExpenseData();

    expenses.push_back(expense);
    if(operationFile.saveExpenseToFile(expense))
        cout << "Wydatek zostal dodany" << endl;
    else
        cout << "Blad. Nie udalo sie dodac wydatku do pliku" << endl;
    system("pause");
}

bool OperationManager::checkAmount(string amount) {
    char comma = ',', dot = '.';
    size_t firstCommaPosition, lastCommaPosition, firstDotPosition, lastDotPosition, forbiddenCharacterPosition;

    firstCommaPosition = amount.find_first_of(comma);
    lastCommaPosition = amount.find_last_of(comma);
    firstDotPosition = amount.find_first_of(dot);
    lastDotPosition = amount.find_last_of(dot);
    forbiddenCharacterPosition = amount.find_first_not_of("0123456789.,");

    if (firstCommaPosition != lastCommaPosition || firstDotPosition != lastDotPosition || forbiddenCharacterPosition != string::npos
            || (firstCommaPosition != string::npos && firstDotPosition != string::npos))
        return false;
    else if (!AuxiliaryMethods::checkDecimals(amount))
        return false;

    return true;
}

Expense OperationManager::addExpenseData() {
    Expense expense;
    string date, item, amount;
    int dateInt;
    char choice;

    expense.setExpenseId(operationFile.getLastExpenseId()+1);
    expense.setUserId(LOGGED_IN_USER_ID);

    while (true) {
        cout << "Czy wydatek dotyczy dnia dzisiejszego? <t/n>: ";
        choice = AuxiliaryMethods::getChar();
        if (choice == 't') {
            date = getTodayDate();
            break;
        } else if (choice == 'n') {
            cout << "Podaj date wydatku(w formacie rrrr-mm-dd): ";
            date = AuxiliaryMethods::getLine();
            while (!checkDate(date)) {
                cout << endl << "Wprowadzona data jest niepoprawna. Wpisz date ponownie: ";
                date = AuxiliaryMethods::getLine();
            }
            break;
        }
    }
    dateInt = AuxiliaryMethods::convertDateToInt(date);

    cout << "Podaj czego dotyczy wydatek: ";
    item = AuxiliaryMethods::getLine();

    cout << "Podaj kwote wydatku(w zl): ";
    amount = AuxiliaryMethods::getLine();
    while (!checkAmount(amount)) {
        cout << endl << "Niepoprawna wartosc. Wpisz kwote wydatku ponownie: ";
        amount = AuxiliaryMethods::getLine();
    }
    amount = AuxiliaryMethods::convertCommaToDot(amount);

    expense.setDate(date);
    expense.setDateInt(dateInt);
    expense.setItem(item);
    expense.setAmount(atof(amount.c_str()));

    return expense;
}

bool OperationManager::checkDate(string date) {
    string dateTemp = date;
    int year, month, day;
    bool isLeapYear;

    if (date.size()!= 10)
        return false;

    year = atoi(getYear(dateTemp).c_str());
    month = atoi(getMonth(dateTemp).c_str());
    day = getDay(dateTemp);

    isLeapYear = checkForLeapYear(year);

    if (!checkDateFormat(date) || !checkDateRange(date) || !checkMonth(month) || !checkDay(day, month, isLeapYear))
        return false;

    return true;
}

bool OperationManager::checkDateFormat(string date) {
    int firstDashPosition = 4, lastDashPosition = 7;
    char dash = '-';

    for (int i = 0; i < date.size(); i++) {
        if (i == firstDashPosition || i == lastDashPosition) {
            if (date[i] == dash)
                continue;
            else
                return false;
        }
        if(date[i] < 48 || date[i] > 57)
            return false;
    }

    return true;
}

bool OperationManager::checkDateRange(string date) {
    int earliestDate = 20000101;
    string dateString = getYearAndMonth();
    int latestDate = AuxiliaryMethods::convertDateToInt(dateString + "-31");
    int dateInt = AuxiliaryMethods::convertDateToInt(date);

    if (dateInt >= earliestDate && dateInt <= latestDate)
        return true;
    return false;
}

bool OperationManager::checkForLeapYear(int year) {
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
        return true;
    return false;
}

bool OperationManager::checkMonth(int month) {
    if (month < 1 || month > 12)
        return false;
    return true;
}

bool OperationManager::checkDay(int day, int month, bool isLeapYear) {
    switch (month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (day < 1 || day > 31)
            return false;
        return true;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (day < 1 || day > 30)
            return false;
        return true;
        break;
    case 2:
        if ((day < 1 || day > 29) && isLeapYear == true)
            return false;
        else if ((day < 1 || day > 28) && isLeapYear == false)
            return false;
        return true;
        break;
    }
}

void OperationManager::getDataForBalance(char balanceChoice) {
    vector <Expense> expenseBalance;
    string dateRange, firstDateString, secondDateString;

    switch (balanceChoice) {
    case '3':
    case '4':
        dateRange = getDateRange(balanceChoice);
        firstDateString = dateRange.substr(0, 10);
        secondDateString = dateRange.substr(11, 10);
        break;
    case '5':
        cout << "Podaj date poczatkowa okresu (w formacie rrrr-mm-dd): ";
        firstDateString = AuxiliaryMethods::getLine();
        checkFirstDate(firstDateString);

        cout << "Podaj date koncowa okresu (w formacie rrrr-mm-dd): ";
        secondDateString = AuxiliaryMethods::getLine();
        checkSecondDate(firstDateString, secondDateString);
    }

    displayBalance(balanceChoice, firstDateString, secondDateString);
}

double OperationManager::sortIncomesByDate(int firstDate, int secondDate) {
    vector <Income> incomeBalance;
    vector <Income>::iterator itrIncome;
    int incomeDate;
    double incomeSum = 0;

    for (itrIncome = incomes.begin(); itrIncome != incomes.end(); ++itrIncome) {
        incomeDate = AuxiliaryMethods::convertDateToInt(itrIncome -> getDate());
        if (incomeDate >= firstDate && incomeDate <= secondDate)
            incomeBalance.push_back(*itrIncome);
    }

    sort(incomeBalance.begin(), incomeBalance.end(), AuxiliaryMethods::sortIncomes);

    for (int i = 0; i < incomeBalance.size(); i++) {
        cout << "Data: " << incomeBalance[i].getDate() << endl;
        cout << "Tytul: " << incomeBalance[i].getItem() << endl;
        cout << "Kwota: " << incomeBalance[i].getAmount() << " zl" << endl << endl;
        incomeSum += incomeBalance[i].getAmount();
    }
    return incomeSum;
}

double OperationManager::sortExpensesByDate(int firstDate, int secondDate) {
    vector <Expense> expenseBalance;
    vector <Expense>::iterator itrExpense;
    int expenseDate;
    double expenseSum = 0;

    for (itrExpense = expenses.begin(); itrExpense != expenses.end(); ++itrExpense) {
        expenseDate = AuxiliaryMethods::convertDateToInt(itrExpense -> getDate());
        if (expenseDate >= firstDate && expenseDate <= secondDate)
            expenseBalance.push_back(*itrExpense);
    }

    sort(expenseBalance.begin(), expenseBalance.end(), AuxiliaryMethods::sortExpenses);

    for (int i = 0; i < expenseBalance.size(); i++) {
        cout << "Data: " << expenseBalance[i].getDate() << endl;
        cout << "Tytul: " << expenseBalance[i].getItem() << endl;
        cout << "Kwota: " << expenseBalance[i].getAmount() << " zl" << endl << endl;
        expenseSum += expenseBalance[i].getAmount();
    }
    return expenseSum;
}

string OperationManager::getDateRange(char balanceChoice) {
    string todayDate, year, month, dateRange = "", firstDay = "01", lastDay = "31";
    int monthInt, yearInt;

    todayDate = getTodayDate();
    year = getYear(todayDate);
    month = getMonth(todayDate);

    if (balanceChoice == '4') {
        monthInt = atoi(month.c_str());

        if (monthInt == 1) {
            monthInt = 12;
            yearInt = atoi(year.c_str());
            yearInt -= 1;
            year = AuxiliaryMethods::convertIntToString(yearInt);
        } else
            monthInt -= 1;

        if (monthInt < 10)
            month = "0" + AuxiliaryMethods::convertIntToString(monthInt);
        else
            month = AuxiliaryMethods::convertIntToString(monthInt);
    }
    dateRange = year + "-" + month + "-" + firstDay + "-" + year + "-" + month + "-" + lastDay;

    return dateRange;
}

void OperationManager::checkFirstDate(string firstDateString) {
    while (!checkDate(firstDateString)) {
        cout << endl << "Wprowadzona data jest niepoprawna. Wpisz date ponownie: ";
        firstDateString = AuxiliaryMethods::getLine();
    }
}

void OperationManager::checkSecondDate(string firstDateString, string secondDateString) {
    int firstDate, secondDate;

    firstDate = AuxiliaryMethods::convertDateToInt(firstDateString);
    while (true) {
        while (!checkDate(secondDateString)) {
            cout << endl << "Wprowadzona data jest niepoprawna. Wpisz date ponownie: ";
            secondDateString = AuxiliaryMethods::getLine();
        }
        secondDate = AuxiliaryMethods::convertDateToInt(secondDateString);
        if (AuxiliaryMethods::isSecondNumberBiggerOrEqual(firstDate, secondDate))
            break;
        cout << endl << "Data koncowa nie moze byc mniejsza od poczatkowej. Wpisz date ponownie: ";
        secondDateString = AuxiliaryMethods::getLine();
    }
}

void OperationManager::displayBalance(char balanceChoice, string firstDateString, string secondDateString) {
    double balance = 0, incomeSum, expenseSum;
    int secondDate, firstDate;

    firstDate = AuxiliaryMethods::convertDateToInt(firstDateString);
    secondDate = AuxiliaryMethods::convertDateToInt(secondDateString);

    system("cls");
    switch (balanceChoice) {
    case '3':
        cout << " >>> BILANS Z OBECNEGO MIESIACA <<<" << endl;
        break;
    case '4':
        cout << " >>> BILANS Z POPRZEDNIEGO MIESIACA <<<" << endl;
        break;
    case '5':
        cout << " >>> BILANS Z OKRESU OD " << firstDateString << " DO " << secondDateString << " <<<" << endl;
        break;
    }
    cout << "------------------------------------" << endl << endl << endl;
    cout << "PRZYCHODY" << endl;
    cout << "------------------------------------" << endl;

    incomeSum = sortIncomesByDate(firstDate, secondDate);

    cout << endl << "Suma przychodow: " << incomeSum << " zl" << endl;
    cout << "------------------------------------" << endl << endl << endl;

    cout << "WYDATKI" << endl;
    cout << "------------------------------------" << endl;

    expenseSum = sortExpensesByDate(firstDate, secondDate);

    cout << endl << "Suma wydatkow: " << expenseSum << " zl" << endl;
    cout << "------------------------------------" << endl << endl << endl;

    balance = incomeSum - expenseSum;

    cout << "SALDO : " << balance << " zl" << endl;
    cout << "------------------------------------" << endl << endl;
    system("pause");
}

string OperationManager::getTodayDate() {
    time_t rawtime;
    struct tm * timeinfo;
    char buffer [80];
    time (&rawtime);
    timeinfo = localtime (&rawtime);

    strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);
    string date = buffer;

    return date;
}

string OperationManager::getYearAndMonth() {
    time_t rawtime;
    struct tm * timeinfo;
    char buffer [80];
    time (&rawtime);
    timeinfo = localtime (&rawtime);

    strftime(buffer, sizeof(buffer), "%Y-%m", timeinfo);
    string date = buffer;

    return date;
}

string OperationManager::getYear(string date) {
    string year = "";
    char dash = '-';
    int firstDashPosition = date.find_first_of(dash);

    year = date.substr(0, firstDashPosition).c_str();

    return year;
}

string OperationManager::getMonth(string date) {
    string month = "";
    char dash = '-';
    int firstDashPosition = date.find_first_of(dash);
    int lastDashPosition = date.find_last_of(dash);

    month = date.substr(firstDashPosition+1, lastDashPosition - firstDashPosition - 1);

    return month;
}

int OperationManager::getDay(string date) {
    string day = "";
    char dash = '-';
    int lastDashPosition = date.find_last_of(dash);

    day = date.substr(lastDashPosition+1, sizeof(date)).c_str();

    return atoi(day.c_str());
}
