#include <iostream>


template<typename T>
T Add(const T& x, const T& y)
{
    return x + y;
}

template<typename T>
T ArraySum(const T* pArr, size_t arrSize)
{
    T sum{};
    for(size_t i = 0; i < arrSize; i++)
        sum += *(pArr + i);

    return sum; 
}

template<typename T>
const T& Max(const T* pArr, size_t arrSize)
{
    const T* maxPtr{pArr};

    for(size_t i = 1; i < arrSize; i++)
        if(*(pArr + i) > *maxPtr)
            maxPtr = (pArr + i);
    
    return *maxPtr;
}

template<typename T> 
std::pair<const T&, const T&> MinMax(const T* pArr, size_t arrSize) 
{ 
    const T* minPtr = pArr; 
    const T* maxPtr = pArr; 
    for(size_t i = 1; i < arrSize; ++i) 
    { 
        if(pArr[i] < *minPtr) minPtr = &pArr[i]; 
        if(pArr[i] > *maxPtr) maxPtr = &pArr[i]; 
    } 
    return {*minPtr, *maxPtr}; 
}