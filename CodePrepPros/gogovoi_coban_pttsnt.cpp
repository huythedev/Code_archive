// Author: huythedev
// Problem Link: 
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

void solve() {
    int n; cin >> n;
    
    vector<int> primes, powers;
    
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            primes.push_back(i);
            int count = 0;
            while (n % i == 0) {
                n /= i;
                count++;
            }
            powers.push_back(count);
        }
    }
    
    if (n > 1) {
        primes.push_back(n);
        powers.push_back(1);
    }
    
    vector<int> vec;
    for (int i = 0; i < (int)primes.sz; ++i) {
        for (int j = 0; j < powers[i]; ++j) {
            vec.push_back(primes[i]);
        }
    }
    
    for (int i = 0; i < (int)vec.sz - 1; ++i) {
        cout << vec[i] << "*";
    }
    cout << vec[(int)vec.sz - 1] << ln;
    
    int res = 1;
    for (int i = 0; i < (int)powers.sz; ++i) {
        res *= (powers[i] + 1);
    }
    
    cout << res << ln;
}

signed main() {
    docfile();
    fastio();

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}