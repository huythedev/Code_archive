// Author: Perry (https://perrythedev.com)
// Problem Link: https://coder.husc.edu.vn/problem/olpicpc068c15d
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "olpicpc068c15d"
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

const int MAX = 2e5 + 5;
int n;
vector<pair<int, int>> rules;
vector<bool> can_place;

void solve() {
    cin >> n;
    rules.resize(n);
    can_place.assign(n, true);
    
    vector<pair<int, int>> blocked;
    for (int i = 0; i < n; i++) {
        if (!can_place[i]) continue;
        
        blocked.push_back({i, i});
        
        auto [L, R] = rules[i];
        int left = max(0, i - L);
        int right = min(n - 1, i + R);
        
        for (int j = left; j < i; j++) 
            can_place[j] = false;
        for (int j = i + 1; j <= right; j++) 
            can_place[j] = false;
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++)
        if (can_place[i]) ans++;
    
    cout << ans << ln;
}

int main() {
    fastio();
    docfile();

    solve();

    time();
    return 0;
}