// https://leetcode.com/problems/first-bad-version/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
extern bool isBadVersion(int version);

// O(log(n)) handler via binary search
class Solution {
public:
	int firstBadVersion(int n) {
		if (isBadVersion(1)) return 1; // the entire tree is rotten
		int lastKnownGV = 1;           // last known good version
		int middlepoint = n/2;         // the current suspect
		for (;;) {
			// return logic
			if (!isBadVersion(n - 1)) return n;
			
			// search logic
			if (isBadVersion(middlepoint)) {
				// discard all the versions higher than middlepoint
				n = middlepoint;
				middlepoint = middlepoint / 2;
			} else {
				// mark versions prior to middlepoint as good
				lastKnownGV = middlepoint;
				middlepoint = lastKnownGV + (n - middlepoint)/2;
			};           
		};
	}
};


// naive O(n) handler
class SolutionNaive {
public:
	int firstBadVersion(int n) {
		if (isBadVersion(1)) return 1; // the entire tree is rotten

		for (;;) {
			// return logic
			if (!isBadVersion(n - 1)) return n;
			
			// search logic
			n--;
		};        
	}
};