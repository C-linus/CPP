#include <iostream>
#include "Savings.h"
#include "Checking.h"
#include "Transact.h"

int main()
{
    Checking acc("Bob",100,50);
    Transact(&acc);
    return 0;
}