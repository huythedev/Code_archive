// Author: huythedev
// Problem Link: https://marisaoj.com/problem/433
#include <bits/stdc++.h>
using namespace std;

#define NAME "433"
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
    int n, m; cin >> n >> m;
    vector<string> vec(n * 2 + m);
    map<char, int> freq;
    int i = 0;
    for (; i < n; ++i) {
        cin >> vec[i];
        for (char c : vec[i]) freq[c]++;
    }
    for (; i < n * 2; ++i) {
        vec[i] = vec[i - n];
        reverse(vec[i].begin(), vec[i].end());
    }

    for (int y = 0; y < m; ++y) {
        string str = "";
        for (int x = 0; x < n; ++x) {
            str += vec[x][y];
        }
        vec[i] = str;
        ++i;
    }

    // for (auto st : vec) cout << st << ln;

    string target; cin >> target;

    if (target.sz == 1) {
        if (freq[target[0]]) cout << "YES" << ln;
        else cout << "NO" << ln;
        return;
    }

    if (find(vec.begin(), vec.end(), target) != vec.end()) {
        cout << "YES" << ln;
    } else {
        cout << "NO" << ln;
    }
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