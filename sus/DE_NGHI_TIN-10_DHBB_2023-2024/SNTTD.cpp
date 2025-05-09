// Author: huythedev
// Problem Link: 

#include <bits/stdc++.h>
using namespace std;

#define NAME "SNTTD"
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

const int MAXN = 1e6 + 5;
vector<vector<int>> prime_divs(MAXN);

void precompute() {
    for (int i = 2; i < MAXN; i++) {
        if (prime_divs[i].empty()) {
            for (int j = i; j < MAXN; j += i) {
                prime_divs[j].push_back(i);
            }
        }
    }
}

signed main() {
    fastio();
    docfile();
    precompute();


    int N, a, b;
    cin >> N >> a >> b;

    map<vector<int>, int> mp;
    for (int i = a; i <= b; i++) {
        mp[prime_divs[i]]++;
    }

    int max_count = 0;
    for (const auto& pair : mp) {
        max_count = max(max_count, pair.second);
    }

    cout << max_count << ln;
 
    time();
    return 0;
}