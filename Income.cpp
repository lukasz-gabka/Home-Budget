#include <iostream>
#include "Income.h"

using namespace std;

void Income::setIncomeId(int incomeId) {
    this -> incomeId = incomeId;
}

void Income::setUserId(int userId) {
    this -> userId = userId;
}

void Income::setDateInt(int dateInt) {
    this -> dateInt = dateInt;
}

void Income::setDate(string date) {
    this -> date = date;
}

void Income::setItem(string item) {
    this -> item = item;
}

void Income::setAmount(double amount) {
    this -> amount = amount;
}

int Income::getIncomeId() {
    return incomeId;
}

int Income::getUserId() {
    return userId;
}

int Income::getDateInt() {
    return dateInt;
}

string Income::getDate() {
    return date;
}

string Income::getItem() {
    return item;
}

double Income::getAmount() {
    return amount;
}
