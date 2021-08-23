// https://leetcode.com/problems/find-lucky-integer-in-an-array/

#define ALPHABET_LENGTH 500

#include <vector>

class Solution {
public:
    int findLucky(std::vector<int>& arr) {
        
        int intmap[ALPHABET_LENGTH + 1]={0};
        
        int size = arr.size();
        for (int i = 0; i < size; i++) {
            intmap[arr[i]]++;
        }
        
        for (int i = ALPHABET_LENGTH; i > 0; --i) {
            if (intmap[i] == i) return i;
        }
        return -1;
    }
};