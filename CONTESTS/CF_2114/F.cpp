// Author: huythedev
// Problem Link: 
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
 
const ll INF = 1LL << 60;
vector<ll> primes;

void sieve() {
    vector<bool> isPrime(1000001, true);
    isPrime[0] = isPrime[1] = false;
    for (ll i = 2; i <= 1000000; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (ll j = i * 2; j <= 1000000; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

map<ll, int> factorize(ll n, ll k) {
    map<ll, int> factors;
    for (ll p : primes) {
        if (p > k || p > n) break;
        while (n % p == 0) {
            factors[p]++;
            n /= p;
        }
    }
    if (n > 1) factors[n]++;
    return factors;
}

void solve() {
    ll x, y, k;
    cin >> x >> y >> k;

    if (x == y) {
        cout << 0 << ln;
        return;
    }

    map<ll, int> mp1 = factorize(x, k);
    map<ll, int> mp2 = factorize(y, k);
    ll core_x = 1, core_y = 1;
    for (auto [p, e] : mp1) {
        if (p > k) core_x *= pow(p, e);
    }
    for (auto [p, e] : mp2) {
        if (p > k) core_y *= pow(p, e);
    }

    if (core_x != core_y) {
        cout << -1 << ln;
        return;
    }

    queue<ll> qx, qy;
    unordered_set<ll> curr_x, curr_y, prev_y;
    qx.push(x);
    curr_x.insert(x);
    qy.push(y);
    curr_y.insert(y);

    int steps_x = 0, steps_y = 0;
    const int MAX_STEPS = 20;
    const int MAX_SIZE = 100000;

    while (!qx.empty() && !qy.empty() && steps_x + steps_y < MAX_STEPS) {
        int size_x = qx.size();
        unordered_set<ll> next_x;
        for (int i = 0; i < size_x && !qx.empty(); i++) {
            ll curr = qx.front();
            qx.pop();
            if (curr_y.count(curr) || prev_y.count(curr)) {
                cout << steps_x + steps_y << ln;
                return;
            }
            for (ll a = 2; a <= k && next_x.size() < MAX_SIZE; a++) {
                if (curr <= INF / a) {
                    ll next = curr * a;
                    if (!curr_x.count(next) && !next_x.count(next)) {
                        next_x.insert(next);
                        qx.push(next);
                    }
                }

                if (curr % a == 0) {
                    ll next = curr / a;
                    if (!curr_x.count(next) && !next_x.count(next)) {
                        next_x.insert(next);
                        qx.push(next);
                    }
                }
            }
        }
        steps_x++;
        curr_x = move(next_x);

        int size_y = qy.size();
        unordered_set<ll> next_y;
        for (int i = 0; i < size_y && !qy.empty(); i++) {
            ll curr = qy.front();
            qy.pop();
            if (curr_x.count(curr)) {
                cout << steps_x + steps_y << ln;
                return;
            }
            for (ll a = 2; a <= k && next_y.size() < MAX_SIZE; a++) {
                if (curr <= INF / a) {
                    ll next = curr * a;
                    if (!curr_y.count(next) && !next_y.count(next)) {
                        next_y.insert(next);
                        qy.push(next);
                    }
                }
                
                if (curr % a == 0) {
                    ll next = curr / a;
                    if (!curr_y.count(next) && !next_y.count(next)) {
                        next_y.insert(next);
                        qy.push(next);
                    }
                }
            }
        }
        steps_y++;
        prev_y = move(curr_y);
        curr_y = move(next_y);

        if (curr_x.empty() && curr_y.empty()) break;
    }

    cout << -1 << ln;
}
 
signed main() {
    docfile();
    fastio();
    sieve();
 
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
 
    time();
    return 0;
}
