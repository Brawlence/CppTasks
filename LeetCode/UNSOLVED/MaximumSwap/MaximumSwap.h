// https://leetcode.com/problems/maximum-swap/

class Solution {
public:
    int pow(const int num, const int pow) {
        int result = 1;
        int i = 0;
        while (i < pow) {
            result = result * num;
            i++;
        };
        return result;
    };
    
    int naiveMaxPowOfTen(const int num) {  
        return (num < 10 ? 0 
                :   
               (num < 100 ? 1 
                :   
               (num < 1000 ? 2 
                :   
               (num < 10000 ? 3 
                :   
               (num < 100000 ? 4 
                :   
               (num < 1000000 ? 5 
                :   
               (num < 10000000 ? 6 
                :  
               7)))))));
    };

    int digitAt(const int powerOfTen, const int number) {
        return number / pow(10, powerOfTen) % 10;
    };
    
    void swap(const int firstPos, const int secondPos, int &num) {
        if (firstPos != secondPos) {
            const int firstDigit = digitAt(firstPos, num);
            const int secondDigit = digitAt(secondPos, num);
            num = num + pow(10, firstPos) * (secondDigit - firstDigit);
            num = num + pow(10, secondPos) * (firstDigit - secondDigit);
        };
    };
    
    int maximumSwap(int num) {
        if (num > 99999999 || num < 10) return num;
        if ((num < 100) && (num % 10)) {swap(0,1, num); return num;}
            
        int first = naiveMaxPowOfTen(num);
        while (first > 0 && digitAt(first, num) == 9) first--; // skip the 9s
        
        // ! The problem is located somewhere around this block
        int second = -1;
        int maxDig = -1;
        int maxPos = -1;
        do {
            int currentDig;
            while (second < first) {
                second++;
                currentDig = digitAt(second, num);
                if (currentDig == 9) { // 9 is the highest there is
                    maxPos = second;
                    break;
                };
                if (currentDig > maxDig) {
                    maxDig = currentDig;
                    maxPos = second;
                };
            };
            if (maxDig > digitAt(first, num)) {
                break;
            } else {
                first--;
                second = -1;
                maxDig = -1;
                maxPos = -1;
            };
        } while (second != first);
        second = maxPos;
        // ! The problem is located somewhere around this block
		
        cout << first << ": digit " << digitAt(first, num) << " → " << second << ": digit "  << digitAt(second, num) << endl;
        
        swap(first, second, num);
        
        return num;
    };
};