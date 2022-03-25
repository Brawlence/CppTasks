// https://leetcode.com/problems/merge-sorted-array/

class Solution {
public:
	void merge(vector<int>& nums1, int m, const vector<int>& nums2, int n) {
		assert(nums1.size()-n == m && nums2.size() == n);
		m--;n--;
		std::for_each(nums1.rbegin(), nums1.rend(), 
		[&](int &element)
		{
			if (n >= 0 and m >= 0 and nums1[m] >= nums2[n]) {
				element = nums1[m--];
			}
			else if (n >= 0) {
				element = nums2[n--];
			}
					
		}
		);

	}
};