// Author: huythedev (https://huythedev.com)
// Problem Link: https://coder.husc.edu.vn/problem/olpicpc073c16d
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "olpicpc073c16d"
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

int n, m;
vector<ll> vec;

bool ok(ll time) {
    ll hamburgers = 0;
    for (int i = 0; i < n; ++i) {
        hamburgers += time / vec[i];
        if (hamburgers >= m + 1) return true;
    }
    return hamburgers >= m + 1;
}

int main() {
    fastio();
    docfile();

    cin >> n >> m;
    vec.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }

    ll l = 1; ll r = *max_element(vec.begin(), vec.end()) * (m + 1);
    while (l < r) {
        ll mid = l + (r - l) / 2;
        if (ok(mid)) {
            r = mid;
        } 
        else {
            l = mid + 1;
        }
    }

    cout << l << ln;

    time();
    return 0;
}