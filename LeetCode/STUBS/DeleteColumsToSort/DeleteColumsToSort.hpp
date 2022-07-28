//https://leetcode.com/problems/delete-columns-to-make-sorted/

class Solution {
public:
	int minDeletionSize(vector<string>& strs) {
		int strLen = strs[0].length();
		int strs_size = strs.size();
		int deleted = {0};
		for (int i = 0; i < strLen; i++) {
			
			for (int j = 0; j < strs_size-1; j++) {
				if (strs[j].at(i) <= strs[j+1].at(i)) {
					continue;  
				} else {
					++deleted;
					break;
				};

			};
			
		};
		return deleted;
	}
};