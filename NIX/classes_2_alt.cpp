// stdout?
#include <iostream>

class A {
public:
	void f() {std::cout<<"A";}
	void g() {f();}
};
class B : public A {
public:
	B() {};
	B(A &a) {};
	virtual void f() {std::cout<<"B";}
};

int main() {
	A a; A *pA; B b;
	b.g();
	pA=&b; pA->g();
	a=b; a.g();
	b=a; b.g();
};