#include <iostream>

class Integer{
    // Non-static member data initialization
    private:
        int  *m_pInt{nullptr};

    public:
        Integer();
        Integer(int value);
        Integer(const Integer& obj);
        Integer(Integer &&obj);
        int GetValue() const;
        void SetValue(int value);
        ~Integer();
};

Integer::Integer()
{
    m_pInt = new int(0);
}

Integer::Integer(int value)
{
    m_pInt = new int(value);
}

// Copy ctor (works on l-value)
Integer::Integer(const Integer& obj)
{
    m_pInt = new int(*(obj.m_pInt));
}

// Move ctor (works on r-value)
Integer::Integer(Integer &&obj)
{
    m_pInt = obj.m_pInt;
    obj.m_pInt = nullptr;
}


int Integer::GetValue() const
{
    return *m_pInt;
}

void Integer::SetValue(int value)
{
    *m_pInt = value;
}

Integer::~Integer()
{
    delete m_pInt;
}


int main()
{

    Integer i(5);
    Integer i2(i);
    std::cout << i.GetValue() << std::endl;
    std::cout <<i2.GetValue() << std::endl;
    return EXIT_SUCCESS;
}