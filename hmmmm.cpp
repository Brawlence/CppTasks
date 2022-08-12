#include <vector>
#include <iostream>

class Solution {
public:
    bool canWinNim(int n) {
        if(n<4) return true;

        std::vector<int> step(16);
        step[1]=1;
        step[2]=1;
        step[3]=1;
        step[4]=0;
        for(int i = 5; i <= n; i++) {
            int curr = i;
            int min1 = i - 1;
            int min2 = i - 2;
            int min3 = i - 3;
            step[curr%16] = !(step[(min1)] && step[min2] && step[min3]);
        }
            
        return step[n%16];
    }
};

int main () {

    int n;
    Solution Pl;

    std::cout << "Input n:\n";

    std::cin >> n;

    // for (int t = 0; t <= n; t++) std::cout << "\nN: " << t << " - " << Pl.canWinNim(t);
    std::cout << "\nN: " << n << " - " << Pl.canWinNim(n);

    std::cin.get();
    return 0;
}