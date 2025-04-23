// Author: huythedev (https://huythedev.com)
// Problem Link: 

#include <bits/stdc++.h>
using namespace std;

#define NAME "FIBODISTRIBUTE"
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

const int MOD = 1e9 + 7;

vector<ll> gen(ll maxval) {
    vector<ll> fib = {1, 2};
    ll a = 1, b = 2;
    while (true) {
        ll tmp = a + b;
        if (tmp > maxval) 
            break;
        fib.push_back(tmp);
        a = b;
        b = tmp;
    }
    return fib;
}

int main() {
    fastio();
    docfile();

    int n;
    cin >> n;
    vector<ll> a(n);
    ll maxsum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        maxsum += a[i];
    }

    vector<ll> fib = gen(maxsum);

    vector<ll> prefixSum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefixSum[i + 1] = prefixSum[i] + a[i];
    }

    vector<ll> dp(n + 1, 0);
    dp[0] = 1;

    unordered_map<ll, vector<int>> positions;
    positions[0].push_back(0);

    for (int i = 1; i <= n; ++i) {
        for (ll f : fib) {
            ll tmp = prefixSum[i] - f;
            if (positions.find(tmp) != positions.end()) {
                for (int pos : positions[tmp]) {
                    dp[i] = (dp[i] + dp[pos]) % MOD;
                }
            }
        }
        positions[prefixSum[i]].push_back(i);
    }

    cout << dp[n];

    time();
    return 0;
}