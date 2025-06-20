// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "DIVSUB"
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

    int n, P; cin >> n >> P;
    string S; cin >> S;

    ll count = 0;
    unordered_map<int, int> freq;
    freq[0] = 1;
    int prefix_rem = 0;

    for (int j = 0; j < n; j++) {
        int digit = S[j] - '0';
        prefix_rem = ((ll)prefix_rem * 10 + digit) % P;
        count += freq[prefix_rem];
        freq[prefix_rem]++;
    }

    cout << count << ln;

    time();
    return 0;
}
