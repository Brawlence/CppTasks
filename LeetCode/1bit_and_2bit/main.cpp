// https://leetcode.com/problems/1-bit-and-2-bit-characters/
// this is a complimentary support file which handles user input and output
// for the solutions (defined in solution.hpp) to work

#include <iostream>
#include <string>
#include <vector>

#include "catprofiler.hpp"

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
	CAT_PROFILE();
	string input = " ";
	vector<int> bits;
	
	cout << "Enter the bit string to reinterpret.\nAllowed values: 1/0 T/F t/f:\n_";
	cin >> noskipws >> input;

	strToVector(input, bits);
	
	cout << "\nReinterpreted string as vector<int>:\n";
	printVector(bits);

	cin.get();

	bool result1;
	{
		CAT_PROFILE_SCOPE("while loop");
		Solution whileLoop;
		result1 = whileLoop.isOneBitCharacter(bits);
	}
	if (result1) {
		cout << "\nThe last character of this sequence is one-bit";
	} else {
		cout << "\nThe last character of this sequence is two-bits";
	}

	bool result2;
	{
		CAT_PROFILE_SCOPE("for loop");
		SolutionForLoop forLoop;
		result2 = forLoop.isOneBitCharacter(bits);
	}
	if (result2) {
		cout << "\nThe last character of this sequence is one-bit";
	} else {
		cout << "\nThe last character of this sequence is two-bits";
	}

	cin.get();

	return 0;
}
