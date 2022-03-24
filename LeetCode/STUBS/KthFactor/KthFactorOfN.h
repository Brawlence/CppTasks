// https://leetcode.com/problems/the-kth-factor-of-n/

class Solution {
public:
    int kthFactor(int n, int k) {
        int totalFactors = 0;
        
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                totalFactors++;
                if (totalFactors == k) return i;
            }
        }
        return -1;
    }
};