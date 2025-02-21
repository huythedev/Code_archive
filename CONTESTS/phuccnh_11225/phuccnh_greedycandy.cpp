// Author: Perry (https://perrythedev.com)
// Problem Link: https://oj.vnoi.info/problem/phuccnh_greedycandy
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

bool can_eat(ll n, ll k) {
    ll vasya = 0, candies = n;
    while (candies > 0) {
        ll vasyaEat = min(candies, k);
        vasya += vasyaEat;
        candies -= vasyaEat;
        ll petyaEat = candies / 10;
        candies -= petyaEat;
    }
    return vasya * 2 >= n;
}

int main() {
    fastio();
    docfile();

    ll n;
    cin >> n;

    ll l = 1, r = n, res = n;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (can_eat(n, mid)) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << res;

    time();
    return 0;
}