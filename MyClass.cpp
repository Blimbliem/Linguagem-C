#include <string>
#include <iostream>

class MyClass {
    public: 
    MyClass(){
        std::cout << "Hello World!";
    }
};

int main(){
    MyClass myObj;
    return 0;
}