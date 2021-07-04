//------------------------------------------------------------------------------
// 4.
//
// Choose any platform you want and describe what happens at machine level in the
// execution of the code below when func() is called. [8 marks]
// What changes if foo is inlined? [2 marks]

int foo( int a, int* b)
{
	return a + *b;
}

extern int x;

void func()
{
	int y = 7;
	int r;
	r = foo( x, &y );
	printf("%d\n", r);
}