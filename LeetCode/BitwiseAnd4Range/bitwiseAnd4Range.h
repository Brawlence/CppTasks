// https://leetcode.com/problems/bitwise-and-of-numbers-range/
// https://leetcode.com/problems/bitwise-and-of-numbers-range/discuss/1426571/c-one-liner-using-obscure-x86-instruction-explained

class Solution : public OneLinerSolution {

};

class OneLinerSolution {
public:
	int rangeBitwiseAnd(const int left, const int right) noexcept {
		return (right == left) ? left : (left & right & (~((1 << (63 - __builtin_clzl(right - left))) - 1) * 2));
	};
};

class InitialSolution {
public:
	int rangeBitwiseAnd(const int left, const int right) noexcept {
		int diff = right - left;
		if (diff == 0) return left;

		int mask = diff;
		while (diff > 0) {
			mask |= mask >> 1;
			diff >>= 1;
		}
		mask = ~mask;

		return (left & right & mask);
	};
};