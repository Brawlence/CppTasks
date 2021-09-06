// https://leetcode.com/problems/valid-mountain-array/submissions/
// testcases I had initially used: 
// [2,1]
// [3,5,5]
// [0,3,2,1]
// [0,1,2,3,4,5,6,7,8,9] - failed
// [9,8,7,6,5,4,3,2,1,0] - failed
// [1,1,1,1,1,1,1,2,1] - failed

#include <vector>

class Solution {
public:    
	bool validMountainArray(const std::vector<int>& arr) {
		//ios_base::sync_with_stdio(false);
		//cin.tie(NULL);
		int size = arr.size();
		if (size < 3) return false;
		
		bool inflected = false;
		
		for (int i = 1; i < size - 1; i++) {
			auto left_derivative = (arr[i] - arr[i-1]);
			auto right_derivative = (arr[i+1] - arr[i]);
			
			if (!inflected 
				&& 
				(left_derivative > 0)
				&&
				(right_derivative <= 0)) inflected = true;
				
			if (left_derivative <= 0 && !inflected) return false;
			if (right_derivative >= 0 && inflected) return false;
			
		}
		
		return inflected && true;
	};
};