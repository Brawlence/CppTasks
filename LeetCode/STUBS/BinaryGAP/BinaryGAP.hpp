// https://leetcode.com/problems/binary-gap/

#include <climits>

#define MAXS(a, b) (a - ((a - b) & ((a - b) >> (sizeof(int) * CHAR_BIT - 1))))

class Solution {
public:
    int binaryGap(int n) {
        if ((n & (n - 1)) == 0) return 0; // zero and powers of two
        
        int maxSpace = 0;
        int tz = __builtin_ctz(n);
        
        n = n >> tz;
        
        while (n > 1) {
            tz = __builtin_ctz(n);
            maxSpace = MAXS(maxSpace, tz);
            n = n >> MAXS(1, tz); // eat the LSD 1 if it's there or shift away all the 0
        };
        
        return maxSpace+1;
    }
};