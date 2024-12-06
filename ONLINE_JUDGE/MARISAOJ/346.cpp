// Author: Perry (https://perrythedev.com)
// Problem Link: https://marisaoj.com/problem/346
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

    int n; ll k; cin >> n >> k;
    vector<ll> A(n);
    for(ll &i : A)
        cin >> i;

    bool found = false;
    for(int mask = 0; mask < (1 << n); ++mask) {
        ll sum = 0;
        for(int i = 0; i < n; ++i) {
            if(mask & (1 << i)) {
                sum += A[i];
            }
        }
        if(sum == k) {
            found = true;
            break;
        }
    }

    cout << (found ? "YES" : "NO");

    time();
    return 0;
}