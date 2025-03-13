// Author: Perry (https://perrythedev.com)
// Problem Link: https://codeforces.com/problemset/problem/339/A
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

signed main() {
    fastio();
    docfile();

    string s;
    cin >> s;

    vector<int> numbers;
    for (char c : s) {
        if (isdigit(c)) {
            numbers.push_back(c - '0');
        }
    }

    sort(numbers.begin(), numbers.end());

    for (size_t i = 0; i < numbers.size(); ++i) {
        if (i > 0) cout << "+";
        cout << numbers[i];
    }
    cout << ln;

    time();
    return 0;
}