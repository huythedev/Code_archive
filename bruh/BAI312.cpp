// Author: huythedev (https://huythedev.com)
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "BAI312"
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
    cerr << ln << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << ln;
}

bool isPrime(ll n) {
    if (n <= 1) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (ll i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

ll solve(string N) {
    ll res = -1;
    int len = N.size();
    
    ll num = stoll(N);
    
    if (num >= 1e11) { 
        for(int i = 0; i < len-1; ++i) {
            string tmp = N;
            tmp.erase(i, 2);
            ll val = stoll(tmp);
            if(isPrime(val)) res = max(res, val);
        }
    }
    else if (num >= 1e10) { 
        for(int i = 0; i < len; ++i) {
            string tmp = N;
            tmp.erase(i, 1);
            ll val = stoll(tmp);
            if(isPrime(val)) res = max(res, val);
        }
    }
    else if (num >= 1e8) { 
        for(int i = 0; i < len; ++i) {
            for(int j = i+1; j < len; ++j) {
                string tmp = N;
                tmp.erase(j, 1);
                tmp.erase(i, 1);
                ll val = stoll(tmp);
                if(isPrime(val)) res = max(res, val);
            }
        }
    }
    else { 
        for(int i = 1; i < (1 << len); ++i) {
            string tmp = "";
            for(int j = 0; j < len; ++j) {
                if(i & (1 << j)) tmp += N[j];
            }
            if(!tmp.empty()) {
                ll val = stoll(tmp);
                if(isPrime(val)) res = max(res, val);
            }
        }
    }
    return res;
}

int main() {
    fastio();
    docfile();

    string n; cin >> n;
    cout << solve(n);

    time();
    return 0;
}