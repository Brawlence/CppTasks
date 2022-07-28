// https://leetcode.com/problems/transpose-matrix/

#include <vector>

using namespace std;

class Solution {
public:
    /*vector<vector<int>> transpose_equidimentional(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m-1; i++) {
            for (int j = 0; j < n; j++) {
                if (j <= i) j = i+1;
                std::iter_swap(&matrix[i][j], &matrix[j][i]);
            }
        }
        return matrix;
    }*/
    
    vector<vector<int>> transpose(const vector<vector<int>>& matrix) {

        
        vector<vector<int>> result(matrix[0].size(), vector<int>(matrix.size()));
        
        for (int i = 0; i < matrix[0].size(); i++)
            for (int j = 0; j < matrix.size(); j++)
                result[i][j] = matrix[j][i];
        
        return result;
    }
};