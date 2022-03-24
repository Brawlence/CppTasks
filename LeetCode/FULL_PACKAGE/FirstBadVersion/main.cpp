// https://leetcode.com/problems/first-bad-version/
// this is a complimentary support file which handles user input and output
// for the solutions (defined in solution.hpp) to work

// using c-style input and output without streams
// line output is made using printf(), integer input is scanf() and pauses are getchar()
#include <cstdio> 

#include "solution.hpp"

// Simulating the statedly provided API of isBadVersion()

class ExistingApi {
private:
	int api_calls_made;
public:
	int knownFBV = 1;	// known First Bad Version

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

static ExistingApi api_handler;

bool isBadVersion(int version) {
	return api_handler.isBadVersion(version);
};

int main() {
	Solution fast_Log;
	SolutionNaive slow_Linear;
	printf("Testing binary search vs naive decrement\n\nEnter the most recent version,\nsolutions will start their search from this point:\nINT N = ");

	int maxVersion = 1;	// the current version
	scanf("%i", &maxVersion);
	printf("\nEnter the known first bad version.\nThis is the right answer, solutons won't have access to it:\nINT firstBadVersion = ");
	scanf("%i", &api_handler.knownFBV);

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
