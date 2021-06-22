// https://leetcode.com/problems/1-bit-and-2-bit-characters/
// this is a complimentary support file which handles user input and output
// for the solutions (defined in solution.hpp) to work

#include <iostream>
#include <string>
#include <vector>
#include <ctime> // time

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

void reportResult (const char * reporteeName, bool & result) {
	cout << endl << reporteeName << " reports: ";
	if (result) {
		cout << "The last character of this sequence is one-bit\n";
	} else {
		cout << "The last character of this sequence is two-bits\n";
	}
}

int main() {
	CAT_PROFILE();
	srand(time(0));
	string input = " ";
	vector<int> bits;
	
	cout << "\nGenerate a vector?\nY/N:" << endl;
	auto temp = cin.get();
	if (temp == 'Y' || temp == 'y') {
		cout << "Enter a power of two (INT):";
		auto temp_power = 0;
		cin >> temp_power;
		temp_power = 2 << temp_power;
		cout << "\nGenerating the vector...\n";
		for (int i = 0; i < temp_power; i++) {
			bits.push_back(rand()%2);
		};
		bits.push_back(0);
	} else {
		cin.get();
		cout << "Enter the bit string to reinterpret.\nAllowed values: 1/0 T/F t/f:\n_";
		cin >> noskipws >> input;

		strToVector(input, bits);

		cout << "\nReinterpreted string as vector<int>:\n";
		printVector(bits);
	}
	

	cin.get();

	bool result1;
	{
		CAT_PROFILE_SCOPE("Bactracker loop");
		Solution backtracker;
		result1 = backtracker.isOneBitCharacter(bits);
	}
	reportResult("Backtracker", result1);

	bool result2;
	{
		CAT_PROFILE_SCOPE("While loop");
		SolutionWhileLoop whileLoop;
		result2 = whileLoop.isOneBitCharacter(bits);
	}
	reportResult("While loop", result2);

	bool result3;
	{
		CAT_PROFILE_SCOPE("For loop");
		SolutionForLoop forLoop;
		result3 = forLoop.isOneBitCharacter(bits);
	}
	reportResult("For loop", result3);

	cin.get();

	return 0;
}
