// I don't actually remember what are we supposed to do with Multi
#include <iostream>

class Base1 {
public:
	int base2;
};
class Base2 {
public:
	int base1;
};
class Multi : public Base1, public Base2 {

};

int main() {
	// ???
};