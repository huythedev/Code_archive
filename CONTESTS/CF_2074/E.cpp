// Author: Perry (https://perrythedev.com)
// Problem Link: https://codeforces.com/contest/2074/problem/E
// davul
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

const int maxn = 75;
int cnt = 0;
 
int query(int x, int y, int z) {
    if (cnt >= maxn) exit(0); 
 
    cout << "? " << x << " " << y << " " << z << ln;
    cout.flush();
 
    int n;
    cin >> n;
 
    if (n == -1) exit(0); 
    cnt++;
    return n;
}
 
void solve() {
    int n;
    cin >> n;
 
    int a = 1, b = 2, c = 3; 
 
    while (true) {
        int res = query(a, b, c);
        if (res == 0) break; 
 
        if (query(res, b, c) == 0) { a = res; continue; }
        if (query(a, res, c) == 0) { b = res; continue; }
        if (query(a, b, res) == 0) { c = res; continue; }
 
        int new_b = query(res, b, c);
        int new_c = query(a, res, c);
        a = res;
        b = new_b;
        c = new_c;
    }
 
    cout << "! " << a << " " << b << " " << c << ln;
    cout.flush();
}

signed main() {
    fastio();
    docfile();

    int t;
    cin >> t;
 
    while (t--) {
        cnt = 0; 
        solve();
    }

    time();
    return 0;
}