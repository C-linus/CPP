#include <iostream>
#include "Savings.h"
#include "Checking.h"
#include "Transact.h"

int main()
{
    Savings acc("Bob",100,0.05f);
    Transact(&acc);
    return 0;
}