// Author: huythedev (https://huythedev.com)
// Problem Link: https://nbk.homes/problem/valval
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "valval"
#define ln "\n"
#define sz size()

typedef long long ll;
typedef unsigned long long ull;
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

const ll MAX_VAL = 1e18;
unordered_map<ll, ll> f_cache;
unordered_map<ll, ll> u_cache;

ll f(ll n) {
    if (f_cache.find(n) != f_cache.end()) return f_cache[n];
    ll cnt = 0;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            cnt += 2;
            if (i * i == n) {
                cnt--;
            }
        }
    }
    return f_cache[n] = cnt;
}

ll u(ll n) {
    if (u_cache.find(n) != u_cache.end()) return u_cache[n];
    ll sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return u_cache[n] = sum;
}

string multiply(string a, string b) {
    if (a == "0" || b == "0") return "0";
    int n = a.sz, m = b.sz;
    vector<int> res(n + m, 0);
    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            int mul = (a[i] - '0') * (b[j] - '0');
            int sum = mul + res[i + j + 1];
            res[i + j + 1] = sum % 10;
            res[i + j] += sum / 10;
        }
    }
    string ans = "";
    for (int i = 0; i < n + m; ++i) {
        if (ans.empty() && res[i] == 0) {
            continue;
        }
        ans += to_string(res[i]);
    }
    return ans;
}

string solve(ll x) {
    string divs = to_string(f(x));
    string sums = to_string(u(x));

    string divs2 = multiply(divs, divs);
    string sums2 = multiply(sums, multiply(sums, sums));
    return multiply(to_string(x), multiply(divs2, sums2));
}

int main() {
    fastio();
    docfile();

    int T;
    cin >> T;
    
    while (T--) {
        ll a, b, c; cin >> a >> b >> c;
        cout << solve(a) << ' ' << solve(b) << ' ' << solve(c) << ln;
    }

    time();
    return 0;
}