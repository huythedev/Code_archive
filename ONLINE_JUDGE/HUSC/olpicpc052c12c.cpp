// Author: huythedev (https://huythedev.com)
// Problem Link: https://coder.husc.edu.vn/problem/olpicpc052c12c

#include <bits/stdc++.h>
using namespace std;

#define NAME "olpicpc052c12c"
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

ll modInverse(ll a, ll m) {
    ll m0 = m, t, q;
    ll x0 = 0, x1 = 1;
    if (m == 1) return 0;
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0) x1 += m0;
    return x1;
}

int main() {
    fastio();
    docfile();

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll max_tich = LLONG_MIN;
    ll tong = 1;
    int zero_cnt = 0;
    int negative_cnt = 0;
    int max_negative = INT_MIN;
    int min_positive = INT_MAX;

    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
            zero_cnt++;
            continue;
        }
        if (a[i] < 0) {
            negative_cnt++;
            max_negative = max(max_negative, a[i]);
        } 
        else {
            min_positive = min(min_positive, a[i]);
        }
        tong = (tong * a[i]) % MOD;
    }

    if (zero_cnt == n) {
        cout << 0 << ln;
    } 
    else if (negative_cnt % 2 == 0) {
        max_tich = tong;
    } 
    else {
        if (negative_cnt == 1 && zero_cnt > 0 && zero_cnt + negative_cnt == n) {
            max_tich = 0;
        } 
        else {
            if (negative_cnt > 0) {
                max_tich = (tong * modInverse(max_negative, MOD)) % MOD;
            }
            if (zero_cnt > 0) {
                max_tich = max(max_tich, tong);
            }
        }
    }

    cout << (max_tich + MOD) % MOD << ln;

    time();
    return 0;
}