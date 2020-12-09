#include <stdio.h>
#include "Bank.h"
double bank_account[row][MAX_BANK_ACCOUNT] = {0};

// make deposit to the acount by acount number and number to deposit
void make_deposit_to_account(int account_number, double amount_to_deposit)
{
    int arr_account_number = account_number - 901;
    bank_account[1][arr_account_number] += amount_to_deposit;

    printf("Balance is:%0.2lf\n", bank_account[1][arr_account_number]);
}

// close acount by acount number
void close_account(int account_number)
{
    int arr_account_number = account_number - 901;
    bank_account[0][arr_account_number] = 0;
    bank_account[1][arr_account_number] = 0;
    printf("account : %d has been close!\n", account_number);
}

// add interest to acounts by giving the interest
void add_interest(double interest)
{
    double how_much_to_add;
    for (int i = 0; i < MAX_BANK_ACCOUNT; i++)
    {
        if (bank_account[0][i] == 1)
        {
            how_much_to_add = ((bank_account[1][i] * interest) / 100);
            bank_account[1][i] += how_much_to_add;
        }
    }
    printf("Add interest\n");
}

// give the use to withdraw from his account
void withdrawal_money_from_account(int account_number, double amount_to_withdrawal)
{
    int arr_account_number = account_number - 901;
    double new_amount = bank_account[1][arr_account_number] - amount_to_withdrawal;
    if (new_amount < 0)
        printf("The current amount of money in the bank isn`t inaf try another amount\n");
    else
    {
        bank_account[1][arr_account_number] = new_amount;
        printf("Your current balance is: %0.2lf\n", new_amount);
    }
}

//search for all acounts
void get_the_acount_number_and_balacne()
{
    int search_for_open_account = 0;
    for (int i = 0; i < MAX_BANK_ACCOUNT; i++)
    {
        if (bank_account[0][i] == 1)
        {
            printf("acount: %d balance: %0.2lf\n", (i + 901), bank_account[1][i]);
            search_for_open_account = 1;
        }
    }
    if (search_for_open_account == 0)
    {
        printf("There is no open accounts in the bank\n");
    }
}

//close all bank acounts

void close_application()
{

    for (int i = 0; i < MAX_BANK_ACCOUNT; i++)
    {
        if (bank_account[0][i] == 1)
        {
            bank_account[0][i] = 0;
            bank_account[1][i] = 0;
        }
    }
    printf("All acounts closed!\n");
}

// take a normal number make it with 2 dots
double make_amount_with_2_dots(double amount_to_change)
{
    amount_to_change = amount_to_change * 100;
    int number_to_change = amount_to_change;
    double temp = number_to_change;
    amount_to_change = temp / 100;
    return amount_to_change;
}

//open new acount and add first deposit
void open_new_account_and_make_first_deposit(double amount_to_deposit)
{
    if (amount_to_deposit < 0)
    {
        printf("You cant deposit a negetive number\n");
        return;
    }
    int i, free_account = -1;
    for (i = 0; i < MAX_BANK_ACCOUNT; i++)
    {
        if (bank_account[0][i] == 0)
        {
            free_account = i;
            break;
        }
    }
    if (free_account == -1)
    {
        printf("Sorry, all the bank accounts is occupied\n");
    }
    else
    {
        bank_account[0][free_account] = 1;
        bank_account[1][free_account] = amount_to_deposit;
        printf("Your account number is: %d\n", (free_account + 901));
    }
}

//check if acount is stil alive by the row number
int check_if_acount_is_close(int account_number)
{
    int arr_account_number = account_number - 901;
    if (bank_account[0][arr_account_number] == 1)
        return 1;
    else
        return 0;
}
double check_balance(int account_number)
{
    int arr_account_number = account_number - 901;
    return bank_account[1][arr_account_number];
}