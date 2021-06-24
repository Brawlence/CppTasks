// https://leetcode.com/problems/move-zeroes/
// this is a complimentary support file which handles user input and output
// for the solution (defined in solution.hpp) to work

#include <iostream>
#include <string>
#include <vector>

#include "solution.hpp"

using namespace std;

void printVector (vector<int> &bits) {
	for (auto it = begin(bits); it!=end(bits); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}

int main() {
	vector<int> nums = {0,110,101,0,1,0,29,20,123,23,4,1,8,121,5,1,1,8,12,3,5,1,0,213,5,1,0};
	
	cout << "\nVector<int>:\n";
	printVector(nums);

	cin.get();

	Solution moveZeroes;
	moveZeroes.moveZeroes(nums);
	printVector(nums);

	cin.get();

	return 0;
}
