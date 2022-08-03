// https://leetcode.com/problems/number-of-lines-to-write-string/

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int numOfLines = 1;
        int accumulator = 0;
        
        for (char c : s) {
            accumulator += widths[c-'a'];
            if (accumulator > 100) {
                accumulator = widths[c-'a'];
                numOfLines++;
            }
        };
        
        vector<int> result = {numOfLines, accumulator};
        return result;
    }
};