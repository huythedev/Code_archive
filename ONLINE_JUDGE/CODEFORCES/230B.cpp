// Author: huythedev (https://huythedev.com)
// Problem Link: https://codeforces.com/problemset/problem/230/B
// davul
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

bool is_prime(ll n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (ll i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

bool is_t_prime(ll n) {
    if (n < 4) return false;
    ll root = sqrt(n);
    return root * root == n && is_prime(root);
}

signed main() {
    fastio();
    docfile();

    ll n;
    cin >> n;
    vector<ll> numbers(n);
    for (ll i = 0; i < n; ++i) {
        cin >> numbers[i];
    }
    for (ll i = 0; i < n; ++i) {
        if (is_t_prime(numbers[i])) {
            cout << "YES" << ln;
        } else {
            cout << "NO" << ln;
        }
    }

    time();
    return 0;
}