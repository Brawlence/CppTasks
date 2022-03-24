// https://leetcode.com/problems/binary-search/

class BisectSolution {
public:
	int search(vector<int>& nums, int target) {
		int high = nums.size() - 1;
		int mid;
		int low = 0;
		while (low <= high) {
			mid = ( low + high ) >> 1;
			if (nums[mid] == target) return mid;
			if (target < nums[mid]) {
				high = mid - 1; // mid was already checked, so assign the one before it
			} else {
				low = mid + 1; // mid was already checked, so assign the one above it
			}
		}
		return -1;
	}
};

class SemiBisectSolution {
public:
	int halve(int k) {
		if (k < 2) return 0;
		if ( k%2 != 0 ) {
			return ((k + 1)/ 2);    
		} else {
			return (k / 2);
		};
	};

	int search(vector<int>& nums, int target) {
		int size = nums.size();
		int index = size - 1;
		int halvedInd = halve(index);
		
		while (nums[halvedInd] > target && index > 0) {
			index = halvedInd;
			halvedInd = halve(halvedInd);
		};
			
		// either the target is higher than halvedIndex, or we reached 0
		
		if (nums[index] == target) return index;
		if (nums[halvedInd] == target) return halvedInd;
		
		while (halvedInd + 1 < size) {
			halvedInd++;            
			if (nums[halvedInd] == target) return halvedInd;
		};
		
		return -1;
	}
};

class Solution : public SemiBisectSolution {

};