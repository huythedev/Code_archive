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

    for(int i = 0; i < n - 1; ++i) {
        ll res = 0;
        for(int j = i + 1; j < n; ++j) {
            res += A[j];
            if(res == k) {
                cout << "YES";
                return 0;
            }
        }
    }

    cout << "NO";

    time();
    return 0;
}