#include <bits/stdc++.h>
using namespace std;

#define NAME "F"
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

const int MAX_P = 200000000; 

vector<bool> isPrime;         
vector<ll> primes;             
vector<ll> S, C;               
vector<int> bin_len;     

void sieve() {
    isPrime.resize(MAX_P, true);
    isPrime[0] = isPrime[1] = false;
    for (ll i = 2; i * i < MAX_P; i++) {
        if (isPrime[i]) {
            for (ll j = i * i; j < MAX_P; j += i) {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i < MAX_P; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
}

void precompute() {
    S.push_back(0);
    C.push_back(0);
    for (ll p : primes) {
        int l = 64 - __builtin_clzll(p - 1);    
        ll b = __builtin_popcountll(p);         
        S.push_back(S.back() + l);
        C.push_back(C.back() + b);
        bin_len.push_back(l);
    }
}

ll solve(int N) {
    if (N == 0) return 0;
    auto it = lower_bound(S.begin(), S.end(), N);
    int k = it - S.begin();                    
    ll cum_ones = (k >= 1) ? C[k - 1] : 0;     
    ll prev_S = (k >= 1) ? S[k - 1] : 0;       
    int m = N - prev_S;                        
    ll p_k = primes[k - 1];                    
    int l_k = bin_len[k - 1];            
    ll prefix_ones = __builtin_popcountll(p_k >> (l_k - m)); 
    return cum_ones + prefix_ones;
}

signed main() {
    fastio();
    docfile();
    precompute();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << solve(n) << ln;
    }

    time();
    return 0;
}