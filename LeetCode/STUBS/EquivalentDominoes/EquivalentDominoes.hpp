// https://leetcode.com/problems/number-of-equivalent-domino-pairs/

class Solution {
public:
	
	int numEquivDominoPairs(vector<vector<int>>& dominoes) {
		// 1 2 3 4 5 6  7  8  9
		// ↓
		// 1 2 3 5 7 11 13 17 19
		int prime[10] = {0, 1, 2, 3, 5, 7, 11, 13, 17, 19};
		
		int hash[362] = {0};
		
		for (auto domino : dominoes) {
			hash[prime[domino[0]]*prime[domino[1]]]++;
		};
		
		int result = 0;
		
		for (int i = 0; i < 362; i++) {
			if (hash[i] > 1) {
				result = result + hash[i]*(hash[i] - 1)/2;
			};
		};

		return result;
	}
};