// https://leetcode.com/problems/move-zeroes/

#include <algorithm>
#include <vector>

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        auto t = std::remove(nums.begin(), nums.end(), 0);
        std::fill(t, nums.end(), 0);
    }
};