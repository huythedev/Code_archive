// Author: huythedev (https://huythedev.com)
// Problem Link: https://oj.vnoi.info/problem/lis

#include <bits/stdc++.h>
using namespace std;

#define NAME "LIS"
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
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    set<int> s;
    for(int i = 0; i < n; ++i) {
        auto it = s.lower_bound(a[i]);
        if(it != s.end()) {
            s.erase(it);
        }
        s.insert(a[i]);
    }

    cout << s.size();

    time();
    return 0;
}