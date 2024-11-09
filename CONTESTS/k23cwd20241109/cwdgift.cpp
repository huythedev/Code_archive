// Author: Perry (https://perrythedev.com)
// Problem Link: https://nbk.homes/problem/cwdgift
#include <bits/stdc++.h>
using namespace std;

#define NAME "cwdgift"
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

    int n, m; ll d; cin >> n >> m >> d;
    
    vector<ll> a(n), b(m);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    ll i = n - 1, j = m - 1;
    ll res = -1;
    while(i >= 0 && j >= 0) {
        if(abs(a[i] - b[j]) <= d) {
            res = max(res, a[i] + b[j]);
            i--;
            j--;
        } else {
            if(a[i] > b[j]) i--;
            else j--;
        }
    }
    cout << res;

    time();
    return 0;
}