// https://leetcode.com/problems/binary-search/
// this is a complimentary support file which handles user input and output
// for the solutions (defined in solution.hpp) to work

// using cpp-style input and output with streams
// line output is made using cout/puts(), input is cin/gets() and pauses are dupplicate cin reads
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "solution.hpp"

void printVector (vector<int> &bits) {
	for (auto it = begin(bits); it!=end(bits); ++it) {
		cout << *it << " ";
	}
	cout << endl;
};

int main() {

	std::vector<int> integers = {1, 2, 3, 4, 6, 10, 15, 16, 18, 20, 310, 410};

	printVector(integers);
	cout << endl;

	Solution semiBisect;

	cout << "Hehheheheheheheh what are you searching: ";

	int target;

	cin >> target;

	cout << endl << "target index: " << semiBisect.search(integers, target);;

	cin >> target;
	
	return 0;
};