#include <iostream>
#include <string>
#include "Header.h";
using namespace std;
//bankAccount Functions:

//Default constructor
bankAccount::bankAccount() {
    accName = "NULL";
    accNum = 0;
    balance = 0.0;
    intRate = 0.0;
    totalBalance = 0;
    withdrawlNum = 0;
}
//Creates a random number
int bankAccount::ranNum(int x) {
    //Random number for accounts
    if (x == 0) {
        srand(time(NULL));
        return 10000 + (rand() % 99999);
        srand(time(NULL));
    }
    //Random number for balances
    else {
        srand(time(NULL));
        return 1000 + (rand() % 999) + (rand() % 999);
        srand(time(NULL));
    }
}
//Print the account holder name, account number, account type, balance, and interest rate (1 for client info and 2 for the whole banks info)
void bankAccount::print() {
    cout << "\n";
    cout << accName << "'s " << accType << " Account:\n";
    for (int i = 0; i < 30; i++) {
        cout << "*";
    }
    cout << "\nAccount Number: " << accNum << "\nBalance: $" << balance << "\nInterest Rate : " << intRate << "%\n\n";
}
//Adds money to the account balance
void bankAccount::deposit(int x) {
    balance = balance + x;
    cout << "\nSuccessfully deposited $" << x << " to your account!\nBalance: $" << balance << "\n\n";
}
//Subtracts money from the account balance
void bankAccount::withdrawal(int x) {
    if (accType == "Savings" && withdrawlNum >= 3) {
        cout << "\nYou have reached your limit of withdrawl transactions allowed this month!\nPlease call your local branch for assistance -- (562) 314 1592\n" << endl;
    }
    else if (balance >= x) {
        balance = balance - x;
        cout << "\nSuccessfully withdrew $" << x << " from your account!\nBalance: $" << balance << "\n\n";
    }
    else if (choiceWithdrawal(0) == false) {
        cout << "Error: Withdrawal Transaction Aborted!\n";
    }
    else {
        if (accType == "Checking") {
            balance = balance - x - 35;
            cout << "\nSuccessfully withdrew $" << x << " from your account and were charged a $35 service fee!\nBalance: $" << balance << "\n\n";
        }
        else {
            balance = balance - x - 50;
            cout << "\nSuccessfully withdrew $" << x << " from your account and were charged a $50 service fee!\nBalance: $" << balance << "\n\n";
        }
    }

    withdrawlNum++;
}
//Returns wether the user would like to overdraft their account or not
bool bankAccount::choiceWithdrawal(int x) {
    cout << "\nAmount Requested Exceeds Your Available Balance!\nWould you like to overdraft your account? (your account will be charged a service fee)\n[1] Yes\n[2] No\n";
    cin >> x;
    if (x == 1)
    {
        return true;
    }
    else if (x == 2)
    {
        return false;
    }
}
//Displays and gives the user their estimated monthly interest payment to their account
void bankAccount::interest(int x) {
    cout << "\n[1] Interest Calculator\n[2] Post Interest\n";
    cin >> x;
    if (x == 1) {
        cout << "\nBalance: $" << getBalance() << "\nInterest Rate: " << getIntRate() << "%\n";
        x = (getBalance() * getIntRate()) / 100;
        cout << "Estimated Monthly Interest Payment: $" << x << "\nBe aware that this payment will be credited to your account on the 1st of the month\nThis is only a tool to give you your estimated credit\n";
    }
    else if (x == 2) {
        x = (getBalance() * getIntRate()) / 100;
        balance = balance + x;
        cout << "Interest Payment: $" << x << "\n";
        cout << "New Account Balance: $" << getBalance() << "\n";
    }
    else
    {
        cout << "Error: Invalid Input!";
        interest(0);
    }
}

//Set Functions
void bankAccount::setBalance(int x) {
    balance = ranNum(1);
}
void bankAccount::setAccNum(int x) {
    accNum = ranNum(0);
}
void bankAccount::setAccType(int x) {
    if (x == 0) {
        accType = "Checking";
    }
    else if (x == 1) {
        accType = "Savings";
    }
}
void bankAccount::setIntRate(string x) {
    if (x == "Checking") {
        intRate = 1.0;
    }
    else if (x == "Savings") {
        intRate = 5.0;
    }
}

