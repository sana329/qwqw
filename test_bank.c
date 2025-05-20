#include <stdlib.h>
#include "bank.h"
#include <stdio.h>

int main() {
    Bank* bank = create_bank();
    create_account(bank, "12345", 1000.0);
    Account* account = get_account(bank, "12345");

    if (deposit(bank, "12345", 500.0)) {
        printf("Deposit successful. New balance: %.2f\n", account->balance);
    } else {
        printf("Deposit failed.\n");
    }

    if (withdraw(bank, "12345", 300.0)) {
        printf("Withdrawal successful. New balance: %.2f\n", account->balance);
    } else {
        printf("Withdrawal failed.\n");
    }

    if (!withdraw(bank, "12345", 2000.0)) {
        printf("Insufficient funds check passed. Balance: %.2f\n", account->balance);
    } else {
        printf("Insufficient funds check failed.\n");
    }

    if (!deposit(bank, "invalid", 100.0)) {
        printf("Invalid account deposit check passed.\n");
    } else {
        printf("Invalid account deposit check failed.\n");
    }

    if (!withdraw(bank, "invalid", 100.0)) {
        printf("Invalid account withdraw check passed.\n");
    } else {
        printf("Invalid account withdraw check failed.\n");
    }

    // Memory cleanup
    for (int i = 0; i < bank->account_count; i++) {
        free(bank->accounts[i]);
    }
    free(bank);

    return 0;
}
