#ifndef BANK_H
#define BANK_H

#include <stdbool.h>

typedef struct {
    char account_number[20];
    double balance;
} Account;

typedef struct {
    Account* accounts[100]; // Array of account pointers
    int account_count;
} Bank;

typedef struct {
    bool (*deposit)(Account* account, double amount);
    bool (*withdraw)(Account* account, double amount);
} Transaction;

// Bank functions
Bank* create_bank();
bool create_account(Bank* bank, const char* account_number, double initial_balance);
Account* get_account(Bank* bank, const char* account_number);
bool deposit(Bank* bank, const char* account_number, double amount);
bool withdraw(Bank* bank, const char* account_number, double amount);

// Transaction functions
bool transaction_deposit(Account* account, double amount);
bool transaction_withdraw(Account* account, double amount);
Transaction* create_transaction();

#endif // BANK_H
