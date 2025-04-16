// Author: huythedev (https://huythedev.com)
// Problem Link: https://codeforces.com/problemset/problem/118/A
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
#define ln "\n"
#define sz size()

typedef long long ll;
typedef long double ld;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void docfile() {
    if (ifstream(NAME ".INP")) {
        freopen(NAME ".INP", "r", stdin);
        freopen(NAME ".OUT", "w", stdout);
    }
}

void time() {
    cerr << ln << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." 
         << ln;
}

bool isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'o' || c == 'y' || c == 'e' || c == 'u' || c == 'i';
}

string processString(const string& s) {
    string result;
    for (char c : s) {
        if (!isVowel(c)) {
            result += '.';
            result += tolower(c);
        }
    }
    return result;
}

signed main() {
    fastio();
    docfile(); 

    string input;
    cin >> input;
    cout << processString(input) << ln;

    time();
    return 0;
}