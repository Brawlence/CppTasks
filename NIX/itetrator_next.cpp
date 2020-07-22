// any mistakes?

int main(void)
{
	int i = 0;
	i++ = 5; // this one is wrong
	++i = 5; // this will work only if operator++ returns non-const & 

	return 0;
}