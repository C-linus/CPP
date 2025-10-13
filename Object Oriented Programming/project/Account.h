#pragma once
#include <string>

class Account
{
    private:
        std::string m_Name;
        int m_AccNo;
        static int S_ANGenerator;
        
    protected:
        float m_Balance;

    public:
        // Ctors
        Account() = delete;
        Account(const std::string&name, float balance);

        // Dtor
        ~Account();

        // Getters
        const std::string & GetName() const;
        float GetBalance() const;
        int GetAccountNo() const;
        virtual float GetInterestRate() const;

        
        virtual void AccumulateInterest();
        virtual void Withdraw(float amount);
        void Deposit(float amount);
};