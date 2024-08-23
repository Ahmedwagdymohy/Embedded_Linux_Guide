#include <array>
#include <iostream>
//Writing modern C++ code
using namespace std;

int main(){
    array<int, 10> numbers={1,2,3,4,5,6,7,8,9,10};
    for(auto number:numbers){
        cout<<number<<endl;
    }

}