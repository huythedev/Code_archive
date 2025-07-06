// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "PRIME"
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

const int MAXN = 1e6 + 5;
vector<bool> isPrime (MAXN * 2, true);
void sieve() {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= 2e6 + 4; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= 2e6 + 4; j += i) {
                isPrime[j] = false;
            }
        }
    }

    // for (int i = 0; i < 10; ++i) {
    //     cerr << i << " is prime: " << isPrime[i] << ln;
    // }
}

vector<ll> prefix_count(MAXN * 2, 0);
void precompute() {
    for (int i = 1; i < MAXN * 2; i++) {
        if (isPrime[i]) {
            prefix_count[i] = prefix_count[i - 1] + 1;
        } else {
            prefix_count[i] = prefix_count[i - 1];
        }
    }

    // for (int i = 0; i < 10; ++i) {
    //     cerr << prefix_count[i] << ' ';
    // }
}

void solve() {
    int n; cin >> n;
    cout << prefix_count[2 * n] - prefix_count[n - 1] << ln;
}

signed main() {
    docfile();
    fastio();
    sieve();
    precompute();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}
