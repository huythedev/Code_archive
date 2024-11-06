#include <bits/stdc++.h>
using namespace std;

#define NAME "FIBO"
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

void fibo(set<ll>& fibo_set) {
    ll a = 0, b = 1;
    fibo_set.insert(a);
    fibo_set.insert(b);
    while (b <= 1e6) {  
        ll c = a + b;
        fibo_set.insert(c);
        a = b;
        b = c;
    }
}

int main() {
    fastio();
    docfile();

    ll n, p, q;
    cin >> n >> p >> q;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) 
        cin >> a[i];

    set<ll> fibo_set;
    fibo(fibo_set);

    vector<ll> prefixsum(n + 1, 0);
    for (ll i = 0; i < n; ++i) 
        prefixsum[i + 1] = prefixsum[i] + a[i];

    ll res = 0;
    
    for (ll i = p; i <= q; ++i) {
        for (ll l = 0; l + i - 1 < n; ++l) {
            ll r = l + i - 1;
            ll sum = prefixsum[r + 1] - prefixsum[l];
            if (fibo_set.count(sum)) 
                ++res;
        }
    }
    
    cout << res << ln;
    time();
    return 0;
}
