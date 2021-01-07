#include <stdio.h>
#include "myBank.h"
int main()
{

    double amount_to_deposit = 0;
    double balance = 0;
    double amount_to_withdrawal = 0;
    double interest = 0;
    int accountNumber = 0;
    char cmd = ' ';
    do
    {

        // choose command
        printf("\n\nChoose one of this options: \nO = Open Account and make first deposit \nB = Check my balance \nD = Make new Deposit \nW = Make new withdraw \nC = Close my account /nI = Make new Inrerase \nP = Print all acount and Deposit \nE = Close all accounts\n\n");
        //check if the command is good
        if (scanf(" %c", &cmd) != 1)
        {
            printf("You get rong command please try again");
        }
        switch (cmd)
        {

        // case O
        case 'O':

            printf("Enter the amount of the deposit\n");
            if (scanf("%lf", &amount_to_deposit) != 1 || amount_to_deposit < 0)
            {
                printf("Number only please try again\n");
            }
            else
            {
                amount_to_deposit = make_amount_with_2_dots(amount_to_deposit);
                open_new_account_and_make_first_deposit(amount_to_deposit);
            }
            break;

        // Case c
        case 'C':
            printf("Please enter the account number you like to close\n");
            if (scanf("%d", &accountNumber) != 1)
            {
                printf("Please enter numbers only!\n");
            }
            else
            {
                if (accountNumber < 901 || accountNumber > 950)
                    printf("You pot a wrong account number, please try again\n");
                else if (check_if_acount_is_close(accountNumber) == 0)
                    printf("This account number is already close\n");
                else
                {
                    close_account(accountNumber);
                }
            }
            break;

        //case B
        case 'B':
            printf("Enter acount number \n");
            if (scanf("%d", &accountNumber) != 1)
            {
                printf("Numbers only!\n");
            }
            else
            {
                if (accountNumber < 901 || accountNumber > 950)
                    printf("The acount number you choose is rong try again\n");
                else if (check_if_acount_is_close(accountNumber) == 0)
                    printf("The acount number you choose is close \n");
                else
                {
                    balance = check_balance(accountNumber);
                    printf("Your balance is:%0.2lf\n", balance);
                }
            }
            break;
        //CASE I
        case 'I':
            printf("Please enter the amount of interesy you like to add\n");
            if (scanf("%lf", &interest) != 1)
            {
                printf("Please enter numbers only!\n");
            }
            else
            {
                add_interest(interest);
            }
            break;

            //CASE P
        case 'P':
            get_the_acount_number_and_balacne();
            break;

            //CASE E
        case 'E':
            close_application();
            break;
        default:
            printf("You type a wrong command, please try one of those: O,B,D,W,C,I,P,E\n");
            break;

            //case D
        case 'D':
            printf("Please enter your account number\n");
            if (scanf("%d", &accountNumber) != 1)
            {
                printf("Please enter numbers only!\n");
            }
            else
            {
                if (accountNumber < 901 || accountNumber > 950)
                    printf("You pot a wrong account number, try again\n");
                else if (check_if_acount_is_close(accountNumber) == 0)
                    printf("Error, the account number you ask about is close\n");
                else
                {
                    printf("Please enter the amount of deposit\n");
                    scanf("%lf", &amount_to_deposit);
                    if (amount_to_deposit < 0)
                        printf("You cant deposit a negetive amount");
                    else
                    {
                        amount_to_deposit = make_amount_with_2_dots(amount_to_deposit);
                        make_deposit_to_account(accountNumber, amount_to_deposit);
                    }
                }
            }
            break;

            // Case W
        case 'W':
            printf("Please enter your account number\n");
            if (scanf("%d", &accountNumber) != 1)
            {
                printf("Please enter numbers only!\n");
            }
            else
            {
                if (accountNumber < 901 || accountNumber > 950)
                    printf("You pot a wrong account number, try again\n");
                else if (check_if_acount_is_close(accountNumber) == 0)
                    printf("Error, the account number you ask about is close\n");
                else
                {
                    printf("Please enter the amount that you like to withdrawal\n");
                    if (scanf("%lf", &amount_to_withdrawal) != 1)
                    {
                        printf("Please enter numbers only!\n");
                    }
                    else
                    {
                        if (amount_to_withdrawal < 0)
                            printf("You cant withdrawal a negetive amount\n");
                        else
                        {
                            amount_to_withdrawal = make_amount_with_2_dots(amount_to_withdrawal);
                            withdrawal_money_from_account(accountNumber, amount_to_withdrawal);
                        }
                    }
                }
            }
            break;
        }

    } while (cmd != 'E');
    return 0;
}
