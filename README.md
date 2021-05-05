"# BankAccount" 

Functions:
	New Account
		When 1 is selected, it calls new_account() to create two accounts. Existing accounts will be overridden by this transaction. At end, it prints a message as shown below to confirm both accounts are created.
		Account number is randomly picked between 55 and 59 but must not duplicate another account number.
		Initial balance of each account is also randomly determined when an account is created. Its value must between -100.00 and 999.99.  Hint: first get a random integer between -10000 and 99999, then, divide it by 100.0 so it has two decimal digits but still a random number
	All Accounts
		Whenever 2 is selected, it calls summary() to print each account's current information in the format as show below.
	Withdraw
		When 3 is selected, the program first asks which account to withdraw.
		Once a valid account number and amount to withdraw are ready, the program calls withdraw() by passing values of these two numbers plus the account's balance. Because the balance is going to be updated after withdraw, it must be passed by reference to the withdraw() function so the updated value is accessible to the program.
	Deposit
		When 4 is selected at any time, the program performs exactly the same as Withdraw except it calls deposit() function instead of withdraw()
	Transfer Funds
		When the selection is 5, the program transfers specified amount from one to the other account. It first asks to enter the source (or FROM) account and the destination (or TO) account, separated by at least one space.
		When all input data are identified, the program calls transfer() by passing values of these three numbers plus each account's balance. Because the balance of each account is going to be updated after transfer, they must be passed by reference to the transfer() function so the updated values are accessible to the program.
	Exchange Balance
		When the selection is 6, user wants the balance of each account to be exchanged. Because this is treated as a serious transaction, the program requires user to confirm 
		Since both balances are affected, they need to be passed to this function by reference so their updated values can be accessible to the program. This function will also print the exchange result with account numbers therefore, they only need to be passed by value.
	High Balance
		When the selection is 7, the program calls high_balance() to search if there is an account whose balance is $200 or higher than the other's. This is a special function that is different from all others of this program. It is required to return a pointer that points to the account which satisfies the search condition. Because of this, it requires to have both account numbers passed by reference such that the address (i.e., reference) of one of them can be returned.
	Reset All Balance
		When the selection is 8, the program requires user to confirm the request as in the exchange transaction. Once confirmed, it calls reset() to bring both balances down to zero.
	Change Account Number
		When the selection is 9, the program first asks which account to re-assign its account number. Note that both account numbers are included in the message prompt for user's convenience. Entering a non-existing account number will result an error message (not shown below) exactly the same as in deposit or withdraw or other transactions. 
		Once an account is identified, the program calls change() to re-assign it a new account number. Because the same rule of no duplicate account numbers applies here, this function needs to know the other account number, although it is not the target to change. As a result, the account that is going to change is passed by reference while the other is passed by value. This is handled by the program when the function is called, depending on which one is entered by user for a new account number. 