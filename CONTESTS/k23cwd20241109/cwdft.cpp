// Author: Perry (https://perrythedev.com)
// Problem Link: https://nbk.homes/problem/cwdft
#include <bits/stdc++.h>
using namespace std;

#define NAME "cwdft"
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

    ll N, M; cin >> N >> M;
    
    for(ll T = M;; T++) {
        bool found = false;
        for(ll a = 1; a * a <= T && a <= N; a++) {
            if(T % a == 0) {
                ll b = T / a;
                if(a <= N && b <= N) {
                    found = true;
                    break;
                }
            }
        }
        if(found) {
            cout << T;
            return 0;
        }
    }
    
    cout << -1;

    time();
    return 0;
}
