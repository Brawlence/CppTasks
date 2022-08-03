// https://leetcode.com/problems/special-positions-in-a-binary-matrix/

#include <vector>

using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int vertControl[100]={0};
        int horzControl[100]={0};
        int specialCount = 0;
        
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) {
                vertControl[i] += mat[i][j];
                horzControl[j] += mat[i][j];
            }

        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) 
            specialCount += (mat[i][j] && horzControl[j] == 1 && vertControl[i] == 1);

        return specialCount;
    }
};