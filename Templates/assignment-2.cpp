#include <iostream> 


template<typename T, size_t N>
T ArraySum(const T (&arr)[N])
{
    T sum{}; 
    for (size_t i = 0; i < N; i++)
        sum += arr[i]; 
    return sum; 
}

template<typename T, size_t N>
const T& Max(const T (&arr)[N])
{
    const T* maxPtr = arr;
    for (size_t i = 1; i < N; i++)
        if (*(arr + i) > *maxPtr)
            maxPtr = (arr + i);
    return *maxPtr;
}

template<typename T, size_t N>
std::pair<const T&, const T&> MinMax(const T (&arr)[N])
{
    const T* minPtr = arr;
    const T* maxPtr = arr;
    for (size_t i = 1; i < N; ++i)
    {
        if (*(arr + i) < *minPtr) minPtr = (arr + i);
        if (*(arr + i) > *maxPtr) maxPtr = (arr + i);
    }
    return {*minPtr, *maxPtr};
}

int main()
{}
