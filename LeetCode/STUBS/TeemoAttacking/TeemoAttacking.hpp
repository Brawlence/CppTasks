// https://leetcode.com/problems/teemo-attacking/

#include <vector>

#define MIN(a,b) ( (a<=b) * a + (b<a) * b )

class Solution {
public:
    int findPoisonedDuration(std::vector<int>& timeSeries, int duration) {
        int total = 0, curr = 0, next = timeSeries[0];
        for (int i = 0; i < timeSeries.size() -1; i++) {
            curr = next;
            next = timeSeries[i+1];
            total += std::min(duration, (next - curr));
        }
        return total + duration;
    }
};