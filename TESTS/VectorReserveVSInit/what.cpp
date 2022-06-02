// using cpp-style input and output with streams
// line output is made using cout/puts(), input is cin/gets() and pauses are cin.get()
#include <iostream>
#include <vector>

#include "catprofiler.hpp"	// primitive in-house profiler

using namespace std;

int main() {
	CAT_PROFILE();
	
	cin.get();
	cout << "running...";
	{
		CAT_PROFILE_SCOPE("Declaration→Reserve loop");
        for (int i = 0; i < 10'000; ++i) {
            vector<int> heh1;
            heh1.reserve(100'000);
			for (int j = 0; j < i; j++) heh1.push_back(i);
        }
	}

	{
		CAT_PROFILE_SCOPE("Declaration+Initialization loop");
        for (int i = 0; i < 10'000; ++i) {
            vector<int> heh2(100'000,0);
			for (int j = 0; j < i; j++) heh2[j]=j;
        }
	}

	{
		CAT_PROFILE_SCOPE("Declaration loop with def init");
        for (int i = 0; i < 10'000; ++i) {
            vector<int> heh3(100'000);
			for (int j = 0; j < i; j++) heh3[j]=j;
        }
	}

	cin.get();

	return 0;
}
