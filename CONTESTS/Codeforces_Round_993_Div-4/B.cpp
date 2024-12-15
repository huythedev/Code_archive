// Author: Perry (https://perrythedev.com)
// Problem Link: https://codeforces.com/contest/2044/problem/B
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

string transform(const string& a) {
    string b = a;
    for (char& c : b) {
        if (c == 'p') {
            c = 'q';
        } else if (c == 'q') {
            c = 'p';
        }
    }
    return b;
}

int main() {
    fastio();
    docfile();

    int t; cin >> t;
    while (t--) {
        string a;
        cin >> a;
        cout << transform(a) << ln;
    }

    time();
    return 0;
}