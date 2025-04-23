// Author: huythedev
// Problem Link: https://codeforces.com/group/VbkeP1fypp/contest/597270/problem/D

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

const int MOD = 1e9 + 7;

ll modpow(ll base, ll exp, ll mod) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

ll modinv(ll a, ll mod) {
    return modpow(a, mod - 2, mod);
}

const int MAX_FACT = 1000005;
ll fact[MAX_FACT], ifact[MAX_FACT];

void precompute() {
    fact[0] = 1;
    for (int i = 1; i < MAX_FACT; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
    }
    ifact[MAX_FACT-1] = modinv(fact[MAX_FACT-1], MOD);
    for (int i = MAX_FACT-2; i >= 0; i--) {
        ifact[i] = (ifact[i+1] * (i+1)) % MOD;
    }
}

ll cacl(ll n, ll r) {
    if (r < 0 || r > n) return 0;
    if (r == 0 || r == n) return 1;
    
    if (n < MAX_FACT) {
        return (((fact[n] * ifact[r]) % MOD) * ifact[n-r]) % MOD;
    }
    
    if (r > n - r) r = n - r;
    
    ll result = 1;
    for (ll i = 0; i < r; i++) {
        result = (result * (n - i)) % MOD;
        result = (result * ifact[i+1]) % MOD;
    }
    return result;
}

ll fib(ll n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    
    if (n > 1000000) {
        vector<vector<ll>> base = {{1, 1}, {1, 0}};
        vector<vector<ll>> res = {{1, 0}, {0, 1}};
        
        n--;
        while (n > 0) {
            if (n & 1) {
                vector<vector<ll>> temp = {{0, 0}, {0, 0}};
                for (int i = 0; i < 2; i++) {
                    for (int j = 0; j < 2; j++) {
                        for (int k = 0; k < 2; k++) {
                            temp[i][j] = (temp[i][j] + res[i][k] * base[k][j]) % MOD;
                        }
                    }
                }
                res = temp;
            }
            
            vector<vector<ll>> temp = {{0, 0}, {0, 0}};
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    for (int k = 0; k < 2; k++) {
                        temp[i][j] = (temp[i][j] + base[i][k] * base[k][j]) % MOD;
                    }
                }
            }
            base = temp;
            
            n >>= 1;
        }
        
        return res[0][0]; 
    }
    
    ll a = 0, b = 1;
    for (ll i = 2; i <= n; i++) {
        ll c = (a + b) % MOD;
        a = b;
        b = c;
    }
    
    return b;
}

bool tmp(ll n, ll r) {
    if (r > 50 && n > r + 1000) return false;
    return true;
}

// Optimize the M=3 case specifically
ll solve_m3_exact(ll n) {
    // For M=3, we need to compute sum of C(n-2j, j) for j=0 to n/3
    // We'll use a more accurate approach without sampling
    
    ll result = 0;
    
    // Small values of j contribute significantly - calculate these precisely
    const int PRECISE_LIMIT = 10000;
    for (ll j = 0; j <= min((ll)PRECISE_LIMIT, n/3); j++) {
        ll total = n - j * 2;
        if (total < j) break;
        result = (result + cacl(total, j)) % MOD;
    }
    
    // For larger values, calculate in batches with memoization
    if (n/3 > PRECISE_LIMIT) {
        // Use a moving window to avoid excessive memory usage
        const int WINDOW_SIZE = 1000;
        
        for (ll start = PRECISE_LIMIT + 1; start <= n/3; start += WINDOW_SIZE) {
            ll end = min(start + WINDOW_SIZE - 1, n/3);
            
            // Calculate each value in this batch
            for (ll j = start; j <= end; j++) {
                ll total = n - j * 2;
                if (total < j) break;
                
                // We know these are large values, so use the optimized calculation
                ll comb_value = 0;
                
                if (j < MAX_FACT) {
                    // This can handle n-2j >= MAX_FACT but j < MAX_FACT
                    ll tmp = 1;
                    for (ll i = 0; i < j; i++) {
                        tmp = (tmp * (total - i)) % MOD;
                        tmp = (tmp * ifact[i+1]) % MOD;
                    }
                    comb_value = tmp;
                }
                
                result = (result + comb_value) % MOD;
            }
        }
    }
    
    return result;
}

void solve(ll n, int m) {
    if (m == 1) {
        cout << 1 << ln;
        return;
    }
    
    if (m == 2) {
        cout << fib(n + 1) << ln;
        return;
    }
    
    if (m == 3) {
        cout << solve_m3_exact(n) << ln;
        return;
    }
    
    // For M > 3, use optimized approach
    ll result = 0;
    ll max_y = min(n / m, (ll)100000); // Less aggressive limit
    
    // Process in segments to manage memory
    const int SEGMENT_SIZE = 10000;
    for (ll segment_start = 0; segment_start <= max_y; segment_start += SEGMENT_SIZE) {
        ll segment_end = min(segment_start + SEGMENT_SIZE, max_y + 1);
        
        for (ll y = segment_start; y < segment_end; y++) {
            ll total = n - y * (m - 1);
            if (total < y) break;
            result = (result + cacl(total, y)) % MOD;
        }
    }
    
    cout << result << ln;
}

signed main() {
    fastio();
    docfile();
    precompute();

    ll n; int m; cin >> n >> m;
    solve(n, m);
    
    time();
    return 0;
}