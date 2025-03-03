// Author: Perry (https://perrythedev.com)
// Problem Link: https://codeforces.com/group/G0iFI97YZN/contest/592900/problem/B
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

ll factorial(ll n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

ll f(ll x) {
    if (x <= 9)
        return factorial(x);
    else {
        return factorial(x % 10) + f(x / 10);
    }
}

int main() {
    fastio();
    docfile();

    int y; cin >> y;

    ll x = 0, curr = 0;
    while (curr != y) {
        curr = f(x);
        x++;
    }

    cout << x - 1 << ln;

    time();
    return 0;
}