// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "ongtimmat"
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

struct Hex {
    int q, r, s;
    
    Hex moveR() const {
        return {q + 1, r, s - 1};
    }
    
    Hex moveDL() const {
        return {q - 1, r + 1, s};
    }
    
    Hex moveDR() const {
        return {q, r + 1, s - 1};
    }
    
    bool operator<(const Hex& other) const {
        if (q != other.q) return q < other.q;
        if (r != other.r) return r < other.r;
        return s < other.s;
    }
    
    bool operator==(const Hex& other) const {
        return q == other.q && r == other.r && s == other.s;
    }
};

int m;
map<Hex, int> values, memo;

bool isValid(int q, int r, int s) {
    return abs(q) <= m && abs(r) <= m && abs(s) <= m && q + r + s == 0;
}

int recursive(Hex curr, Hex target) {
    if (!isValid(curr.q, curr.r, curr.s)) 
        return -1e9;

    if (curr == target) {
        return values[curr];
    }
    
    if (memo.count(curr)) 
        return memo[curr];
    
    int res = -1e9;
    
    if (curr.q < m && curr.s > -m) {
        Hex next = curr.moveR();
        res = max(res, recursive(next, target));
    }
    
    if (curr.q > -m && curr.r < m) {
        Hex next = curr.moveDL();
        res = max(res, recursive(next, target));
    }
    
    if (curr.r < m && curr.s > -m) {
        Hex next = curr.moveDR();
        res = max(res, recursive(next, target));
    }
    
    if (res != -1e9) {
        res += values[curr];
    }
    
    return memo[curr] = res;
}

void solve() {
    cin >> m;
    
    int hexSize = 1 + 3 * m * (m + 1);
    for (int i = 0; i < hexSize; ++i) {
        int q, r, s, val;
        cin >> q >> r >> s >> val;
        values[{q, r, s}] = val;
    }

    Hex target;
    cin >> target.q >> target.r >> target.s;

    Hex start = {0, -m, m};
    cout << recursive(start, target);
}

signed main() {
    docfile();
    fastio();

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}