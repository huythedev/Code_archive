#include <bits/stdc++.h>
using namespace std;

#define NAME "20-11"
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

const int MOD = 20112024;

ll factorial(int n) {
    ll result = 1;
    for (int i = 2; i <= n; ++i) {
        result = (result * i) % MOD;
    }
    return result;
}

ll power(ll a, ll b, ll mod) {
    ll result = 1;
    while (b > 0) {
        if (b % 2 == 1)
            result = (result * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return result;
}

ll modInverse(ll n, ll mod) {
    return power(n, mod - 2, mod);
}

ll solve(int n, const unordered_map<int, int>& freq) {
    ll total_fact = factorial(n);
    ll divisor_fact = 1;
    for (const auto &entry : freq) {
        divisor_fact = (divisor_fact * factorial(entry.second)) % MOD;
    }
    return (total_fact * modInverse(divisor_fact, MOD)) % MOD;
}

int main() {
    fastio();
    docfile();

    int n; cin >> n;
    vector<int> colors(n);
    unordered_map<int, int> freq;

    for(int i = 0; i < n; ++i) {
        cin >> colors[i];
        freq[colors[i]]++;
    }
    
    int max_freq = 0;
    for(const auto &entry : freq) {
        max_freq = max(max_freq, entry.second);
    }
    
    // Kiểm tra nếu màu nào xuất hiện quá nhiều
    if(max_freq > (n + 1) / 2) {
        cout << 0 << endl;
        return 0;
    }

    ll res = solve(n, freq);
    cout << res << endl;

    time();
    return 0;
}
