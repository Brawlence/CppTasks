// https://leetcode.com/problems/move-zeroes/
// this is a complimentary support file which handles user input and output
// for the solution (defined in solution.hpp) to work

#include <iostream>
#include <string>
#include <vector>

#include "solution.hpp"

using namespace std;

void strToVector (string &input, vector<int> &bits) {
	for (auto it = begin(input); it!=end(input); ++it) {
		switch (*it) {
			case '0':
			case 'F':
			case 'f':
				bits.push_back(0);
				break;
			
			case '1':
			case 'T':
			case 't':
				bits.push_back(1);
				break;

			default:
				break;
		}
	};
};

void printVector (vector<int> &bits) {
	for (auto it = begin(bits); it!=end(bits); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}

int main() {
	string input = " ";
	vector<int> nums;
	
	cout << "Enter the bit string to reinterpret.\nAllowed values: 1/0 T/F t/f:\n_";
	cin >> noskipws >> input;

	strToVector(input, nums);
	
	cout << "\nReinterpreted string as vector<int>:\n";
	printVector(nums);

	cin.get();

	Solution moveZeroes;
	printVector(nums);

	cin.get();

	return 0;
}
