#include <array>
#include <iostream>
//Writing modern C++ code
using namespace std;


enum class option{
    FRIES = 1,
    BURGER=2 ,
    EXIT =3
};

option DEFAULT = option::FRIES;




istream& operator>> (istream& input_stream, option &result){
    int int_option;
    input_stream >> int_option;
    result = static_cast<option>(int_option);
}


string to_string (const option optt)
{
    switch(optt){
        case option::FRIES:
            return "FRIES";
        case option::BURGER:
            return "BURGER";

        case option::EXIT:
            return "EXIT";          
    }
}


int main(){

    option Ahmed = DEFAULT;
    cin>> Ahmed;


    array<int, 10> numbers={1,2,3,4,5,6,7,8,9,10};
    for(auto number:numbers){
        cout<<number<<endl;
    }

}