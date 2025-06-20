// Author: huythedev
// Problem Link: https://codeforces.com/gym/450561/problem/A
#include <bits/stdc++.h>
using namespace std;

#define NAME "A"
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

vector<string> fib(93);

string sum(string a, string b) {
    while ((int)a.sz < (int)b.sz) {
        a = '0' + a;
    }
    while ((int)a.sz > (int)b.sz) {
        b = '0' + b;
    }

    int mem = 0;
    string result;
    for (int i = (int)a.sz - 1; i >= 0; --i) {
        int num = a[i] - '0' + b[i] - '0';
        num += mem;
        mem = num / 10;
        num %= 10;
        result = char(num + '0') + result;
    }

    if (mem != 0) {
        result = '1' + result;
    }

    return result;
}

void precompute() {
    fib[0] = '1';
    fib[1] = '1';

    for (int i = 2; i < 93; ++i) {
        fib[i] = sum(fib[i - 1], fib[i - 2]);
    }
}

void solve() {
    int n; cin >> n;
    cout << fib[n] << ln;
}

signed main() {
    docfile();
    fastio();
    precompute();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}