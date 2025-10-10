#include <iostream>
#include "Account.h"

int main()
{
    Account acc("Bob",1000);
    std::cout << "Initial Balance:" << acc.GetAccountNo() << std::endl;
    acc.Deposit(200);
    acc.Withdraw(380);
    std::cout<< "Balance: " << acc.GetBalance() << std::endl;
    return 0;
}