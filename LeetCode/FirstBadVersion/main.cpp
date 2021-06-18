// https://leetcode.com/problems/first-bad-version/
// this is a complimentary support file which handles user input and output
// for the solutions (defined in solution.hpp) to work

#include <cstdio>

#include "solution.hpp"

int maxVersion = 1; // the current version
int knownFBV = 1; 	 // known First Bad Version

class Api { 
private:
	int api_calls_made;
public:
	bool isBadVersion(int n) {
		api_calls_made++;
		return (n >= knownFBV);
	};

	void setZero () {
		api_calls_made = 0;
	}

	int reportCalls () {
		return api_calls_made;
	}
};

static Api api_handler;

// simulating the provided API
bool isBadVersion(int version) {
	return api_handler.isBadVersion(version);
};

int main() {
	Solution fast_Log;
	SolutionNaive slow_Linear;
	printf("Testing binary search vs naive decrement\n\nEnter the most recent version,\nsolutions will start their search from this point:\nINT N = ");
	scanf("%i", &maxVersion);
	printf("\nEnter the known first bad version.\nThis is the right answer, solutons won't have access to it:\nINT firstBadVersion = ");
	scanf("%i", &knownFBV);

	getchar();

	int result = fast_Log.firstBadVersion(maxVersion);
	int callsAmount = api_handler.reportCalls();
	printf("\nBinsearch result: %i,\n calls to api: %i\n", result, callsAmount);

	getchar();
	api_handler.setZero();

	result = slow_Linear.firstBadVersion(maxVersion);
	callsAmount = api_handler.reportCalls();
	printf("Decrement result: %i,\n calls to api: %i\n", result, callsAmount);

	getchar();

	return 0;
}
