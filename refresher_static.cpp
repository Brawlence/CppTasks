#include "stdio.h"

class TestClass {
	private:
		static int amount;
	public:
		int self_number;
		int always_one;
		int counter;
		static int static_counter;

	TestClass(){
		printf("An object has been init with ID #%i\n", ++amount);
		self_number = amount;
		always_one = 1;
	};

	void set_zero() {
		printf("#%i has been set to zero\n", self_number);
		counter = 0;
		static_counter = 0;
	};
	
	void increment() {
		printf("#%i has recieved increment\n", self_number);
		counter += 1;
		static_counter += 1;
	};
	
	void report(){printf("#%i state is: %i, %i, %i\n", self_number, always_one, counter, static_counter);};
};

using namespace std;

int TestClass::amount = 0;
int TestClass::static_counter;
TestClass article;
TestClass article2;

int main () {
	
	article.increment();
		article.report();
		article2.report();
	article.set_zero();
		article.report();
		article2.report();

	article.increment();
		article.report();
		article2.report();

	printf("Incrementing a static variable externally...\n");
	TestClass::static_counter = TestClass::static_counter * 2;
		article.report();
		article2.report();

	return 0;
};