// https://leetcode.com/problems/1-bit-and-2-bit-characters/

// Backtracking solution
class Solution {
public:
	bool isOneBitCharacter(std::vector<int>& bits) {
		int size = bits.size(), i = size - 1;
		if (bits.at(i) == 0) return true;
		while ((i > 0) && (bits.at(i-1) == 1)) {
			i--;
		}
		return (size+1-i)%2;
	}
};

// WHILE loop solution
class SolutionWhileLoop {
public:
	bool isOneBitCharacter(std::vector<int>& bits) {
		int i = 0, size = bits.size();
		while (i < size) {
			if (bits[i] == 1) {
				i = i + 2;
			} else {
				if (i == size - 1) return true;
				i = i + 1;
			}
		}
		return false;
	}
};


// The original FOR loop solution
class SolutionForLoop {
public:
	bool isOneBitCharacter(std::vector<int>& bits) {
		int i = 0, size = bits.size();
		while (i < size) {
			if (bits[i] == 1) {
				i = i + 2;
			} else {
				if (i == size - 1) return true;
				i = i + 1;
			}
		}
		return false;
	}
};