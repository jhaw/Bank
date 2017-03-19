#include "BankAccount.h"
#include "main.cpp"
#include <iostream>
#include <fstream>
#include <cstlib>
using namespace std;

BankAccount::BankAccount()
{

}
void BankAccount::deposit() //function for depositing money into accounts
{
    double depositAmnt;
	std::string a, b, c;
	std::cout << "How much would you like to deposit?" << std::endl;
	std::cin >> depositAmnt;
	file.open(acctNum + ".txt")
		file >> a >> b >> c >> currentBalance; //a, b, and c are fillers I only need the last part of the file which is the currentBalance
    currentBalance = currentBalance + depositAmnt;
		file << a << b << c << currentBalance; //putting them right back in with currentBalance updated
	file.close();
	std::cout << "Current Balance is $" << currentBalance << std::endl;
    numberOfTransactions ++; //increasing number of transactions
	transLog.open("transLog.txt", ios::app); // adding transaction to log at the end using ios::app to add to the end of file
	transLog << numberOfTransactions << "Account " << acctNum << " has deposited $" << depositAmnt << std::endl; //giving each line in translog file its own number and summary of transacion
	transLog.close();
}

void BankAccount::withdrawl() //function for withdrawing money from accounts
{
    double withdrawAmnt;
	std::string a, b, c;
	std::cout << "How much would you like to withdraw?" << std::endl;
	std::cin >> withdrawAmnt;
	file.open(acctNum + ".txt")
		file >> a >> b >> c >> currentBalance; //a, b, and c are fillers I only need the last part of the file which is the currentBalance
	currentBalance = currentBalance - withdrawAmnt;
		file << a << b << c << currentBalance; //putting them right back in with currentBalance updated
	file.close();
	std::cout << "Current Balance is $" << currentBalance << std::endl;
    numberOfTransactions++; //increasing number of transactions
	transLog.open("transLog.txt", ios::app); // adding transaction to log at the end using ios::app to add to the end of file
	transLog << numberOfTransactions << "Account " << acctNum << " has withdrawn $" << withdrawAmnt << std::endl;
	transLog.close();
}
void BankAccount::openAcct() //opening new accounts. really struggling how to write all this to one txt file
{
	ofstream file; //create file
    std::cout << "\nEnter your account 5 digit number: ";
	std::cin >> acctNum;
	file.open(acctNum + ".txt"); //makes file name based on the account number chosen
    std::cout << "\nEnter the last name for the account: ";
	std::cin >> lastName;
    std::cout << "\nEnter the first name for the account: ";
	std::cin >> firstName;
		file << acctNum << std::endl << firstname << std::endl << lastName << std::endl << currentBalance;
		//previous line writes to the file the account number, first name, last name, and currentBalance = 0.0
    std::cout << "\n\nAccount Created.";
	file.close();
    };
void BankAccount::createTransLog() //function for creating the transaction log
{
	std::ofstream transLog;
	transLog.open("transLog.txt"); //creates translog file
	transLog.close();

}
void BankAccount::writeCheck() //function for withdrawing money from accounts
{
	double checkAmnt;
	std::string a, b, c;
	std::cout << "How much would you like to wwrite the check for?" << std::endl;
	std::cin >> checkAmnt;
	file.open(acctNum + ".txt")
		file >> a >> b >> c >> currentBalance; //a, b, and c are fillers I only need the last part of the file which is the currentBalance
	currentBalance = currentBalance - checkAmnt;
		file << a << b << c << currentBalance; //putting them right back in with currentBalance updated
	file.close();
	std::cout << "
	std::cout << "Check has been written for $" << checkAmnt << std::endl;
	std::cout << "Current Balance is $" << currentBalance << std::endl;
	numberOfTransactions++; //increasing number of transactions
	transLog.open("transLog.txt", ios::app); // adding transaction to log at the end using ios::app to add to the end of file
	transLog << numberOfTransactions << "Account " << acctNum << " has written a check for $" << checkAmnt << std::endl;
	transLog.close();
}
void BankAccount::viewAcct()
{
	file.open(acctNum + ".txt");
	file >> acctNum >> lastName >> firstName >> currentBalance;
	std::cout << "Account Number: " << acctNum << std::endl << "Name: " << firstName << " " << lastName << std::endl
		<< "Current Balance: $" << currentBalance << std::endl;
	file.close();
}
