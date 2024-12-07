// Author: Perry (https://perrythedev.com)
// Problem Link: https://marisaoj.com/problem/323
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
    if(vec.size() >= 2 && vec[vec.size() - 1] == vec[vec.size() - 2]) return;
    if(vec.size() == k) {
        for(int i : vec) cout << i << ' ';
        cout << '\n';
        return;
    }
    for(int i = 1; i <= n; ++i) {
        vec.push_back(i);
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