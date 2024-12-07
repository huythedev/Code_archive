// Author: Perry (https://perrythedev.com)
// Problem Link: https://marisaoj.com/problem/546
#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
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

void solve(vector<int> vec, int n, int k) {
    if(vec.sz >= 2 && vec[vec.sz - 1] == vec[vec.sz - 2]) {
        return;
    }
    if(vec.sz == k) {
        for(int x : vec) cout << x << ' ';
        cout << ln;
        return;
    }

    for(int x = 1; x <= n; ++x) {
        vec.push_back(x);
        solve(vec, n, k);
        vec.pop_back();
    }
}

int main() {
    fastio();
    docfile();

    int n, k; cin >> n >> k;
    vector<int> vec;
    solve(vec, n, k);

    time();
    return 0;
}