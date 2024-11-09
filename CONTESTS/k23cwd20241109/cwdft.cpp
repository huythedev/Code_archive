// Author: Perry (https://perrythedev.com)
// Problem Link: https://nbk.homes/problem/cwdft
#include <bits/stdc++.h>
using namespace std;
#define NAME "cwdft"
#define ln "\n"
typedef long long ll;
typedef long double ld;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void docfile() {
    if (ifstream(NAME ".INP")) {
        freopen(NAME ".INP", "r", stdin);
        freopen(NAME ".OUT", "w", stdout);
    }
}

// Optimized function to check if number T can be factored into a*b where both a,b <= N
bool canFactor(ll T, ll N) {
    ll sqrtT = sqrt(T);
    // Only need to check up to sqrt(T)
    for (ll a = 1; a <= sqrtT; a++) {
        if (T % a == 0) {
            ll b = T / a;
            if (a <= N && b <= N) return true;
        }
    }
    return false;
}

int main() {
    fastio();
    docfile();
    
    ll N, M;
    cin >> N >> M;
    
    // Early exit conditions
    if (M > N * N) {
        cout << -1;
        return 0;
    }
    
    // If M is already factorable within N bounds, return it
    if (canFactor(M, N)) {
        cout << M;
        return 0;
    }
    
    // Binary search approach for optimization
    ll left = M + 1;
    ll right = N * N;
    ll ans = -1;
    
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        if (canFactor(mid, N)) {
            ans = mid;
            right = mid - 1;  // Try to find smaller valid answer
        } else {
            left = mid + 1;
        }
    }
    
    cout << ans;
    return 0;
}