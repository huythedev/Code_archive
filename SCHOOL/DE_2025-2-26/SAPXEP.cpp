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
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<pair<int, int>> ops;
    for(int i = 0; i < n - 1; i++) {
        int min_val = a[i];
        int j = i;
        for(int k = i + 1; k < n; k++) {
            if(a[k] < min_val) {
                min_val = a[k];
                j = k;
            }
        }
        if(j != i) {
            reverse(a.begin() + i, a.begin() + j + 1);
            ops.push_back({i + 1, j + 1});
        }
    }
    cout << ops.size() << endl;
    for(auto p : ops) {
        cout << p.first << " " << p.second << endl;
    }

    time();
    return 0;
}