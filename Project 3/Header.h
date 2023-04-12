#include <iostream>
#include <string>
using namespace std;

class bankAccount {
public:
    //Default constructor
    bankAccount();  
    //Creates a random number
    static int ranNum(int x);
    //Print the account holder name, account number, account type, balance, and interest rate (1 for client info and 2 for the whole banks info)
    void print();
    //Adds money to the account balance
    void deposit(int x);
    //Subtracts money from the account balance
    void withdrawal(int x);
    //Returns wether the user would like to overdraft their account or not
    bool choiceWithdrawal(int x);
    //Displays and gives the user their estimated monthly interest payment to their account
    void interest(int x);

    //Set Functions
    void setBalance(int x);
    void setAccNum(int x);
    void setAccType(int x);
    void setIntRate(string x);

    //Get Functions
    double getIntRate();
    double getBalance();
    int getAccNum();
    string getAccType();

    double balance;
    int accNum;
    string accName;
    string accType;
    int totalBalance;
    int withdrawlNum;
    double intRate;
    int minBalance;
    int serviceCharge;
};

class CheckingAccount: public bankAccount {
public:
    //Default Checking Account Constructor
    CheckingAccount();
    //Checking Account Menu
    int clientMenu(int x);
    //Issues A Check
    void check(int amount, string name);

private:
    int checkNum;
};

class ServiceChargeChecking : public CheckingAccount {
public:
    ServiceChargeChecking();
};

class NoServiceChargeChecking : public CheckingAccount {
public:
    NoServiceChargeChecking();
};

class HighInterestChecking : public CheckingAccount {
public:
    HighInterestChecking();
};

class SavingsAccount: public bankAccount {
public:
    //Default Savings Account Constructor
    SavingsAccount();
    //Savings Account Menu
    int clientMenu(int x);
};

class HighSavingsAccount : public SavingsAccount {
public:
    //Default Constructor
    HighSavingsAccount();
};

class ManagerAccount: public bankAccount {
public:
    //Default Constructor
    ManagerAccount();
    //Constructor for random accounts and balances
    ManagerAccount(int x);
    //Manager Menu
    int managerMenu(int x);
    //Prints the randomly created accounts
    void printAccounts();
};

class CD : public bankAccount {
public:
    //Default CD Constructor
    CD();
    //CD Menu
    int clientMenu(int x);
    //Buy Certificate of Deposit
    void buyCD(int x);
    //View Your Certificate of Deposit
    void viewCD();
    //Withdrawl Your CD
    void cdWithdrawl();
    //Set Functions
    void setMaturityMonths(int x);
    void setCDNum(int x);
    void incrementCDNum();
    //Get Functions
    int getMaturityMonths();
    int getCDNum();
private:
    int maturityMonths;
    int currMonth;
    int cdNum;
};