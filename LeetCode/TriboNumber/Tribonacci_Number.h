// https://leetcode.com/problems/n-th-tribonacci-number/submissions/
// TODO: implement MEMOIZATION to recursive algos

class Solution {    
public:
	int tribonacci(int n) {
		return trib_iterative(n); // just select whatever you need
	};
	
	int trib_iterative(int n) {
		int TR_0 = 0;
		int TR_1 = 1;
        int TR_2 = 1;
		int next, current, previous, evenearlier;
		switch (n) {
			case 0:	return TR_0;
			case 1:	return TR_1;
            case 2:	return TR_2;
			default:
				current = TR_2;
				previous = TR_1;
                evenearlier = TR_0;
				for (int i = 3; i <= n; i++) {
					next = evenearlier + previous + current;
					evenearlier = previous;
                    previous = current;
					current = next;                    
				}
				return next;
		};
	};
	
	int trib_recursive_switch(int n) {
		switch (n) {
			case 0: return 0;
			case 1:
            case 2: return 1;
			default:
				return trib_recursive_switch(n-3) + trib_recursive_switch(n-2) + trib_recursive_switch(n-1);
		};
	};

	int trib_recursive_if(int n) {
		if (n <= 0) return 0;
		if (n <= 2) return 1;
		return trib_recursive_if(n-3) + trib_recursive_if(n-2) + trib_recursive_if(n-1);
	};
};