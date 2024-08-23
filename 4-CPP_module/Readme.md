# 🪓  Modern Cpp Module  🪓
## 1. 🧙🏻‍♂️ Basics
###  🦖 Modifiers:
In C++, modifiers are keywords that modify the behavior of fundamental data types. They can be used to alter the size or properties of a data type. Here are some common modifiers in C++:

- **🤔 const**: This keyword is used to declare constants. It indicates that the value of a variable cannot be changed after it is initialized.

    - `const int myConstVar = 10; `


- **🤔 volatile**: This keyword is used to indicate that a variable may be changed by some external factors, such as hardware, and should not be optimized by the compiler.

    - `volatile int sensorValue`; 


- **🤔 mutable**: It is used in a class to allow a particular data member to be modified even if the object is declared as const.

    - `class Example { public: mutable int mutableVar; };` 

- **🤔 static**: When used with variables, it makes the variable retain its value between function calls. When used with functions, it makes the function a class function rather than an instance function.

    - `static int staticVar; static void staticFunction();`

- **🤔 extern**: It is used to declare a variable or function that is defined in another file or in an external library.

    - `extern int externVar; extern void externFunction(); `


- **🤔 constexpr**: This keyword is used to declare variables that are evaluated at compile time. It can also be used to define functions that are evaluated at compile time, The key point of constexpr is that it can be executed at compile time. Your code may have been executed before you run it. That’s the main point.

---
### 🦖 Coding Guidelines:
1. **Always initialize variables when you declare them**.
    - for the string , it's intialized by default to empty string.

2. **Don't use endl to end a line, use '\n' instead for performance reasons**.

3. **Stop using the magic number , Don't use nmbers in the code instead make a varaible with this name and make it understandable**

4. **Don't use the C array , instead use the array from the STL,This gives more features and saftey to the code**.

---

### 🦖Arrays:
In modern c++ we don't use the C arrays , we include the array instead , this gives us more features and safety.

- ```cpp
    #include <array>
    using namespace std;
    array<int, 5> myArray = {1, 2, 3, 4, 5}; //myArray is the name of the array
  ```



### 🦖Stirng:
In modern c++ We have String from STL.

- ```cpp
    #include <string>
    using namespace std; 
    string name="Ahmed";
    //operations on string
    name.size();        //return the size of the string
    name.empty();       //return true if the string is empty
    name.clear();       //clear the string
    name.substr(0,3);   //return the substring from index 0 to 3
    name.max_size();    //return the max size of the string can reach
    name.length();      //return the length of the string -> same as size()
  ```