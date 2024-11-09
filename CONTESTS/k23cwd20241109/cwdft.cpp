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
    
    if(M > N * N) {
        cout << -1;
        return 0;
    }
    
    ll k = (M + N - 1) / N;
    ll ans = k * N;
    
    if(ans > N * N) {
        ll sqrtM = sqrt(M - 1);
        ans = (sqrtM + 1) * (sqrtM + 1);
    }
    
    cout << ans;

    time();
    return 0;
}
