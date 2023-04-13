#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
#include "Header.h"
using namespace std;

/*  This program uses a class, member variables, and member functions to simulate a program that may be used at a banking institution.
    The client menu showcases the member functions that manipulate the account object that the user creates.
    The bank manager menu showcases the array of 10 bank accounts with randomly assigned account numbers and bank balances using a static class function  */

int main() 
{
    cout << "       Tyler's Bank\n     1413 Chester Ave\n  Chesterville 10913, CA\n      (562) 314 1592\n";
    for (int i = 0; i < 30; i++) {
        cout << "-";
        if (i == 29)
        {
            cout << "\n";
        }
    }
    bankAccount accountOne;

    //Main Menu
    int nav = 0;
    int nav2 = 0;
    int x = 1;
    cout << "\tMain Menu\n";
    for (int i = 0; i < 30; i++) {
        cout << "-";
        if (i == 29)
        {
            cout << "\n";
        }
    }
    cout << "Select From The Following Options:\n[1] New Client\n[2] Bank Manager\n";
    cin >> nav;

    while (nav != 1 || nav != 2) {
        //Create users account and gives them access to their menu based off of their account type
        if (nav == 1) {

            //Account type
            cout << "\nSelect account type:\n[1] Checking \n[2] Savings \n[3] Certificate of Deposit\n";
            cin >> x;
            while (nav2 == 0)
            {
                //Checking Account
                if (x == 1)
                {
                    while (x != 0)
                    {
                        cout << "Please select from the following options:" << endl;
                        cout << "[1] Service Charge Checking : Pays No Interest, Allowed To Issue 5 Checks, No Minimum Balance, $20 Monthly Service Charge" << endl;
                        cout << "[2] No Service Charge Checking : Pays 1% Interest, Allowed To Issue Unlimited Checks, $500 Minimum Balance Required, No Monthly Service Charge" << endl;
                        cout << "[3] High Interest Checking : Pays 2.5% Interest, Allowed To Issue Unlimited Checks, $1000 Minimum Balance Required, No Monthly Service Charge" << endl;
                        cin >> x;
                        //New Service Charge Checking Account
                        if (x == 1)
                        {
                            ServiceChargeChecking accountOne;
                            //account holder name
                            cout << "Enter your full name: ";
                            cin.ignore();
                            getline(cin, accountOne.accName);

                            //Put the Checking Account Menu in here                   
                            while (x == 1 || x == 2 || x == 3 || x == 4 || x == 5) {
                                x = accountOne.clientMenu(1);
                                int amount;
                                string name;
                                switch (x) {
                                case 1:
                                    //Deposit
                                    cout << "(We work on the honor system here)\nHow much would you like to deposit into your account?: $";
                                    cin >> nav;
                                    accountOne.deposit(nav);
                                    nav = 0;
                                    break;
                                case 2:
                                    //Withdrawl
                                    cout << "How much would you like to withdrawl from your account?: $";
                                    cin >> nav;
                                    accountOne.withdrawal(nav);
                                    nav = 0;
                                    break;
                                case 3:
                                    //Print Account Info
                                    accountOne.print();
                                    break;
                                case 4:
                                    //Write A Check
                                    cout << "\nName of person the check is being issued to: ";
                                    cin.ignore();
                                    getline(cin, name);
                                    cout << "Amount being issued: $";
                                    cin >> amount;
                                    accountOne.check(amount, name);
                                    break;
                                case 5:
                                    //Interest Calculator
                                    accountOne.interest(0);
                                    break;
                                }
                            }
                            if (x == 0) {
                                cout << "\nThank you for banking with us! Have a nice day!\n";
                                return 0;
                            }
                            else {
                                cout << "Invalid Input!\n";
                            }
                        }
                        //New No Service Charge Checking Account
                        else if (x == 2)
                        {
                            NoServiceChargeChecking accountOne;
                            //account holder name
                            cout << "Enter your full name: ";
                            cin.ignore();
                            getline(cin, accountOne.accName);

                            //Put the Checking Account Menu in here                   
                            while (x == 1 || x == 2 || x == 3 || x == 4 || x == 5) {
                                x = accountOne.clientMenu(1);
                                int amount;
                                string name;
                                switch (x) {
                                case 1:
                                    //Deposit
                                    cout << "(We work on the honor system here)\nHow much would you like to deposit into your account?: $";
                                    cin >> nav;
                                    accountOne.deposit(nav);
                                    nav = 0;
                                    break;
                                case 2:
                                    //Withdrawl
                                    cout << "How much would you like to withdrawl from your account?: $";
                                    cin >> nav;
                                    accountOne.withdrawal(nav);
                                    nav = 0;
                                    break;
                                case 3:
                                    //Print Account Info
                                    accountOne.print();
                                    break;
                                case 4:
                                    //Write A Check
                                    cout << "\nName of person the check is being issued to: ";
                                    cin.ignore();
                                    getline(cin, name);
                                    cout << "Amount being issued: $";
                                    cin >> amount;
                                    accountOne.check(amount, name);
                                    break;
                                case 5:
                                    //Interest Calculator
                                    accountOne.interest(0);
                                    break;
                                }
                            }
                            if (x == 0) {
                                cout << "\nThank you for banking with us! Have a nice day!\n";
                                return 0;
                            }
                            else {
                                cout << "Invalid Input!\n";
                            }
                        }
                        //New High Interest Checking Account
                        else if (x == 3)
                        {
                            HighInterestChecking accountOne;
                            //account holder name
                            cout << "Enter your full name: ";
                            cin.ignore();
                            getline(cin, accountOne.accName);

                            //Put the Checking Account Menu in here                   
                            while (x == 1 || x == 2 || x == 3 || x == 4 || x == 5) {
                                x = accountOne.clientMenu(1);
                                int amount;
                                string name;
                                switch (x) {
                                case 1:
                                    //Deposit
                                    cout << "(We work on the honor system here)\nHow much would you like to deposit into your account?: $";
                                    cin >> nav;
                                    accountOne.deposit(nav);
                                    nav = 0;
                                    break;
                                case 2:
                                    //Withdrawl
                                    cout << "How much would you like to withdrawl from your account?: $";
                                    cin >> nav;
                                    accountOne.withdrawal(nav);
                                    nav = 0;
                                    break;
                                case 3:
                                    //Print Account Info
                                    accountOne.print();
                                    break;
                                case 4:
                                    //Write A Check
                                    cout << "\nName of person the check is being issued to: ";
                                    cin.ignore();
                                    getline(cin, name);
                                    cout << "Amount being issued: $";
                                    cin >> amount;
                                    accountOne.check(amount, name);
                                    break;
                                case 5:
                                    //Interest Calculator
                                    accountOne.interest(0);
                                    break;
                                }
                            }
                            if (x == 0) {
                                cout << "\nThank you for banking with us! Have a nice day!\n";
                                return 0;
                            }
                            else {
                                cout << "Invalid Input!\n";
                            }
                        }
                        else 
                        {
                            cout << "Error: Invalid Selection!\n";
                        }

                    }
                }
                //Savings Account
                else if (x == 2)
                {
                    while (x != 0) {
                        cout << "Please select from the following options: " << endl;
                        cout << "[1] Standard Savings Account: Pays 2.5% Interest, No Minimum Balance, No Monthly Service Charge" << endl;
                        cout << "[2] High Interest Savings Account: Pays 5% Interest, $10,0000 Minimum Balance, No Monthly Service Charge" << endl;
                        cin >> x;
                        //New Standard Savings Account 
                        if (x == 1) {
                            SavingsAccount accountOne;
                            //account number
                            accountOne.accNum = accountOne.ranNum(0);
                            //account holder name
                            cout << "Enter your full name: ";
                            cin.ignore();
                            getline(cin, accountOne.accName);
                            //Savings Account Menu
                            while (x == 1 || x == 2 || x == 3 || x == 4 || x == 5) {
                                x = accountOne.clientMenu(1);
                                int amount;
                                string name;
                                switch (x) {
                                case 1:
                                    //Deposit
                                    cout << "(We work on the honor system here)\nHow much would you like to deposit into your account?: $";
                                    cin >> nav;
                                    accountOne.deposit(nav);
                                    nav = 0;
                                    break;
                                case 2:
                                    //Withdrawl
                                    cout << "How much would you like to withdrawal from your account?: $";
                                    cin >> nav;
                                    accountOne.withdrawal(nav);
                                    nav = 0;
                                    break;
                                case 3:
                                    //Print Account Info
                                    accountOne.print();
                                    break;
                                case 4:
                                    //Interest Calculator
                                    accountOne.interest(0);
                                    break;
                                }
                            }
                            if (x == 0) {
                                cout << "\nThank you for banking with us! Have a nice day!\n";
                                return 0;
                            }
                            else {
                                cout << "Invalid Input!\n";
                            }
                        }
                        //New High Interest Savings Account
                        else if (x == 2) {
                            HighSavingsAccount accountOne;
                            //account number
                            accountOne.accNum = accountOne.ranNum(0);
                            //account holder name
                            cout << "Enter your full name: ";
                            cin.ignore();
                            getline(cin, accountOne.accName);
                            //Savings Account Menu
                            while (x == 1 || x == 2 || x == 3 || x == 4 || x == 5) {
                                x = accountOne.clientMenu(1);
                                int amount;
                                string name;
                                switch (x) {
                                case 1:
                                    //Deposit
                                    cout << "(We work on the honor system here)\nHow much would you like to deposit into your account?: $";
                                    cin >> nav;
                                    accountOne.deposit(nav);
                                    nav = 0;
                                    break;
                                case 2:
                                    //Withdrawl
                                    cout << "How much would you like to withdrawal from your account?: $";
                                    cin >> nav;
                                    accountOne.withdrawal(nav);
                                    nav = 0;
                                    break;
                                case 3:
                                    //Print Account Info
                                    accountOne.print();
                                    break;
                                case 4:
                                    //Interest Calculator
                                    accountOne.interest(0);
                                    break;
                                }
                            }
                            if (x == 0) {
                                cout << "\nThank you for banking with us! Have a nice day!\n";
                                return 0;
                            }
                            else {
                                cout << "Invalid Input!\n";
                            }
                        }
                        else {
                            cout << "Error: Invalid Selection!";
                        }

                        
                    }
                }
                //CD Account 
                else if (x == 3)
                {
                    CD accountOne;
                    accountOne.accType = "CD";
                    //account number
                    accountOne.accNum = accountOne.ranNum(0);
                    //account holder name
                    cout << "Enter your full name: ";
                    cin.ignore();
                    getline(cin, accountOne.accName);

                    //CD Menu 
                    while (x == 1 || x == 2 || x == 3 || x == 4 || x == 5) {
                        x = accountOne.clientMenu(1);
                        int amount;
                        string name;
                        switch (x) {
                        case 1:
                            //Deposit
                            cout << "(We work on the honor system here)\nHow much would you like to deposit into your account?: $";
                            cin >> nav;
                            accountOne.deposit(nav);
                            nav = 0;
                            break;
                        case 2:
                            //Buy CD
                            cout << "Would you like to purchase a Certificate of Deposit?\nPrice: $5000\nMaturity: 6 Months\nInterest Rate: 10.0%\n[1] Yes\n[2] No\n";
                            cin >> x;
                            accountOne.buyCD(x);
                            nav = 0;
                            break;
                        case 3:
                            //Withdrawal CD
                            cout << "WARNING: Early Withdrawal Result In A $500 Penalty!\nWould You Like To Proceed?\n[1] Yes\n[2] No\n";
                            cin >> x;
                            if (x == 1) {
                                cout << "Total owned CDs: " << accountOne.getCDNum() << endl;
                                cout << "Amount of CDs you would like to withdrawal: ";
                                cin >> nav;
                                if (nav != accountOne.getCDNum()) {
                                    cout << "Error: Invalid Selection!\n";
                                    break;
                                }
                                else {
                                    accountOne.cdWithdrawal(nav);
                                    nav = 0;
                                    break;
                                }
                            }
                            else {
                                break;
                            }
                        case 4:
                            //Withdrawal Cash
                            cout << "How much would you like to withdrawal from your account?: $";
                            cin >> nav;
                            accountOne.withdrawal(nav);
                            nav = 0;
                            break;;
                        case 5: 
                            //Account Info
                            accountOne.print();
                            break;
                        }
                    }
                    if (x == 0) {
                        cout << "\nThank you for banking with us! Have a nice day!\n";
                        return 0;
                    }
                    else {
                        cout << "Invalid Input!\n";
                    }

                    }
                
            }
            if (x != 1 || x != 2 || x != 3)
            {
                cout << "Error: Invalid entry!";
                cout << "\nSelect account type:\n[1] Checking \n[2] Savings \n[3] Certificate of Deposit\n";
                cin >> x;
                }
            //new account message
            cout << "\nSuccessfully created a new account!\n\n";

        }
        //Give the user access to the manager menu
        else if (nav == 2) {
            ManagerAccount manager;
            ManagerAccount randomAccounts[10] = { 1,1,1,1,1,1,1,1,1,1 };
            for (int i = 0; i < 10; i++) {
                randomAccounts[i].balance = randomAccounts[i].balance + (rand() % 5000);
                randomAccounts[i].accNum = randomAccounts[i].accNum + (rand() % 25000);
            }
            //Mini authentication system to assure that a random person doesn't access the manager menu
            int password;
            int counter = 3;
            while (x == 1) {
                cout << "Enter system passcode: ";
                cin >> password;
                if (password == 123) {
                    while (x != 0) {
                        x = manager.managerMenu(1);
                        switch (x) {
                        case 1:
                            //Total Bank Balance
                            for (int i = 0; i < 10; i++)
                            {
                                x = randomAccounts[i].balance + x;
                            }
                            cout << "\nTotal Balance Of All Accounts: $" << x << endl;
                            break;
                        case 2:
                            //All Bank Accounts Info
                            cout << "\nAll Bank Accounts" << endl;
                            for (int i = 0; i < 30; i++) {
                                cout << "-";
                                if (i == 29)
                                {
                                    cout << "\n";
                                }
                            }
                            for (int i = 0; i < 10; i++) {
                                randomAccounts[i].printAccounts();
                            }
                            break;
                        }
                    }
                }
                else if (counter == 1)
                {
                    cout << "\nPasscode limit reached. System shutting down.\n";
                    return 0;
                }
                else if (counter == 2)
                {
                    counter--;
                    cout << "\nWRONG CODE!\n" << counter << " attempt remain" << endl;
                }
                else {
                    counter--;
                    cout << "\nWRONG CODE!\n" << counter << " attempts remain" << endl;
                }
            }
        }
        else {
            cout << "Invalid input! Select 1 or 2\n";
            cout << "Choose from the following options:\n[1] New Client\n[2] Bank Manager\n";
            cin >> nav;
        }
    }
}

