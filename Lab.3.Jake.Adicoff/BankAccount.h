fffffffffff/* 
 * File:   BankAccount.h
 * Author: jakeadicoff
 *
 * Created on February 22, 2015, 7:15 PM
 */

#ifndef BANKACCOUNT_H
#define	BANKACCOUNT_H

#include <iostream>
#include <string>

using namespace std;

class BankAccount {
public:
    //default constructor and constructor
    BankAccount();
    BankAccount(string firstN, string lastN, int accountNum, double balance);
    // in line get balance function returns balance
    double getBalance() {return balance;} 
    // out of line functions defined in cpp
    double withdraw(double amount);
    double closeAccount();
    void deposit(double amount);
    void printAccountInfo();
    
private:
    // variables in class defined and private
    string firstN;
    string lastN;
    int accountNum;
    double balance;
    bool active;
};

#endif	/* BANKACCOUNT_H */

