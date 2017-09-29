/* 
 * File:   main.cpp
 * Author: smajerci
 *
 * Created on February 19, 2015, 10:32 AM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include "BankAccount.h"

using namespace std;


int main(int argc, char** argv) {

    // create the account
    BankAccount account("Stephen", "Majercik", 1234, 100.0);
    account.printAccountInfo();
    cout << endl;
    

    
    // try to make a negative deposit and show that it is not allowed
    cout << "Depositing -$100.00" << endl;
    account.deposit(-100.00);
    cout << "Balance: $" << account.getBalance() << endl;
    cout << endl;
    
    // make a legal deposit
    cout << "Depositing $100.00" << endl;;
    account.deposit(100.00);
    cout << "Balance: $" << account.getBalance() << endl;
    cout << endl;
    
    // try to make a negative withdrawal and show that it is not allowed
    cout << "Withdrawing -$50.00" << endl;;
    double amountWithdrawn = account.withdraw(-50.00);
    cout << "Withdrawal Amount: $" << amountWithdrawn << endl;
    cout << "Balance: $" << account.getBalance() << endl;
    cout << endl;
    
    // try to make a withdrawal greater than the balance and show that 
    // it is not allowed
    cout << "Withdrawing $500.00" << endl;;
    amountWithdrawn = account.withdraw(500.00);
    cout << "Withdrawal Amount: $" << amountWithdrawn << endl;
    cout << "Balance: $" << account.getBalance() << endl;
    cout << endl;
    
    // make a legal withdrawal
    cout << "Withdrawing $5.00" << endl;;
    amountWithdrawn = account.withdraw(5.00);
    cout << "Withdrawal Amount: $" << amountWithdrawn << endl;
    cout << "Balance: $" << account.getBalance() << endl;
    cout << endl;
    
    // print the account information
    account.printAccountInfo();
    
    // close the account, show the amount received, and print out the 
    // account information
    double closingAmount = account.closeAccount();
    cout << "Account Closed" << endl << "Amount Received: $" << closingAmount <<       endl;
    account.printAccountInfo();
   
    return EXIT_SUCCESS;
}
