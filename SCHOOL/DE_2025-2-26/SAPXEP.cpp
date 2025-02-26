// Author: Perry (https://perrythedev.com)
// Problem Link: 
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "SAPXEP"
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

int main() {
    fastio();
    docfile();

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    vector<int> b = a;
    sort(b.begin(), b.end());
    
    map<int, queue<int>> pos;
    for (int i = 0; i < n; i++) {
        pos[a[i]].push(i + 1); 
    }
    
    vector<pair<int, int>> ops;
    for (int i = 1; i <= n; i++) {
        int v = b[i - 1];
        while (!pos[v].empty() && pos[v].front() < i) {
            pos[v].pop(); 
        }
        if (pos[v].empty()) continue; 
        int j = pos[v].front();
        if (j != i) {
            ops.push_back({i, j});
            pos[v].pop();
        }
    }
    
    cout << ops.size() << "\n";
    for (auto [i, j] : ops) {
        cout << i << " " << j << "\n";
    }

    time();
    return 0;
}