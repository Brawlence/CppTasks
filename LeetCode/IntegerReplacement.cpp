//https://leetcode.com/problems/integer-replacement/

class Solution {
public:
    int integerReplacement(int n) {
        if (n == INT_MAX) return sizeof(INT_MAX)*8;
        int steps = 0;
        while (n > 1) {
            if (n == 3) {steps+=2; return steps;};

            if (n%2 == 0) {
                //even
                n = n / 2;
            } else if ((n-1)/2 % 2 == 0) {
                //odd and does not have additional 1s lined up in higher digits
                n--;
            } else {
                //odd 
                n++;
            };              
            steps++;
        };
        return steps;
    }
};