//https://leetcode.com/problems/number-of-good-ways-to-split-a-string/

class Solution {
public:
    int numSplits(string s) {
        int len = s.length();
        if (len < 2) return 0;
        int left[26] = {}, right[26] = {};
        int result = 0, volumeL = 0, volumeR = 0;
        
        for (int i = 0; i < len; i++) {
            right[s[i]-'a']++;
            if (right[s[i]-'a'] == 1) volumeR++;
        };
        
        for (int delim = 1; delim < len; delim++) {
            
            right[s[delim-1]-'a']--;
            if (right[s[delim-1]-'a'] < 1) volumeR--;
            
            left[s[delim-1]-'a']++;
            if (left[s[delim-1]-'a'] == 1) volumeL++;
            
            if (volumeR == volumeL) result++;            
        }
        
        return result;
    }
};