//Get Functions
double bankAccount::getBalance() {
    return balance;
}
double bankAccount::getIntRate() {
    return intRate;
}
int bankAccount::getAccNum() {
    return accNum;
}
string bankAccount::getAccType() {
    return accType;
}



//Checking Account Functions:
//Default Constructor
CheckingAccount::CheckingAccount(): bankAccount() {
    checkNum = 1;
    accType = "Checking";
    accNum = ranNum(0);
}
//Checking Account Menu
int CheckingAccount::clientMenu(int x) {
    cout << endl;
    for (int i = 0; i < 30; i++) {
        cout << "-";
        if (i == 29)
        {
            cout << "\n";
        }
    }
    cout << "\tClient Menu\n";
    for (int i = 0; i < 30; i++) {
        cout << "-";
        if (i == 29)
        {
            cout << "\n";
        }
    }
    while (x != 0) {
        cout << "Select From The Following Options:\n[1] Deposit\n[2] Withdrawal\n[3] Account Info\n[4] Write A Check\n[5] Interest Calculator\n[0] Exit\n";
        cin >> x;
        if (x == 1 || x == 2 || x == 3 || x == 4 || x == 5) {
            switch (x) {
            case 1:
                //Deposit
                return 1;
            case 2:
                //Withdrawl
                return 2;
            case 3:
                //Print Account Info
                return 3;
            case 4:
                //Write A Check
                return 4;
            case 5:
                //Interest Calculator
                return 5;
            }
        }
        else if (x == 0) {
            return 0;
        }
        else {
            cout << "Invalid Input!\n";
        }
    }
}
//Issues a Check
void CheckingAccount::check(int amount, string name) {

    if (balance < amount)
    {
        cout << "Error: Unable to issue a check for more than your balance!" << endl;
    }
    else {
        for (int i = 0; i < 30; i++) {
            cout << "-";
            if (i == 29)
            {
                cout << "\n";
            }
        }
        cout << accName << "\nCheck: " << checkNum << "\nPay To The Order Of: " << name << "\nAmount: $ " << amount << "\nFrom Account: " << accNum;
        checkNum++;
        balance = balance - amount;
    }
}

//Service Charge Checking
//Default Constructor
ServiceChargeChecking::ServiceChargeChecking(): CheckingAccount() {
    intRate = 0.0;
    minBalance = 0;
    serviceCharge = 20;
}

//No Service Charge Checking
//Default Constructor
NoServiceChargeChecking:: NoServiceChargeChecking(): CheckingAccount() {
    intRate = 1.0;
    minBalance = 500;
    serviceCharge = 0;
}

// High Interest Checking
//Default Constructor
HighInterestChecking::HighInterestChecking(): CheckingAccount() {
    intRate = 2.5;
    minBalance = 1000;
    serviceCharge = 0;
}

//Savings Account Functions:
//Default Constructor
SavingsAccount::SavingsAccount() {
    intRate = 2.5;
    minBalance = 0;
    serviceCharge = 0;
}
//Savings Account Menu 
int SavingsAccount::clientMenu(int x) {
    cout << endl;
    for (int i = 0; i < 30; i++) {
        cout << "-";
        if (i == 29)
        {
            cout << "\n";
        }
    }
    cout << "\tClient Menu\n";
    for (int i = 0; i < 30; i++) {
        cout << "-";
        if (i == 29)
        {
            cout << "\n";
        }
    }
    while (x != 0) {
        cout << "Select From The Following Options:\n[1] Deposit\n[2] Withdrawal\n[3] Account Info\n[4] Interest Calculator\n[0] Exit\n";
        cin >> x;
        if (x == 1 || x == 2 || x == 3 || x == 4) {
            switch (x) {
            case 1:
                //Deposit
                return 1;
            case 2:
                //Withdrawl
                return 2;
            case 3:
                //Print Account Info
                return 3;
            case 4:
                //Interest Calculator
                return 4;
            }
        }
        else if (x == 0) {
            return 0;
        }
        else {
            cout << "Invalid Input!\n";
        }
    }
}

