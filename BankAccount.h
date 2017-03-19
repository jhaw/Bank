#pragma once
using namespace std;

class BankAccount
{
	double currentBalance = 0.0; //initializing balance
	int numberOfTransactions = 0; //initializing number of transactions
	char ans; 
	int ans1;
public:
	int acctNum;
	string lastName;
	string firstName;
	void openAcct();
	void deposit();
	void withdrawl();
	void writeCheck();
	void viewAcct();
	void viewTransLog();
	void createTransLog();
};

