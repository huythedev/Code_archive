// Author: huythedev
// Problem Link: https://codeforces.com/group/G0iFI97YZN/contest/608263/problem/D
#include <bits/stdc++.h>
using namespace std;

#define NAME "D"
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

vector<int> convert(ll val) {
    if (val == 0) {
        return {0};
    }
    vector<int> digits;
    while (val > 0) {
        digits.push_back(val % 3);
        val /= 3;
    }
    return digits;
}

ll to_dec(const vector<int>& digits) {
    ll res = 0, exp_3 = 1;
    for (int i : digits) {
        res += (ll)i * exp_3;
        exp_3 *= 3;
    }
    return res;
}

void solve() {
    ll n; cin >> n;

    vector<int> digits = convert(n);

    int tmp = -1;
    for (int i = (int)digits.sz - 1; i >= 0; --i) {
        if (digits[i] == 2) {
            tmp = i;
            break; 
        }
    }

    if (tmp == -1) {
        cout << n << ln;
        return;
    }

    vector<int> digits2 = digits;

    for (int i = 0; i <= tmp; ++i) {
        digits2[i] = 0;
    }
    
    int pos = tmp + 1;
    while (true) {
        if (pos >= digits2.sz) {
            digits2.push_back(0);
        }
        
        digits2[pos]++;
        
        if (digits2[pos] <= 1) {
            break;
        } else {
            digits2[pos] = 0;
            pos++;
        }
    }
    
    cout << to_dec(digits2) << ln;
}

signed main() {
    fastio();
    docfile();

    int q; cin >> q;
    while (q--) {
        solve();
    }

    time();
    return 0;
}