#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
// arr is 2D 0-5 indexed array
int hourglassSum(vector<vector<int>> arr) {
    vector<vector<int>> sasuga(4);
    int sum = 0;
    int temp_maximum = -800;
    for (int i = 1; i < 5; i++){
        for (int j = 1; j < 5; j++){
            //sasuga[i-1][j-1] 
            sum = arr[i-1][j-1] + arr[i-1][j] + arr[i-1][j+1] + arr[i][j] + arr[i+1][j-1] + arr[i+1][j] + arr[i+1][j+1];
            if (sum > temp_maximum){ temp_maximum = sum;}; 
        };
    };

    return temp_maximum;
};

int main()
{
    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        };

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    cout << result << "\n";

    return 0;
}
