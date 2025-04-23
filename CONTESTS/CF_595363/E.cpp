// Author: huythedev (https://huythedev.com)
// Problem Link: https://codeforces.com/group/VbkeP1fypp/contest/595363/problem/E

#include <bits/stdc++.h>
using namespace std;
 
#define NAME "E"
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
 
const int maxn = 1e5 + 5;
const int MOD = 1e9 + 7;
 
int n;
vector<int> a(maxn);
 
int pow_mod(int n) {
    int res = 1;
    int base = 2;
    while (n > 0) {
        if (n & 1) res = (1LL * res * base) % MOD;
        base = (1LL * base * base) % MOD;
        n >>= 1;
    }
    return res;
}
 
signed main() {
    fastio();
    docfile();
 
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    int total = (pow_mod(n) - 1 + MOD) % MOD;

    vector<int> cnt_a(100001, 0);
    for (int i = 0; i < n; ++i) {
        if (a[i] <= 100000) cnt_a[a[i]]++;
    }

    vector<vector<int>> divs(100001);
    for (int d = 1; d <= 100000; ++d) {
        for (int k = d; k <= 100000; k += d) {
            divs[k].push_back(d);
        }
    }

    vector<int> freq(100001, 0);
    for (int k = 1; k <= 100000; ++k) {
        if (cnt_a[k] > 0) {
            for (int d : divs[k]) {
                freq[d] += cnt_a[k];
            }
        }
    }

    vector<int> cnt(100001, 0);
    for (int i = 2; i <= 100000; ++i) {
        if (freq[i] > 0) {
            cnt[i] = (pow_mod(freq[i]) - 1 + MOD) % MOD;
        }
    }

    for (int i = 100000; i >= 2; --i) {
        for (int j = i * 2; j <= 100000; j += i) {
            cnt[i] = (cnt[i] - cnt[j] + MOD) % MOD;
        }
    }

    int tmp = 0;
    for (int i = 2; i <= 100000; ++i) {
        tmp = (tmp + cnt[i]) % MOD;
    }

    cout << (total - tmp + MOD) % MOD << ln;
 
    time();
    return 0;
}