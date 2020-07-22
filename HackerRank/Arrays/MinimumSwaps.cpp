#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

// Returns the minimum required swaps
int minimumSwaps(vector<int> arr) {
    bool visited[arr.size()] = {false};
    int count = 0;
    /* for every a occupying b's place, b occupying c's place and so on exists integer x such as: x occupies a's place.
    Such n-length loop can be ordered with n-1 swaps.
    */
    
    // Find those loops.
    // Select an element
    for (int i = 0; i < arr.size(); i++){
        //skip elements on their rightful places and the ones we've already passed
        if (arr[i] != i+1 && !visited[i]){
            //and try to acess the size of the loop
            for(int j = arr[i]-1;!visited[j];){
                visited[j]=true;
                j = arr[j]-1;
                count++;
            };
            count--;            
        }else if (arr[i] == i+1){
            visited[i]=true;
        };
    };
    return count;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int res = minimumSwaps(arr);

    cout << res << "\n";
    return 0;
}

