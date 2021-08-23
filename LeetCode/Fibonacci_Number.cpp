// https://leetcode.com/problems/fibonacci-number/

class Solution {    
public:
    int fib(int n) {
        return fib_recursive(n); // just select whatever you need
    };
    
    int fib_iterative(int n) {
        int F_0 = 0;
        int F_1 = 1;
        int next, current, previous;
        switch (n) {
            case 0:
                return F_0;
                break;
            case 1:
                return F_1;
                break;
            default:
                current = F_1;
                previous = F_0;
                for (int i = 2; i <= n; i++) {
                    next = previous + current;
                    previous = current;
                    current = next;                    
                }
                return next;
        };
    };
    
    int fib_recursive_switch(int n) {
        switch (n) {
            case 0:
                return 0;
            case 1:
                return 1;
            default:
                return fib_recursive(n-2) + fib_recursive(n-1);
        };
    };

    int fib_recursive_if(int n) {
        if (n <= 0) return 0;
        if (n == 1) return 1;
        return fib_recursive_if(n-2) + fib_recursive_if(n-1);
    };
};