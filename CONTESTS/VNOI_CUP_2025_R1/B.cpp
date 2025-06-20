// Author: huythedev
// Problem Link:
#include <bits/stdc++.h>
using namespace std;

#define NAME "B"
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

void solve() {
    ll n, m;
    cin >> n >> m;
    
    if (n == m) {
        cout << "0" << ln;
        return;
    }
    
    if (n > m) {
        cout << "-1" << ln;
        return;
    }
    
    queue<ll> q;
    map<ll, pair<ll, ll>> parent;
    
    q.push(n);
    parent[n] = {-1, -1};
    
    while (!q.empty()) {
        ll curr = q.front();
        q.pop();
        
        vector<ll> divisors;
        for (ll i = 1; i * i <= curr; i++) {
            if (curr % i == 0) {
                if (i <= m) divisors.push_back(i);
                if (i != curr / i && curr / i <= m) divisors.push_back(curr / i);
            }
        }
        
        for (ll x : divisors) {
            ll g = __gcd(curr, x);
            ll next = curr * g;
            
            if (next > m || parent.count(next)) continue;
            
            parent[next] = {curr, x};
            
            if (next == m) {
                vector<ll> path;
                ll node = m;
                while (parent[node].second != -1) {
                    path.push_back(parent[node].second);
                    node = parent[node].first;
                }
                reverse(path.begin(), path.end());
                
                cout << path.size() << " ";
                for (ll x : path) {
                    cout << x << " ";
                }
                cout << ln;
                return;
            }
            
            q.push(next);
        }
    }
    
    cout << "-1" << ln;
}

signed main() {
    fastio();
    docfile();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}
