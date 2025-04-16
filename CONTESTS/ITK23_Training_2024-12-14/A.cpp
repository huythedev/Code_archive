// Author: huythedev (https://huythedev.com)
// Problem Link: https://codeforces.com/group/G0iFI97YZN/contest/573643/problem/A
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

int main() {
    fastio();
    docfile();

    ll n, k; cin >> n >> k;
    
    ll x_max = n / (2 * (1 + k)); 
    ll x = x_max;
    ll y = k * x;                
    ll z = n - (x + y);         

    cout << x << " " << y << " " << z << endl;

    time();
    return 0;
}