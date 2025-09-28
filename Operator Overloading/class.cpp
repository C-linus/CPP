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

class Intptr
{
    private:
        Integer *m_p;

    public:
        Intptr(Integer* p): m_p(p) {}
        ~Intptr(){delete m_p;}
        Integer * operator ->() { return m_p;}
        Integer & operator *() {return *m_p;}
};


int main()
{

    Intptr p = new Integer;
    p->SetValue(5);
    std::cout<< p->GetValue() << std::endl;
    return EXIT_SUCCESS;
}