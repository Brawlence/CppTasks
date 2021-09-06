// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/

class Solution {
public:
	int minMoves2(vector<int>& nums) {
		auto median = begin(nums) + nums.size() / 2;
		nth_element(begin(nums), median, end(nums));
		auto res = 0;
		for (auto e : nums) {
			res += abs(e - *median);
		}
		return res;
	}
};
