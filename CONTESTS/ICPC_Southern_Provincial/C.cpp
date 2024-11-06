#include <bits/stdc++.h>
using namespace std;

#define NAME "C"
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

const int MAXN = 1e6 + 5;
vector<int> w(MAXN), a(MAXN), b(MAXN);

ll solve(int n) {
    vector<int> pos(n);  
    for (int i = 0; i < n; i++) 
        pos[b[i]] = i;  
    
    vector<bool> vec(n, false);
    ll res = 0;
    int tmp = *min_element(w.begin(), w.begin() + n);  
    
    for (int i = 0; i < n; i++) {
        if (!vec[i]) {
            vector<int> tmp2;
            int j = i;
            int min_cost = INT_MAX;
            ll tong = 0;
            
            while (!vec[j]) {
                vec[j] = true;
                tmp2.push_back(j);
                min_cost = min(min_cost, w[a[j]]);
                tong += w[a[j]];
                j = pos[a[j]];  
            }
            
            if (tmp2.sz > 1) {
                res += min(tong + (tmp2.sz - 2) * min_cost, tong + min_cost + (tmp2.sz + 1) * tmp);
            }
        }
    }
    
    return res;
}

int main() {
    fastio();
    docfile();
    
    int n; cin >> n;
    
    for (int i = 0; i < n; i++) 
        cin >> w[i];
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;  
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        b[i]--;  
    }
    
    cout << solve(n) << ln;
    
    time();
    return 0;
}
