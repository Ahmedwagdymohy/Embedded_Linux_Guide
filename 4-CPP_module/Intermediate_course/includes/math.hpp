#ifndef  _MATH_HPP_
#define _MATH_HPP_

/**
 * @brief provide the function that gives the sum of two integres
 */

using namespace std;
template <typename T, typename U, typename ... Ts>


auto sum (const T a , const U b, const Ts ... args){
    if constexpr ( sizeof... (Ts) > 0){
        auto r = a + b;
        return sum (r, args ... );

    }else{
        return a + b;

    }

}


//function template specialization
 

template <>
auto sum<string, string> (const string a , const string b){
    return a.length() + b.length();

}

#endif // _MATH_HPP_