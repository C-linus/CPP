#pragma once
#include "Account.h"

class Checking : public Account
{
    private:
        float m_MinimumBalance;

    public:
        Checking(const std::string& name, float balance,float minbalance);
        ~Checking();
        void Withdraw(float amount);

        // Getters
        float GetMinimumBalance() const;
};