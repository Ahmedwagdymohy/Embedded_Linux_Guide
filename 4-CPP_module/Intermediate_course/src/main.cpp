#include <stdio.h>
#include <iostream>
#include <string>

#include "math.hpp"
#include <concepts>

using namespace std;


template <typename T , typename T2 = T >
concept Equality_comparison = 
    requires (T a, T2 b){
        {a == b} -> std::same_as<bool>;
        {a != b} -> std::same_as<bool>;
        {b == a} -> std::same_as<bool>;
        {b != a} -> std::same_as<bool>;
    };


int main(){

    cout<<sum(5,10,20,50,80,100)<<endl;
    static_assert(Equality_comparison<int,double>);


/* if (__cplusplus == 202101L) std::cout << "C++23";
    else if (__cplusplus == 202002L) std::cout << "C++20";
    else if (__cplusplus == 201703L) std::cout << "C++17";
    else if (__cplusplus == 201402L) std::cout << "C++14";
    else if (__cplusplus == 201103L) std::cout << "C++11";
    else if (__cplusplus == 199711L) std::cout << "C++98";
    else std::cout << "pre-standard C++." << __cplusplus;
    std::cout << "\n"; */

}

