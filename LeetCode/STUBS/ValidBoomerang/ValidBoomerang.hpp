// https://leetcode.com/problems/valid-boomerang/

#include <vector>

using namespace std;

class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        #define Δx1 (points[1][0] - points[0][0])
        #define Δy1 (points[1][1] - points[0][1])
        #define Δx2 (points[2][0] - points[1][0])
        #define Δy2 (points[2][1] - points[1][1])
        
        bool hasDeltaOne = ( Δx1 || Δy1 );
        bool hasDeltaTwo = ( Δx2 || Δy2 );
            
        bool nonColinear = ( Δx1 * Δy2 != Δx2 * Δy1);
        
        //cout << "delta1 " << hasDeltaOne << " delta2 " << hasDeltaTwo << " nonCol " << nonColinear << endl;
        return (hasDeltaOne && hasDeltaTwo && nonColinear);
    }
};