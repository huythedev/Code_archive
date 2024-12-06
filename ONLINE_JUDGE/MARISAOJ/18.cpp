// Author: Perry (https://perrythedev.com)
// Problem Link: https://marisaoj.com/problem/18
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

bool is_prime(int n) {
    if(n < 2) return false;
    for(int i = 2; i <= sqrt(n); ++i) if(n % i == 0) return false;
    return true;
}

int main() {
    fastio();
    docfile();

    int n; cin >> n;
    cout << (is_prime(n) ? "YES" : "NO");

    time();
    return 0;
}