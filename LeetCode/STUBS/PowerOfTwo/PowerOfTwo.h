// https : //leetcode.com/problems/power-of-two/

class Solution {
public:
	bool isPowerOfTwo(const int n) {
		if (n <= 0) return false;

		return !(n & (n - 1));
	}
};