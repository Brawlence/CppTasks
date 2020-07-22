// my initial solution -- WRONG
// #define int int main(void){
// #define main(void) std::cout<<"Hello World";
// #define { ' '

// solution implies making a class with constructior writing to stdout
// and adding a global var to this code
// this task probably judges knowledge of Static Order Initialization Fiasco
#include <iostream>

class A {
public:
	A() {std::cout<<"Hello World!";}
};

A a;

// TASK BEGINS HERE
// this program with this main needs to write "Hello World!" to stdout
int main(void)
{
	return 0;
}