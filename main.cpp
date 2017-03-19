#include <iostream>
#include "BankAccount.h"
#include "BankAccount.cpp"
#include <fstream>
main(){ 
	createTransLog(); //starts the transaction log
	do
    {
		std::cout << "######Main Menu######" << std::endl; //main menu
        std::cout << "1) Open new Account" << std::endl;
        std::cout << "2) Interact with existing account" << std::endl;
        std::cout << "Select an option: ";
        std::cin >> ans1;
        switch (ans1){ //switch for first menu.
            case 1:
            {
            openAcct();
            break;
            }
            case 2:
            {
            std::cout << "Enter the Account Number: " << std::endl;
            std::cin >> acctNum;
			open.file(acctNum + ".txt");
			if (file.fail()) 
				{
					std::cerr << "enter an account number that exists!" << std::endl;
					exit(1);
				}
			else
                {
				std::cout << "####ACCOUNT_FUNCTIONS####" //second menu
                std::cout << "1) Deposit into Account" << std::endl;
                std::cout << "2) Withdraw from account" << std::endl;
                std::cout << "3) Write a check" << std::endl;
                std::cout << "4) View account information" << std::endl;
                std::cout << "5) View transaction log" << std::endl;
                std::cout << "Select an option: ";
                std::cin >> ans1;
					switch (ans1) { //switch for second menu. did two menus to avoid multiple account number prompts
					
						case 1:
						{
							deposit();
							break;
						}

						case 2:
						{
							withdraw();
							break;
						}
					
						case 3:
						{
							writeCheck();
							break;
						}	
						case 4:
						{
							viewAcct();
							break;
						}
						case 5:
						{
							viewTransLog();
							break;
						}
				}
				}    
            else if(acctNum != acctNum) //checking account number
                {
                std::cout << "Incorrect account number please try again." << std::endl;
                }
            break;
            }   
            }
    std::cout << "Do you wish to continue? (Y/N)" << std::endl; //asking for continue
    std::cin >> ans;
    }while (ans == 'y'||ans =='Y') //cheching continue and allowing for lower case
}
