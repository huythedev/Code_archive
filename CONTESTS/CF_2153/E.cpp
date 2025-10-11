// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "E"
#define ln "\n"
#define sz size()

typedef long long ll;
typedef long double ld;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void fileIO() {
    if (ifstream(NAME ".INP")) {
        freopen(NAME ".INP", "r", stdin);
        freopen(NAME ".OUT", "w", stdout);
    }
}

void time() {
    cerr << ln << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." 
         << ln;
}

const int MAXN = 1e7 + 10;
const ll INF = 1LL << 60;

vector<ll> spf(MAXN), primes;
map<ll, int> mp;

void sieve() {
    for (int i = 0; i < MAXN; i++) 
        spf[i] = i;
    
    for (ll i = 2; i * i < MAXN; i++) {
        if (spf[i] == i) {
            for (ll j = i * i; j < MAXN; j += i) {
                if (spf[j] == j) 
                    spf[j] = i;
            }
        }
    }

    for (ll i = 2; i < MAXN; i++)
        if (spf[i] == i) 
            primes.push_back(i);
    
    for (int i = 0; i < (int)primes.size(); i++)
        mp[primes[i]] = i;
}

ll calc(ll n, ll p) {
    ll res = 0;
    ll pp = p;
    while (pp <= n) {
        res += n / pp;
        if (pp > n / p) break;
        pp *= p;
    }
    return res;
}

void solve() {
    ll n, m;
    cin >> n >> m;

    ll sqrtM = floor(sqrt(m)) + 10;

    vector<ll> vec((int)primes.size(), 0);

    for (int i = 0; i < (int)primes.size(); i++) {
        ll p = primes[i];
        if (p > m) 
            break;

        ll pw = 1;
        ll ee = 0;
        while (true) {
            if (pw > m / p) 
                break;
            
            ll next = pw * p;
            if (next > m)
                break;
            
            pw = next;
            ee++;
        }

        vec[i] = ee;
    }

    vector<ll> vec2((int)primes.size(), 0);
    for (int i = 0; i < (int)primes.size(); i++) {
        ll p = primes[i];
        if (p > n) 
            break;
        vec2[i] = calc(n, p);
    }

    vector<ll> delta((int)primes.size(), 0);
    set<pair<ll, int>> st;
    set<pair<ll, int>> st2;
    vector<ll> vec3((int)primes.size(), -1);

    ll ans = 0;
    bool isZero = false;
    for (ll i = n - 1; i >= 1; i--) {
        ll num = i + 1;
        vector<pair<ll, int>> factors;

        while (num > 1) {
            ll p = spf[num];
            int cnt = 0;
            while (num % p == 0) {
                num /= p;
                cnt++;
            }
            factors.push_back({p, cnt});
        }

        for (auto [p, cnt] : factors) {
            auto it = mp.find(p);
            if (it == mp.end()) 
                continue;
            
            int idx = it -> second;
            ll prev = vec2[idx];
            vec2[idx] -= cnt;
            delta[idx] += cnt;
            bool first = (delta[idx] == cnt);

            if (first) {
                if (primes[idx] > sqrtM)
                    st.insert({prev, idx});
            }

            if (primes[idx] > sqrtM) {
                st.erase({prev, idx});
                st.insert({vec2[idx], idx});
            } 
            else {
                if (!first)
                    st2.erase({vec3[idx], idx});
                
                ll tmp2 = INF;
                for (ll j = vec[idx]; j >= 1; j--) {
                    ll r = vec2[idx] % j;
                    if (delta[idx] >= j - r) {
                        tmp2 = vec2[idx] / j;
                        break;
                    }
                }

                vec3[idx] = tmp2;
                st2.insert({tmp2, idx});
            }

            if (delta[idx] > 0 && vec2[idx] + 1 <= vec[idx])
                isZero = true;
        }

        if (isZero) 
            break;

        ll min1 = st.empty() ? INF : st.begin() -> first;
        ll min2 = st2.empty() ? INF : st2.begin() -> first;
        
        ans += min(min1, min2);
    }

    cout << ans << ln;
}

signed main() {
    fastIO();
    fileIO();

    sieve();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}