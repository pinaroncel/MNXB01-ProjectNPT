// Account.cxx

#define RESET   "\033[0m"
#define RED     "\033[1m\033[31m"
#define GREEN   "\033[1m\033[32m"
#define YELLOW  "\033[1m\033[33m"
#define MAGENTA "\033[1m\033[35m"
#define CYAN    "\033[1m\033[36m"

#include <iostream>
#include "Account.h"

using std::cout;
using std::endl;

// Constructor function -> Creates an instance
Account::Account() {
    _balance = 0;
}

// Prints account balance
void Account::print() {
    cout << MAGENTA << "Your account balance is " << balance() << "." << RESET << endl;
};

// Deposits given arg to account
void Account::deposit(int depositAmount) {
    if (depositAmount < 0) {
        cout << CYAN << "You have entered a negative amount." << RESET << endl;
    } else {
        _balance += depositAmount;
        cout << CYAN << "Deposit of " << depositAmount << " confirmed."        << RESET << endl;
        cout << CYAN << "Your updated account balance is " << balance() << "." << RESET << endl;
    }
};

// Withdraws given arg from account
void Account::withdraw(int withdrawAmount) {
    if (withdrawAmount < 0) {
        cout << YELLOW << "You have entered a negative amount." << RESET << endl;
    } else if (withdrawAmount > balance()) {
            cout << YELLOW << "Your account balance is insufficient."                << RESET << endl;
            cout << YELLOW << "Your current account balance is " << balance() << "." << RESET << endl;
    } else {
        _balance -= withdrawAmount;
        cout << YELLOW << "Withdrawal of " << withdrawAmount << " confirmed."      << RESET << endl;
        cout << YELLOW << "Your remaining account balance is " << balance() << "." << RESET << endl;
    }

};
