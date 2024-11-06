#include <bits/stdc++.h>
using namespace std;

#define NAME "BALLS"
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

const int maxn = 1e5;
ll tmp = 0, res = 0;
int n, q, a, b;
vector<ll> value(maxn), color(maxn);

void solve(vector<ll> vec) {
    for(int i = 0; i < vec.sz; ++i) {
        if(i != 0 && color[vec[i]] == color[vec[i - 1]])
            tmp += value[vec[i]] * a;
        else
            tmp += value[vec[i]] * b;
    }
    res = max(res, tmp);
    tmp = 0;
}

void dequy(const vector<ll>& vec, vector<ll>& current, int start, int k) {
    if(current.sz == k) {
        solve(current);
        return;
    }
    for(int i = start; i < vec.sz; ++i) {
        current.push_back(i);
        dequy(vec, current, i + 1, k);
        current.pop_back();
    }
}

int main() {
    fastio();
    docfile();
    
    cin >> n >> q;
    
    value.resize(n, 0); color.resize(n, 0);
    
    for(int i = 0; i < n; ++i) cin >> value[i];
    for(int i = 0; i < n; ++i) cin >> color[i];
    
    while(q--) {
        cin >> a >> b;
        for(int k = 1; k <= n; ++k) {
            vector<ll> current;
            dequy(color, current, 0, k);
        }
        cout << res << ln;
        res = 0;
    }
    time();
    return 0;
}
