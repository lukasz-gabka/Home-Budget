#include <iostream>
#include "OperationFile.h"

using namespace std;

int OperationFile::getLastIncomeId() {
    return lastIncomeId;
}

int OperationFile::getLastExpenseId() {
    return lastExpenseId;
}

vector <Income> OperationFile::loadIncomesFromFile(int loggedInUserId) {
    CMarkup xml;
    string element = "", incomeIdElement = "0";
    Income income;
    vector <Income> incomes;

    if (xml.Load("Incomes.xml")) {
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem("Income")) {
            xml.IntoElem();
            xml.FindElem("IncomeId");
            incomeIdElement = xml.GetData();
            income.setIncomeId(atoi(incomeIdElement.c_str()));

            xml.FindElem("UserId");
            element = xml.GetData();
            if (loggedInUserId != atoi(element.c_str())) {
                xml.OutOfElem();
                continue;
            }
            income.setUserId(atoi(element.c_str()));

            xml.FindElem("Date");
            element = xml.GetData();
            income.setDate(element);
            income.setDateInt(AuxiliaryMethods::convertDateToInt(element));

            xml.FindElem("Item");
            element = xml.GetData();
            income.setItem(element);

            xml.FindElem("Amount");
            element = xml.GetData();
            income.setAmount(atof(element.c_str()));

            incomes.push_back(income);
            xml.OutOfElem();
        }
        xml.OutOfElem();
        lastIncomeId = atoi(incomeIdElement.c_str());
        return incomes;
    }
    return incomes;
}

bool OperationFile::saveIncomeToFile(Income income) {
    CMarkup xml;

    if(!xml.Load("Incomes.xml")) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("IncomeId", income.getIncomeId());
    xml.AddElem("UserId", income.getUserId());
    xml.AddElem("Date", income.getDate());
    xml.AddElem("Item", income.getItem());
    xml.AddElem("Amount", AuxiliaryMethods::convertDoubleToString(income.getAmount()));
    xml.OutOfElem();
    xml.OutOfElem();

    if (xml.Save("Incomes.xml")) {
        lastIncomeId++;
        return true;
    } else {
        return false;
    }
}

vector <Expense> OperationFile::loadExpensesFromFile(int loggedInUserId) {
    CMarkup xml;
    string element = "", expenseIdElement = "0";
    Expense expense;
    vector <Expense> expenses;

    if (xml.Load("Expenses.xml")) {
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem("Expense")) {
            xml.IntoElem();
            xml.FindElem("ExpenseId");
            expenseIdElement = xml.GetData();
            expense.setExpenseId(atoi(expenseIdElement.c_str()));

            xml.FindElem("UserId");
            element = xml.GetData();
            if (loggedInUserId != atoi(element.c_str())) {
                xml.OutOfElem();
                continue;
            }
            expense.setUserId(atoi(element.c_str()));

            xml.FindElem("Date");
            element = xml.GetData();
            expense.setDate(element);
            expense.setDateInt(AuxiliaryMethods::convertDateToInt(element));

            xml.FindElem("Item");
            element = xml.GetData();
            expense.setItem(element);

            xml.FindElem("Amount");
            element = xml.GetData();
            expense.setAmount(atof(element.c_str()));

            expenses.push_back(expense);
            xml.OutOfElem();
        }
        xml.OutOfElem();
        lastExpenseId = atoi(expenseIdElement.c_str());
        return expenses;
    }
    return expenses;
}

bool OperationFile::saveExpenseToFile(Expense expense) {
    CMarkup xml;

    if(!xml.Load("Expenses.xml")) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("ExpenseId", expense.getExpenseId());
    xml.AddElem("UserId", expense.getUserId());
    xml.AddElem("Date", expense.getDate());
    xml.AddElem("Item", expense.getItem());
    xml.AddElem("Amount", AuxiliaryMethods::convertDoubleToString(expense.getAmount()));
    xml.OutOfElem();
    xml.OutOfElem();

    if (xml.Save("Expenses.xml")) {
        lastExpenseId++;
        return true;
    } else {
        return false;
    }
}
