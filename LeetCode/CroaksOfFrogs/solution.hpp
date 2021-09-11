// https://leetcode.com/problems/minimum-number-of-frogs-croaking/

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int len = croakOfFrogs.length();
        if (croakOfFrogs[0]!='c'||croakOfFrogs[len-1]!='k') return -1;

        int map[5] = {0};
        int repeat_count = 0;
        
        for (int i = 0; i < len; i++) {
            switch (croakOfFrogs[i]) {
                case 'c':
                    map[0]++;
                    if (map[4] && repeat_count < map[4]) repeat_count++;
                    break;
                case 'r':
                    map[1]++;
                    break;
                case 'o':
                    map[2]++;
                    break;
                case 'a':
                    map[3]++;
                    break;
                case 'k':
                    map[4]++;
                    break;
                default:
                    return -1;
            };
        };
        
        if ((map[0] | map[1] | map[2] | map[3] | map[4]) 
            !=
            (map[0] & map[1] & map[2] & map[3] & map[4])) return -1;
        
        return map[0] - repeat_count;
    }
};