// Author: huythedev
// Problem Link: https://codeforces.com/contest/2109/problem/C2
#include <bits/stdc++.h>
using namespace std;

#define NAME "C2"
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

string read() {
    string res; cin >> res;
    return res;
}

bool digit() {
    cout << "digit" << ln;
    cout.flush();
    return read() == "1";
}

bool add(ll y) {
    cout << "add " << y << ln;
    cout.flush();
    return read() == "1";
}

bool mul(ll y) {
    cout << "mul " << y << ln;
    cout.flush();
    return read() == "1";
}

bool div(ll y) {
    cout << "div " << y << ln;
    cout.flush();
    return read() == "1";
}

bool announce() {
    cout << "!" << ln;
    cout.flush();
    return read() == "1";
}

void solve() {
    ll n; cin >> n;

    mul(9);
    digit();
    digit();
    add(n - 9);

    announce();
}

signed main() {
    fastio();
    docfile();

    int t; cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}