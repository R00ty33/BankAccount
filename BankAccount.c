/** Nicholas Rudolph */
/** Bank Account     */
/** Feb 23, 2020     */

/** directives       */
#include <stdio.h> /** printf */
#include <stdlib.h> /** for generating random number */
#include <time.h>  /** seeding */

/** driver code */
int main() {
    srand((unsigned) time(NULL)); /** use current time as seed for random generator */
    /** Data Fields */
    int *paccountNumber1, *paccountNumber2, accountNumber1, accountNumber2; /** pointers paccountNumber1, paccountNumber2 of type int */
    float *pbalance1, *pbalance2, *pbalanceDiff, balance1, balance2, balanceDiff; /** pointers pbalance1, pbalance2 of type float */
    pbalance1 = &balance1; /** pbalance1 points to the address of balance1 of type int */
    pbalance2 = &balance2; 
    paccountNumber1 = &accountNumber1; /** paccountNumber1 points to the address of accountNumber1 of type int */
    paccountNumber2 = &accountNumber2;
    pbalanceDiff = &balanceDiff; /** used or caclulating difference in balance of function 7 (High Balance) */


    /** FUNCTIONS BELOW */

    /** New Accounts. When 1 is selected, it calls new_account() to create two accounts. Existing accounts will be overridden by this transaction. Account number is randomly picked between 55 and 59.
     * but must not duplicate another account number. Initial balance of each account is also randomly determined when an account is created. Its value must be between -100.00 and 999.99. */
    /* #1 */ void new_accounts(int *paccountNumber1, float *pbalance1, int *paccountNumber2, float *pbalance2) {

                /** generates accountNumber between 55-59 */
                    int randNum = (rand() % (59 - 55 + 1)) + 55; /** (upper - lower + 1) + lower */
                    *paccountNumber1 = randNum;

                while (1) {
                    randNum = (rand() % (59 - 55 + 1)) + 55; /** (upper - lower + 1) + lower */
                    *paccountNumber2 = randNum;
                    if (accountNumber1 != accountNumber2) {
                        break;
                    }
                    else {
                        continue;
                    }
                }
                
                /** generates balance between -100.00 - 999.99 */
                    float randNumberGen = (rand() % (99999 - (-10000) + 1) + -10000);
                    *pbalance1 = randNumberGen / 100.00;
                    randNumberGen = (rand() % (99999 - (-10000) + 1) + -10000);
                    *pbalance2 = randNumberGen / 100.00;

                printf("\n\n>>>> Two accounts created!\n");
    }

    /* #2 */ void summary(int act1, float b1, int act2, float b2) {
                printf("\n\n>>>> %d:   $%f", act1, b1); 
                printf("\n\n>>>> %d:   $%f", act2, b2);
    }

    /* #3 */ void withdraw(int act, float *b, float withdraw) {
                float oldBalance = *b;
                *b -= withdraw;
                printf("\n>>>> Account %d balance changed from $%f to $%f\n", act, oldBalance, *b);
    }

    /* #4 */ void deposit(int act, float *b, float deposit) {
                float oldBalance = *b;
                *b += deposit;
                printf("\n>>>> Account %d balance changed from $%f to $%f\n", act, oldBalance, *b);
    }

    /* #5 */ void transfer(int act1, float *b1, int act2, float *b2, float amount) {
                float oldAct1Bal = *b1;
                float oldAct2Bal = *b2;
                *b1 -= amount;
                *b2 += amount;
                printf("\n>>>> Account %d balance changed from $%f to $%f", act1, oldAct1Bal, *b1);
                printf("\n>>>> Account %d balance changed from $%f to %f", act2, oldAct2Bal, *b2);

    }
    /* #6 */ void exchange(int act1, float *b1, int act2, float *b2) {
                float oldAct1Bal = *b1;
                float oldAct2Bal = *b2;
                *b1 = *b2;
                *b2 = oldAct1Bal;
                printf("\n>>>> Account %d balance changed from $%f to $%f", act1, oldAct1Bal, *b1);
                printf("\n>>>> Account %d balance changed from $%f to $%f", act2, oldAct2Bal, *b2);

    }

    /* #7 */ float *high_balance(int *act1, float b1, int *act2, float b2, float *bDiff) {
                if ((b1 - 200) > b2) {
                    *bDiff = b1 - b2;
                    printf("\n>>>> Account %d ($%f) has balance of %f more than account %d ($%f)", *act1, b1, *bDiff, *act2, b2);
                }
                if ((b2 - 200) > b1) {
                    *bDiff = b2 - b1;
                    printf("\n>>>> Account %d ($%f) has balance of %f more than account %d ($%f)", *act2, b2, *bDiff, *act1, b1);
                }
                return bDiff;
    }

    /* #8 */ void reset(float *b1, float *b2) {
                *b1 = 0;
                *b2 = 0;
                printf("\n>>>> Balance of both accounts are reset to $0.00");
    }
    /* #9 */ void change(int *act1, int act2) {
                int randNum;
                int oldActNum = *act1;
                while (1) {
                        randNum = (rand() % (59 - 55 + 1)) + 55; /** (upper - lower + 1) + lower */
                        *act1 = randNum;
                        if (*act1 != act2 && *act1 != oldActNum) {
                            break;
                        }
                        else {
                            continue;
                        }
                    }

                printf("\n>>>> Account %d is now changed to %d", oldActNum, *act1);
    }
    /* menu */ void menu() {
        printf("\n:---------------------------------------\n: Main Menu\n:\n: 1 New Accounts\n: 2 All Accounts\n: 3 Withdraw\n: 4 Deposit\n: 5 Transfer Fund\n: 6 Exchange Balance\n: 7 High Balance\n: 8 Reset All Balance\n: 9 Change Account Number\n: 0 Exit\n:---------------------------------------\n");
        printf("--> Choose your transaction (1, 2,..., 9, or 0 to exit): ");
    }

    /**  FUNCTIONS END */

    int userInput = 1; /** record userInput with scanf */
    int userInput2 = 1;

    while (userInput != 0) {
        menu(); /** calls menu */
        scanf("%d", &userInput);
        if (userInput == 0) {
            printf("\n>>>> GOOD BYE!\n\n");
        }
        /** function 1 */
        if (userInput == 1) {
            new_accounts(paccountNumber1, pbalance1, paccountNumber2, pbalance2);
        }
        /** function 2 */
        if (userInput == 2) {
            summary(*paccountNumber1, *pbalance1, *paccountNumber2, *pbalance2);
        }
        /** function 3 */
        if (userInput == 3) {
            printf("\nEnter account to withdraw (%d or %d): ", *paccountNumber1, *paccountNumber2);
            scanf("%d", &userInput);
            if (userInput == *paccountNumber1) {
                printf("Enter amount to withdraw:   $");
                float userInputF;
                scanf("%f", &userInputF);
                withdraw(*paccountNumber1, pbalance1, userInputF);
                continue;
            }
            if (userInput == *paccountNumber2) {
                printf("Enter amount to withdraw:   $");
                float userInputF;
                scanf("%f", &userInputF);
                withdraw(*paccountNumber2, pbalance2, userInputF);
                continue;
            }
            else {
                printf("\n>>>> Account %d doesn't exist!", userInput);
                continue;
            }
        }
        /** function 4 */
        if (userInput == 4) {
            printf("\nEnter account to deposit (%d or %d): ", *paccountNumber1, *paccountNumber2);
            scanf("%d", &userInput);
            if (userInput == *paccountNumber1) {
                printf("Enter amount to deposit:   $");
                float userInputF;
                scanf("%f", &userInputF);
                deposit(*paccountNumber1, pbalance1, userInputF);
                continue;
            }
            if (userInput == *paccountNumber2) {
                printf("Enter amount to deposit:   $");
                float userInputF;
                scanf("%f", &userInputF);
                deposit(*paccountNumber2, pbalance2, userInputF);
                continue;
            }
            else {
                printf("\n>>>> Account %d doesn't exist!", userInput);
                continue;
            }
        }
        /** function 5 */
        if (userInput == 5) {
            printf("\nEnter 'FROM' account and 'TO' account seperated by a space: ");
            scanf("%d %d", &userInput, &userInput2);
            if (userInput == *paccountNumber1 && userInput2 == *paccountNumber2) {
                printf("Enter amount to transfer:    $");
                float userInputF;
                scanf("%f", &userInputF);
                transfer(*paccountNumber1, pbalance1, *paccountNumber2, pbalance2, userInputF);
                continue;
            }
            if (userInput == *paccountNumber2 && userInput2 == *paccountNumber1) {
                printf("Enter amount to transfer:    $");
                float userInputF;
                scanf("%f", &userInputF);
                transfer(*paccountNumber2, pbalance2, *paccountNumber1, pbalance1, userInputF);
                continue;

            }
            if (userInput == userInput2) {
                printf("\n>>>> Cannot transfer from and to the same account!\n");
                continue;
            }
            else {
                printf("\n>>>> Account %d doesn't exist!", userInput);   /** COULD GO WRONGLY */
                continue;
            }
        }
        /** function 6 */
        if (userInput == 6) {
            printf("\nAre you sure to exchange balance of account 58 and 59 (y/n)? ");
            char ch;
            while (getchar() != '\n')  /* skips rest of line */ ;
            while ((ch = getchar ()) == ' ') { /* skips blanks */ 
                scanf("%c", &ch);
            }
            if (ch == 'y' || ch == 'Y') {
                exchange(*paccountNumber1, pbalance1, *paccountNumber2, pbalance2);
                continue;
            }
        }
        /** function 7 */
        if (userInput == 7) {
            if (((*pbalance1 - 200) > *pbalance2) || (*pbalance2 - 200) > *pbalance1) {
                high_balance(paccountNumber1, *pbalance1, paccountNumber2, *pbalance2, pbalanceDiff);
                continue;
            }
            else {
                printf("\n>>>> No any account's balance is $200 or higher than the other's");
                continue;
            }
        }
        /** functuon 8 */
        if (userInput == 8) {
            printf("\nAre you sure to reset balance of both accounts (y/n)? ");
            char ch;
            while (getchar() != '\n')  /* skips rest of line */ ;
            while ((ch = getchar ()) == ' ') { /* skips blanks */ 
                scanf("%c", &ch);
            }
            if (ch == 'y' || ch == 'Y') {
                reset(pbalance1, pbalance2);
                continue;
            }
        }
        /** function 9 */
        if (userInput == 9) {
            printf("\nWhich account number to change, %d or %d? ", *paccountNumber1, *paccountNumber2);
            scanf("%d", &userInput);
            if (userInput == *paccountNumber1) {
                change(paccountNumber1, accountNumber2);
                continue;
            }
            if (userInput == *paccountNumber2) {
                change(paccountNumber2, accountNumber1);
                continue;
            }
            else {
                printf("\n>>>> Account %d doesn't exist", userInput);
                continue;
            }
        }
    }
} // end of main