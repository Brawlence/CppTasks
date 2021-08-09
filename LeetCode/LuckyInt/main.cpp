// https://leetcode.com/problems/find-lucky-integer-in-an-array/
// this is a complimentary support file which handles user input and output
// for the solution (defined in solution.hpp) to work

#include <cstdio>
#include <vector>
#include "solution.hpp"

Solution intmapper;

int main() {

	std::vector<int> integers = {1, 2, 3, 2, 3, 3, 4, 6, 10, 10, 10, 10, 5, 5, 5, 5, 6, 7, 6, 6, 10, 6, 6, 6, 6, 6, 8, 9, 10, 10, 10, 10};

	
	printf("The lucky number is: %i", intmapper.findLucky(integers));

	getchar();

	return 0;
}