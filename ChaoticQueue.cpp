#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Solve for minimum amount of bribes (max of 2 per persone) to happen for this state to occur
// Probably useful to check the minimum swaps (last excersise) code

/*
1 2 3 4<5 6 7 8 9
1 2 3 5 4 6<7 8 9
1 2 3 5 4 7 6<8 9
1 2 3<5 4 7 8 6 9
1 2 5 3 4<7 8 6 9
1 2 5 3 7 4<8 6 9
1 2 5 3 7 8 4<6 9
1 2 5 3 7 8 6 4 9

*/
// forward bribe for i th element manages to separate (i-2) and (i-1) th elements with no more than 1 step
// IF some element k was separated from its k+1 neighbour by more than 1 - some kind of bamboozlement was afoot

void minimumBribes(vector<int> q) {
    int bribesOccured = 0;
    bool overBribeDetected = false;
    int temp = 0;

    //For every member of the queue, sequental integer swaps can lead to keeping his place
    for (int i = 0; i < q.size(); i++) {
        if (q[i] != i + 1) { // member is not on its position
            if (q[i] > i + 3) { overBribeDetected = true; }; //forward displacement is bigger than 2, overbribe
            if (q[i] > q[i+1]) { //mama I am sorting
                for (int k = i+1; q[k] != k+1; k--) {
                    temp = q[k-1];
                    q[k-1] = q[k];
                    q[k] = temp;
                    bribesOccured++;
                    i = k-2;
                };
            };
        };
    }; 

    // outputting the number if no overbribes detected
    if (!overBribeDetected) {
        cout << bribesOccured << endl;
    } else {
        cout << "Too chaotic" << endl;
    };
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string q_temp_temp;
        getline(cin, q_temp_temp);

        vector<string> q_temp = split_string(q_temp_temp);

        vector<int> q(n+5);

        for (int i = 0; i < n; i++) {
            int q_item = stoi(q_temp[i]);

            q[i] = q_item;
        }

        minimumBribes(q);
    }

    return 0;
}

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
