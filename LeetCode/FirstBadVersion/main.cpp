// https://leetcode.com/problems/first-bad-version/
// this is a complimentary support file which handles user input and output
// for the solutions (defined in solution.hpp) to work

#include <cstdio>

#include "solution.hpp"

int maxVersion = 1; // the current version
int knownFBV = 1; 	 // known First Bad Version

// simulating the provided API
bool isBadVersion(int n) {
	return (n >= knownFBV);
}

int main() {
	Solution fast_Log;
	SolutionNaive slow_Linear;
	printf("Testing binary search vs naive decrement\nEnter the most recent version of software (solutions will start their search from here) -- integer:\n");
	scanf("%i", &maxVersion);
	printf("Enter the known first bad version (the right answer, solutons won't have access to it) -- also integer):\n");
	scanf("%i", &knownFBV);

	getchar();

	printf("result (binsearch): %i\n", fast_Log.firstBadVersion(maxVersion));

	getchar();

	printf("result (decrement): %i\n", slow_Linear.firstBadVersion(maxVersion));

	getchar();

	return 0;
}
