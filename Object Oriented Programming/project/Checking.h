#pragma once
#include "Account.h"

class Checking : public Account
{
    public:
        using Account::Account;
        ~Checking();
        void Withdraw(float amount);
};