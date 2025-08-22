// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "gogovoi_coban_traobai"
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
    int n, x; cin >> n >> x;
    
    list<int> cards;
    for (int i = 1; i <= n; ++i) cards.push_back(i);

    unordered_map<int, list<int>::iterator> pos;
    auto it = cards.begin();
    for (int i = 1; i <= n; ++i, ++it) {
        pos[i] = it;
    }

    while (x--) {
        int a, b; cin >> a >> b;

        auto it1 = pos[a];
        cards.erase(it1);

        auto it2 = pos[b];
        auto tmp = cards.insert(it2, a);
        
        pos[a] = tmp;
    }

    for (int i : cards) cout << i << ' ';
    cout << ln;
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