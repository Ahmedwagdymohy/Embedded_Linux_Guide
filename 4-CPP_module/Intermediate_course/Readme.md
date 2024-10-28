# Meta-programming
- Meta-programming is processed in the compile time


1. **Template** : it's a way to write a generic function that can take any type of data
    - ```cpp
        template <typename T>
        T add(T a, T b){
            return a+b;
        }
        int main (){
            cout<<add<float>(1.5,2.9)<<endl;
        }
      ```
    [NOTE]:
    - If you sperated the implementation of the template function and the declaration, it will generate an compiler error so You have to put the implementation in the header file.
    - If we didn't specify the type of the template function when using , the compiler will make an `argument deduction` he just will try to guess  



    - We have `auto` keyword , it's used to tell the compiler to guess the data type of the variable and mostly used with the return type of the function , to let the compiler decide

2. **Function template specialization** : here we specify a special type of the template , when the user use it get executed like the following example
    - ```cpp
        template <typename T>
        T add(T a, T b){
            return a+b;
        }
        template <>
        auto sum<string, string> (const string a , const string b){
            return a.length() + b.length();
        }

        int main(){
        string a {"Hello"};
        string b {"World"};
        cout<<sum<string, string>(a,b) <<endl;
        }
      ```
    [NOTE]:
    - The compiler will choose the specialized function if it's found , if not it will choose the general function 

3. **Variadic templates :**
    - it's a way to pass many arguments to the function and they are not fixed
    - we make parameter packing `....`
    - ```cpp
        template <typename T>
        void print(T arg){
            cout<<arg<<endl;
        }
        template <typename T, typename... Args>
        // key word `Args` can be any name
        void print(T arg, Args... args){
            // key word `args` can be any name
            cout<<arg<<endl;
            print(args...);
        }
        int main(){
            print(1,2,3,4,5);
        }
      ```


    - NOTE the following edits, here we have used parameters packing and unpacking, if the size of packed parameters is greater than 0, we will add the first two parameters and and then pack the rest of the parameters and add them :
        ```cpp
        auto sum (const T a , const U b, const Ts ... args){
        if constexpr ( sizeof... (Ts) > 0){
        auto r = a + b;
        return sum (r, args ... );

        }else{
        return a + b;

        }
        }
       ```
    - But there's an issue above that if we passed just one argument to the function it will error, so to solve it we should use template overloading with one parameter and specify the action to do with one argument :
        ```cpp
        template <typename T>
        T sum (const T a){
        return a;
        }
        template <typename T, typename U, typename... Ts>
        auto sum (const T a , const U b, const Ts ... args){
        if constexpr ( sizeof... (Ts) > 0){
        auto r = a + b;
        return sum (r, args ... );

        }else{
        return a + b;

        }
        }
        ```  

4. **Folding expression :**
