// Author: Perry (https://perrythedev.com)
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "20-11"
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

const int MOD = 20112024;
vector<int> fact(1e5 + 1, 1);

void precompute() {
    // Caculate first 1e5 values of factorial
    for (int i = 1; i <= 1e5; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}

int main() {
    fastio();
    docfile();
    precompute();

    int n; cin >> n;
    unordered_map<int, int> colors;
    for(int i = 0; i < n; ++i) {
        int x; cin >> x;
        colors[x]++;
    }

    ll res = fact[n];
    for(auto& [color, cnt] : colors) {
        res = (res * fact[cnt]) % MOD;
    }

    cout << res << ln;

    time();
    return 0;
}