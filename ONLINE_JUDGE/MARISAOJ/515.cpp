// Author: huythedev (https://huythedev.com)
// Problem Link: https://marisaoj.com/problem/515

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

const int maxn =  1e5 + 5;

int n, q;
vector<int> A(maxn);

void solve(int x) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2; 
        if (A[mid] > x) {
            r = mid - 1;
        }
        else if (A[mid] < x) {
            l = mid + 1;
        }
        else {
            cout << mid + 1 << ln;
            return;
        }
    }
}

signed main() {
    fastio();
    docfile();

    cin >> n >> q;
    A.resize(n);
    for (int i = 0; i < n; ++i) cin >> A[i];

    while (q--) {
        int x; cin >> x;
        solve(x);
    }

    time();
    return 0;
}