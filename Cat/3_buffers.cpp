//------------------------------------------------------------------------------
// 3.
//
// Explain the differences between buffer1, buffer2 and buffer3 in the
// example code below. Consider:
// i. Scope & Lifetime [4 marks]
// ii. Performance & use of system resources [6 marks]

char buffer1[512];

void func1()
{
	char buffer2[1024];
	//...
}

void func2()
{
	char* buffer3 = static_cast<char*> ( malloc(2048) );
	//...
}