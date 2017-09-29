/* 
 * File:   BankAccount.cpp
 * Author: jakeadicoff
 * 
 * Created on February 22, 2015, 7:15 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include "BankAccount.h"

using namespace std;

// default constructor
BankAccount::BankAccount() {
    firstN = "";
    lastN = "";
    accountNum = 0;
    balance = 0.0; 
    active = false;
    
}
// constructor w/ 4 arguments. active set to true when constructor is used
BankAccount::BankAccount(string firstN, string lastN, 
        int accountNum, double balance) {
    this->firstN = firstN;
    this->lastN = lastN;
    this->accountNum = accountNum;
    this->balance = balance;
    this->active = true;
}

// print values of all account variables
void BankAccount::printAccountInfo() {
    cout << endl;
    cout << "Name: "<< lastN << ", " << firstN << endl;
    cout << "Account Number: " << accountNum << endl;
    cout << "Balance: $" << balance << endl;
    if(active == true) {
        cout << "Active: Yes" << endl; // active bool tells if account active
    } else {
        cout << "Active: No" << endl;
    }
    cout << endl;
}

// deposit money 
void BankAccount::deposit(double amount) {
    if(amount < 0) { // deposit cant be positive
        cout << "Error: deposit amount cannot be negative" << endl;
    } else {
        this->balance += amount; //if deposit valid, its added to balance
    }
}

// withdraw money from balance
double BankAccount::withdraw(double amount) {
    if(amount < 0) { //check for non neg amount
        cout << "Error: withdrawal amount cannot be negative" << endl;
        return 0; // amount withdrawn = 0
    } else if (amount > balance) { // check for amount less than current balance
        cout << "Error: withdrawal amount exceeds your balance of $" 
                << getBalance() << endl;
        return 0;
    } else {
        this->balance -= amount; // if valid amount, subtract from balance
        return amount; //return withdrawn amount
    }
}

// close account
double BankAccount::closeAccount() {
    this->active = false; // make account inactive
    double amount = balance; // save "amount received" 
    this->balance = 0; // set balance to 0       
    return amount; // return "amount received" to main
}