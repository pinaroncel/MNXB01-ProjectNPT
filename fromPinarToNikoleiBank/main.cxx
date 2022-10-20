// main.cxx

#define RESET   "\033[0m"
#define RED     "\033[1m\033[31m"
#define GREEN   "\033[1m\033[32m"
#define YELLOW  "\033[1m\033[33m"
#define MAGENTA "\033[1m\033[35m"
#define CYAN    "\033[1m\033[36m"

#include <chrono>
#include <iostream>
#include <string>
#include <thread>
#include "Account.h"

using std::cin;
using std::cout;
using std::endl;
using std::numeric_limits;
using std::streamsize;
using namespace std::chrono;
using namespace std::this_thread;

void welcome() {
    cout << endl;
    cout << GREEN << "--------------------------------" << RESET << endl;
    cout << GREEN << "  Welcome to the Bank of Einar  " << RESET << endl;
    cout << GREEN << "--------------------------------" << RESET << endl;
    cout << endl;
    sleep_for(300ms);
};

void menu() {
    cout << GREEN   << "--------------------------------" << RESET << endl;
    cout << MAGENTA << "1. Show my account balance"       << RESET << endl;
    cout << CYAN    << "2. Deposit into my account"       << RESET << endl;
    cout << YELLOW  << "3. Withdraw from my account"      << RESET << endl;
    cout << RED     << "4. Quit"                          << RESET << endl;
    cout << GREEN   << "--------------------------------" << RESET << endl;
    cout << endl;
    sleep_for(300ms);
};

void menu1(Account& account) {
    account.print();
    sleep_for(300ms);
};

void menu2(Account& account, int& depositAmount) {
    account.deposit(depositAmount);
    sleep_for(300ms);
};

void menu3(Account& account, int& withdrawAmount) {
    account.withdraw(withdrawAmount);
    sleep_for(300ms);
};

void menu4(bool& quit) {
    cout << RED << "Thank you for visiting Bank of Einar." << RESET << endl;
    sleep_for(300ms);
    quit = true;
};

void menuX() {
    cout << GREEN << "Please pick one of the available options in the menu." << RESET << endl;
    sleep_for(300ms);
};

int main() {

    Account account;
    bool quit = false;

    while (!quit) {

        welcome();
        menu();

        int choice;
        cin >> choice;

        if (choice == 1) {
            menu1(account);
        } else if (choice == 2) {
            int depositAmount;
            cout << CYAN << "Enter deposit amount:" << RESET << endl;
            cin >> depositAmount;
            menu2(account, depositAmount);
        } else if (choice == 3) {
            int withdrawAmount;
            cout << YELLOW << "Enter withdraw amount:" << RESET << endl;
            cin >> withdrawAmount;
            menu3(account, withdrawAmount);
        } else if (choice == 4) {
            menu4(quit);
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            menuX();
        }
    };

    return 0;
};
