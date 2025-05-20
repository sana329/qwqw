#include "bank.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Bank* create_bank() {
    Bank* bank = (Bank*)malloc(sizeof(Bank));
    if (bank) {
        bank->account_count = 0;
    }
    return bank;
}

bool create_account(Bank* bank, const char* account_number, double initial_balance) {
    if (bank->account_count >= 100) return false; // Max accounts reached
    if (get_account(bank, account_number)) return false; // Account exists

    Account* new_account = (Account*)malloc(sizeof(Account));
    if (!new_account) return false;

    strncpy(new_account->account_number, account_number, sizeof(new_account->account_number) - 1);
    new_account->account_number[sizeof(new_account->account_number) - 1] = '\0'; // Ensure null termination
    new_account->balance = initial_balance;

    bank->accounts[bank->account_count++] = new_account;
    return true;
}

Account* get_account(Bank* bank, const char* account_number) {
    for (int i = 0; i < bank->account_count; i++) {
        if (strcmp(bank->accounts[i]->account_number, account_number) == 0) {
            return bank->accounts[i];
        }
    }
    return NULL;
}

bool transaction_deposit(Account* account, double amount) {
    if (amount > 0) {
        account->balance += amount;
        return true;
    }
    return false;
}

bool transaction_withdraw(Account* account, double amount) {
    if (amount > 0 && account->balance >= amount) {
        account->balance -= amount;
        return true;
    }
    return false;
}

Transaction* create_transaction() {
    Transaction* transaction = (Transaction*)malloc(sizeof(Transaction));
    if (transaction) {
        transaction->deposit = transaction_deposit;
        transaction->withdraw = transaction_withdraw;
    }
    return transaction;
}

bool deposit(Bank* bank, const char* account_number, double amount) {
    Account* account = get_account(bank, account_number);
    if (account) {
        Transaction* transaction = create_transaction();
        bool result = transaction->deposit(account, amount);
        free(transaction);
        return result;
    }
    return false;
}

bool withdraw(Bank* bank, const char* account_number, double amount) {
    Account* account = get_account(bank, account_number);
    if (account) {
        Transaction* transaction = create_transaction();
        bool result = transaction->withdraw(account, amount);
        free(transaction);
        return result;
    }
    return false;
}
