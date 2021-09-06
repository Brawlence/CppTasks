// https://leetcode.com/problems/count-servers-that-communicate/submissions/

class Solution {
public:
	int countServers(vector<vector<int>>& grid) {
		int m = grid.size();
		if (!m) return 0;
		int n = grid[0].size();
		if (!n) return 0;
		
		vector<int> horizontalHashes(m, 0); 
		vector<int> verticalHashes(n, 0);
		int count = 0;
		
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j]) {
					horizontalHashes[i]++;
					verticalHashes[j]++;
				};
			};
		};
				
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if ((grid[i][j])
						&& 
					(horizontalHashes[i] > 1 || verticalHashes[j] > 1)) {
						count++;
					};
			};
		};
		
		return count;
	}
};