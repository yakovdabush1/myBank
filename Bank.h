#ifndef _MYBANK_
#define _MYBANK_
#define MAX_BANK_ACCOUNT 50
#define row 2
extern double bank_account[row][MAX_BANK_ACCOUNT];

void add_interest(double interest);
void get_the_acount_number_and_balacne();
void close_application();
double make_amount_with_2_dots(double to_change_amount);
void open_new_account_and_make_first_deposit(double amount_to_deposit);
double check_balance(int accountNumber);
int check_if_acount_is_close(int accountNumber);
void make_deposit_to_account(int accountNumber, double amount_to_deposit);
void withdrawal_money_from_account(int accountNumber, double amount_to_withdrawal);
void close_account(int accountNumber);

#endif