//High Interest Savings Account Functions:
//Default Constructor
HighSavingsAccount::HighSavingsAccount() {
    intRate = 5.0;
    minBalance = 10000;
    serviceCharge = 0;
}

//Manger Account Functions: 
//Default Constructor
ManagerAccount::ManagerAccount() {

}
//Constructor for random accounts and balances
ManagerAccount::ManagerAccount(int x) {
    //Assigns a random account number
    accNum = ranNum(0) + ranNum(0);
    //Assigns a random balance to the account
    balance = ranNum(1);
    totalBalance = 0;
    accName = "NULL";
    accType = "NULL";
    intRate = 0.0;
    withdrawlNum = 0;
}
//Manager Menu
int ManagerAccount::managerMenu(int x)
{
    for (int i = 0; i < 30; i++) {
        cout << "-";
        if (i == 29)
        {
            cout << "\n";
        }
    }
    cout << "\tManager Menu\n";
    for (int i = 0; i < 30; i++) {
        cout << "-";
        if (i == 29)
        {
            cout << "\n";
        }
    }
    while (x != 0) {
        cout << "Select From The Following Options:\n[1] Total Bank Balance\n[2] View All Bank Accounts\n[0] Exit\n";
        cin >> x;
        if (x == 1 || x == 2) {
            switch (x) {
            case 1:
                //Total Bank Balance
                return 1;
                break;
            case 2:
                //All Bank Accounts Info
                return 2;
                break;
            }
        }
        else if (x == 0) {
            cout << "\nEnd Of Program!\n";
            return 0;
            break;
        }
        else {
            cout << "Invalid Input!\n";
        }
    }
}
//Prints the randomly created accounts
void ManagerAccount::printAccounts() {
    cout << "Account Number:\t" << accNum << "\nBalance:\t$" << balance << endl;
    for (int i = 0; i < 30; i++) {
        cout << "*";
        if (i == 29)
        {
            cout << "\n";
        }
    }
}

//CD Account Functions:
//Default Constructor
CD::CD():bankAccount() {
    maturityMonths = 0;
    currMonth = 0;
    cdNum = 0;
    intRate = 10.0;
    minBalance = 0;
}
//CD Account Menu
int CD::clientMenu(int x) {
    cout << endl;
    for (int i = 0; i < 30; i++) {
        cout << "-";
        if (i == 29)
        {
            cout << "\n";
        }
    }
    cout << "\tCertificate Of Deposit Menu\n";
    for (int i = 0; i < 30; i++) {
        cout << "-";
        if (i == 29)
        {
            cout << "\n";
        }
    }
    while (x != 0) {
        cout << "Select From The Following Options:\n[1] Deposit\n[2] Buy CD\n[3] Withdrawal CD\n[4] Withdrawal Cash\n[5] View CDs\n[0] Exit";
        cin >> x;
        if (x == 1 || x == 2 || x == 3 || x == 4 || x == 5) {
            switch (x) {
            case 1:
                //Buy CD
                return 1;
            case 2:
                //Withdrawl
                return 2;
            case 3:
                //View CDs
                return 3;
            }
        }
        else if (x == 0) {
            return 0;
        }
        else {
            cout << "Error: Invalid Input!\n";
        }
    }
}
//Buy A CD
void CD::buyCD(int x) {
    while (x == 0)
    {
        cout << "Would you like to purchase a Certificate of Deposit?\nPrice: $5000\nMaturity: 6 Months\nInterest Rate: 10.0%\n[1] Yes\n[2] No\n";
        cin >> x;
        if (x == 1)
        {
            incrementCDNum();
            cout << "Successfully Purchased A Certificate Of Deposit!\nCD #" << cdNum << "\nPurchase Price: $5000\nMature Value: $5500";
        }
        else {
            cout << "Error: Invalid Selection!\n";
        }
    }
    return;
}
//Set Functions
void CD::setMaturityMonths(int x) {
    maturityMonths = x;
}
void CD::setCDNum(int x) {
    cdNum = x;
}
void CD::incrementCDNum() {
    cdNum++;
}
//Get Functions
int CD::getMaturityMonths() {
    return maturityMonths;
}
int CD::getCDNum() {
    return cdNum;
}