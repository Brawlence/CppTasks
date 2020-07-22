// any mistakes?

int main(void)
{
	const int * p1 = 0;
	int const * p2 = 0;
	int * const p3 = 0;

	 p1 = 0;
	*p1 = 0;
	 p2 = 0;
	*p2 = 0;
	 p3 = 0;
	*p3 = 0;

	return 0;
}