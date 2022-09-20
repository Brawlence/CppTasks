// https://leetcode.com/problems/reverse-only-letters/

// two pointers with skip for non-alphanumeric
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int lhs = 0, rhs = s.size()-1;

        while (lhs < rhs) {
            while (!isalpha(s[lhs]) && lhs < rhs) lhs++;
            while (!isalpha(s[rhs]) && lhs < rhs) rhs--;
            
            swap(s[lhs], s[rhs]);
            lhs++;
            rhs--;
        }

        return s;
    }
};