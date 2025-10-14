#include <iostream>
#include "Transact.h"
#include "Checking.h"
#include <typeinfo>

void Transact(Account* pAccount)
{
    std::cout<< "Transaction started" << std::endl;
    std::cout<< "Initial Balance: " << pAccount->GetBalance() << std::endl;
    pAccount->Deposit(100);
    pAccount->AccumulateInterest();

    // typeid operator
    // if(typeid(*pAccount) == typeid(Checking))
    // {
    //     Checking* pChecking = static_cast<Checking *>(pAccount);
    //     std::cout<<"Minimum balance of Checking:" << pChecking->GetMinimumBalance() << std::endl;
    // }

    // dynamic cast
    Checking *pChecking = dynamic_cast<Checking *>(pAccount);
    if(pChecking != nullptr)
    {
            std::cout<<"Minimum balance of Checking:" << pChecking->GetMinimumBalance() << std::endl;

    }

    pAccount->Withdraw(170);
    std::cout << "Interest rate:" << pAccount->GetInterestRate() << std::endl;
    std::cout << "Final Balance:" << pAccount->GetBalance() << std::endl;
}