// https://leetcode.com/problems/simplified-fractions/

#include <vector>
#include <string>
#include <numeric> //gcd 

using namespace std;

class Solution {
public:
	vector<string> simplifiedFractions(int denominator) {
		vector<string> fractions = {};
		vector<string> nums_as_string(denominator + 1);
		
		for (int i = 1; i <= denominator; i++) {
			nums_as_string[i] = to_string(i);
		};

		while (denominator > 1) {
			for (int nominator = denominator; nominator > 0; --nominator) {
				if (gcd(nominator,denominator) == 1) {
					fractions.emplace_back(nums_as_string[nominator]+"/"+nums_as_string[denominator]);
				};
			};
			--denominator;
		};
		
		return fractions;
	}
};