//https://leetcode.com/problems/slowest-key/

class Solution {
public:
	char slowestKey(vector<int>& releaseTimes, string keysPressed) {

		int size = releaseTimes.size();
		int longestDur = 0;
		int indexOfLongest = 0;
		int dur = 0;
		
		for (int i = 0; i < size; ++i) {
			dur = releaseTimes[i] - dur; 
			
			bool bigger = (dur > longestDur);
			bool equalButCooler = (dur == longestDur && keysPressed[i] > keysPressed[indexOfLongest]);
		   
			longestDur = bigger? dur : longestDur;
			indexOfLongest = (bigger||equalButCooler)? i : indexOfLongest;
			
			dur = releaseTimes[i];
		}
		return keysPressed[indexOfLongest];
	}
};