// stdout?
#include <iostream>

class Base {
public:
	void virtual f() {std::cout<<"A";}
};
class Derived : public Base {
public:
	void virtual f() {std::cout<<"B";}
};

int main() {
	Derived o1;
	Base *p1 = new Derived;
	o1.f(); p1->f();
};