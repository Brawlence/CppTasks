#include <bits/stdc++.h>

using namespace std;

long howmAyyny(string s, long n)
{
    if (n==0){return 0;};
    if (s.length() > n){s.resize(n);};
    return count(s.begin(),s.end(),'a');
}

long repeatedString(string s, long n){
    long wholeparts = long ( (s.length() > n) ? (s.length() / n) : (n / s.length()) );
    return wholeparts * howmAyyny(s, n) + ( (s.length() > n) ? 0 :
    ( howmAyyny(s, n % s.length()) ) );
}


int main (){

    string s;
    getline(cin,s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    long result = repeatedString(s, n);

    cout << result;
    //cin >> n;
    return 0;
}

