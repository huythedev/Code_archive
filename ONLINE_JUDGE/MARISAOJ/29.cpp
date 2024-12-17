// Author: Perry (https://perrythedev.com)
// Problem Link: https://marisaoj.com/problems/29
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

int main() {
    fastio();
    docfile();

    int n; cin >> n;
    unordered_map<int, int> freq;
    for(int i = 0; i < n; ++i) {
        int x; cin >> x;
        freq[x]++;
    }

    int max_freq_val = 0, max_freq = 0;
    for(pair<int, int> i : freq) {
        if(i.second > max_freq) {
            max_freq = i.second;
            max_freq_val = i.first;
        }
    }

    cout << max_freq_val;

    time();
    return 0;
}