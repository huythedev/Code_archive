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

bool hehe(ll T, ll N) {
    ll sqrtT = sqrt(T);
    for(ll a = 1; a <= min(sqrtT, N); a++) {
        if(T % a == 0) {
            ll b = T / a;
            if(b <= N) return true;
        }
    }
    return false;
}

int main() {
    fastio();
    docfile();

    ll N, M;
    cin >> N >> M;
    
    if(M > N * N) {
        cout << -1;
        return 0;
    }
    
    for(ll T = M; T <= N * N; T++) {
        if(hehe(T, N)) {
            cout << T;
            return 0;
        }
    }
    
    cout << -1;

    time();
    return 0;
}
