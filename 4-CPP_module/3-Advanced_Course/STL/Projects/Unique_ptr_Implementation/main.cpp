#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <functional>


#include <filesystem>

// Implementing the unique pointer in cpp

template <typename T>
class Unique_Pointer {
    private:
        T* ptr_;

    public:

         /* Constructor */
        //using explicit keyword for safety
        //using the list init
        explicit Unique_Pointer(T *ptr = nullptr) : ptr_(ptr) {}
        //This can be written as Unique_pointer(T *ptr = nullptr) {ptr_ = ptr;}   


        /* Destructor */
        ~Unique_Pointer(){
            delete ptr_;
        }




        //Removing the copy constructor, if the Copy constrctor is working it's not a uniqe pointer :)
        Unique_Pointer(const Unique_Pointer<T>&) = delete;
        
        //removing the copy assignment operator as well cuz we don't want any replicas
        Unique_Pointer<T>& operator=(const Unique_Pointer<T>&) = delete;







        /* NOTE the move constructor is only used when creating the object from another one */
        //  move constructor by using the && operator of the rvalue reference to move the ownership
        /* Taking the (other) ptr and put it in the tmp ptr -> (ptr_) and then delete (other)  */
        Unique_Pointer(Unique_Pointer<T>&& obj) : ptr_(other.ptr){
            other.ptr_ = nullptr;
        }




        //Move assignment operator, it's used with the '=' normally

        Unique_Pointer& operator =(Unique_Pointer<T>&& other){
            //Other is the object wich will be moved!!!!!

            //but here we need to make el lllll check firrrst
            if(this = other){
                cerr << "Wrong usage of self assignment!!";
            } else if(this != other){

               delete ptr_;
               ptr_ = other.ptr_;
               other.ptr_ = nullptr;


            }else{}

            return *this;
            

        }

        // Dereference
        //should return by reference to give the ability to the user to edit on the values of the poitners
        T& operator*(){
            return *ptr_
        }

        
        T* operator->(){
            return ptr_
        }
            



         // Release ownership
        T* release() {
            T* temp = ptr;
            ptr = nullptr;
            return temp;
        }


        // Reset the pointer
        void reset(T* p = nullptr) {
            delete ptr;
            ptr = p;
        }





        



};



int main(){
    std::filesystem path 



}