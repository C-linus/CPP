#include <iostream>
using namespace std;

int main()
{

    //Try to modify x1 & x2 and see the compilation output
    int x = 5 ;
    const int MAX = 12 ;
    int &ref_x1 = x ;
    ref_x1 = 6;
    cout<<"x1:"<<x<<endl;
    const int &ref_x2 = x ; 
    //ref_x2 = 7; | This is not possible because the ref is const to the data it is pointing

    
    //Try to modify the pointer (e.g. ptr1) and the pointee value (e.g. *ptr1)
    const int *ptr1 = &x ; // const integer pointer (data can't be modified)
    int *const ptr2 = &x ; // const pointer (refernce to the pointer can't be modified)
    const int * const ptr3 = &x ; // both pointer and data it is pointing is constant
    
    //Find which declarations are valid. If invalid, correct the declaration
    const int *ptr5 = &MAX ;
    //int *ptr4 = &MAX ; // This is invalid, the pointer should be const to the data type
    
    const int &r1 = ref_x1 ; // It is valid,but through refernce r1 we can't modify x
    //int &r2 = ref_x2 ; // This is invalid, the reference should be const to the data type
    
    const int *&p_ref1 = ptr1 ;
    int* const &p_ref2 = ptr2 ;

    return EXIT_SUCCESS;
}