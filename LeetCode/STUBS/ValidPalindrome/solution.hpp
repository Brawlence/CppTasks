// https://leetcode.com/problems/valid-palindrome/

class Solution {
public:
	bool isPalindrome(string s) {
		auto first = s.begin();
		auto last = s.end() -1;
		
		while (first < last) {
			while (!iswalnum(*first) && first < last) first++;
			while (!iswalnum(*last)  && first < last) last--;
			
			if (tolower(*first++) != tolower(*last--)) return false;
		};
		
		return true;
	};
};