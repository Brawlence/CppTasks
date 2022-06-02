//------------------------------------------------------------------------------
// 7.
//
// (7a)
// An object foo is written to a new file on platform 1 as:
write( file, &myFoo, sizeof(struct foo) );

// ...and then read on platform 2 using:
read(file, &myFoo, filesize(file) );

// The foo object has the following definition:
struct foo
{
	char a;
	int b;
	long c;
	char* d;
};

// What kind of issues might arise when loading foo on platform 2? [6 marks]

// (7b)
// You are writing a unit test to confirm the correctness of a function which
// takes 3 float values as arguments. You decide to stress test it by testing
// 1000000 'random' inputs.
// You find that the function will fail, but very rarely, so you include code
// to print out all failure cases, hoping to grab a simple repro case which you
// can debug into.
// Note: All code here is run in a single-threaded environment.
	//...
	// Some code sets a,b,c
	//...
	if ( testPasses(a,b,c) )
	{
		printf("Pass\n");
	}
		else // someFunc fails, print the values so we can reproduce
	{
		printf("Fail: %f %f %f\n", a, b, c);
	}

// where testPasses has the following signature and executes deterministically
// with no side effects:
bool testPasses(float f1, float f2, float f3);

void testRepro()
{
	float a = // fill in from value printed by above code
	float b = // fill in from value printed by above code
	float c = // fill in from value printed by above code
	bool result = testPasses(a,b,c);
};

// Surprisingly, when you type in the 3 values printed out in testRepro()
// the test does not fail!
// Modify the original code and test bed to reproduce the problem reliably. [4 marks]