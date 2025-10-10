#include <string>

class Account
{
    private:
        std::string m_Name;
        float m_Balance;
        int m_AccNo;
        static int S_ANGenerator;

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
        float GetInterestRate() const;

        
        void AccumulateInterest();
        void Withdraw(float amount);
        void Deposit(float amount);
};