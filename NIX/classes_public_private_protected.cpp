// any mistakes?
#include <iostream>

class Base {
public:
	int m_public;
private:
	int m_private;
protected:
	int m_protected;
};
class Derived : public Base {
	void f() {
		m_public = 1;
		m_private = 1;
		m_protected = 1;
	}
};
class Another
{
public:
	Base base;
	void f() {
		base.m_public = 1;
		base.m_private = 1;
		base.m_protected = 1;
	}
};

int main() {
	return 0;
};