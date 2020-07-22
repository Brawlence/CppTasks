// stdout?
#include "iostream"

class A {
public:
	virtual void f() {std::cout<<"A";}
	virtual void g() {f();}
};
class B : public A {
public:
	B() {};
	B(A &a) {};
	void f() {std::cout<<"B";}
};

int main() {
	A a; A *pA; B b;
	b.g();
	pA=&b; pA->g();
	a=b; a.g();
	b=a; b.g();
};