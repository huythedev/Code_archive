#include <bits/stdc++.h>
using namespace std;

#define NAME "lfib"
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

vector<ll> fib(41, 0);

void precompute() {
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2; i < 41; ++i)
        fib[i] = fib[i - 1] + fib[i - 2];
}

int main() {
    fastio();
    docfile();
    precompute();

    int tests; cin >> tests;
    while(tests--) {
        int i, j, s; cin >> i >> j >> s;
        if(fib[i] + fib[j] == s)
            cout << "YES" << ln;
        else
            cout << "NO" << ln;
    }

    time();
    return 0;
}