#include <iostream>
#include "Checking.h"




Checking::~Checking()
{

}

void Checking::Withdraw(float amount)
{
    if((m_Balance - amount) > 50)
        Account::Withdraw(amount);
    else
        std::cout<<"Invalid amount"<<std::endl;
}