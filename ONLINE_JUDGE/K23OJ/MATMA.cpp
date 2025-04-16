// Author: huythedev (https://huythedev.com)
// Problem Link: https://k23oj.site/problem/matma
#include <bits/stdc++.h>
using namespace std;

#define NAME "MATMA"
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

int main() {
    fastio();
    docfile();

    string s; cin >> s;
    ll sum_digit = 0;
    bool is_devided_by_30 = false, has_zero = false;

    vector<int> freq(10, 0);  
    for (char c : s) {
        sum_digit += c - '0';
        if (c == '0') has_zero = true;
        freq[c - '0']++;
    }

    if (sum_digit % 3 == 0 && has_zero) is_devided_by_30 = true;

    if (!is_devided_by_30) {
        cout << -1;
        return 0;
    }
    else {
        for (int i = 9; i >= 0; i--) {
            while (freq[i] > 0) {
                cout << i;
                freq[i]--;
            }
        }
    }

    time();
    return 0;
}