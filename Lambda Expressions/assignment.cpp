#include <iostream>
#include <algorithm>
#include <utility>

template<typename T>
struct Max()
{
    T operator ()(T a, T b)
    {
        return (a > b)? a : b;
    }
};


template<typename T>
struct GreaterFunctor {
    bool operator()(T a, T b) const {
        return a > b;
    }
};


template<typename T>
struct LessFunctor {
    bool operator()(T a, T b) const {
        return a < b;
    }
};



template<typename Iterator>
struct MinMaxFunctor {
    auto operator()(Iterator begin, Iterator end) const {
        auto minmax = std::minmax_element(begin, end);
        return std::make_pair(*minmax.first, *minmax.second);
    }
};
