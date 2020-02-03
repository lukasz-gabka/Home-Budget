#include <iostream>
#include "Expense.h"

using namespace std;

void Expense::setExpenseId(int expenseId) {
    this -> expenseId = expenseId;
}

void Expense::setUserId(int userId) {
    this -> userId = userId;
}

void Expense::setDateInt(int dateInt) {
    this -> dateInt = dateInt;
}

void Expense::setDate(string date) {
    this -> date = date;
}

void Expense::setItem(string item) {
    this -> item = item;
}

void Expense::setAmount(double amount) {
    this -> amount = amount;
}

int Expense::getExpenseId() {
    return expenseId;
}

int Expense::getUserId() {
    return userId;
}

int Expense::getDateInt() {
    return dateInt;
}

string Expense::getDate() {
    return date;
}

string Expense::getItem() {
    return item;
}

double Expense::getAmount() {
    return amount;
}
