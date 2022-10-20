// Account.h

#ifndef ACCOUNT_H
#define ACCOUNT_H

// Class declaration
class Account {

    // Private class members
    private:

        // Account balance
        int _balance;

    // Public class members
    public:

        // Constructor function -> Creates an instance
        Account();

        // Getter function -> Returns account balance
        int balance() {
            return _balance;
        };

        // Prints account balance
        void print();
        
        // Deposits given arg to account
        void deposit(int depositAmount);
        
        // Withdraws given arg from account
        void withdraw(int withdrawalAmount);

};

#endif // ACCOUNT_H
