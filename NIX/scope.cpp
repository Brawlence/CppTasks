// stdout?
#include <iostream>

int main(void)
{
	int i = 0;
	while (i < 10) {
		int i = 10;
		std::cout<<i<<'\t';
		i++;
	}
	return 0;
}