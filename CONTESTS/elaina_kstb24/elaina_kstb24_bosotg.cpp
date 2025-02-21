// Author: Perry (https://perrythedev.com)
// Problem Link: https://oj.vnoi.info/problem/elaina_kstb24_bosotg
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "BOSOTG"
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

bool is_triangles(int a, int b, int c) {
    return a + b > c && a + c > b && b + c > a;
}

int main() {
    fastio();
    docfile();

    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    sort(a.begin(), a.end());

    ll res = 0;
    for (int i = 0; i < n - 2; ++i) {
        int k = i + 2;
        for (int j = i + 1; j < n - 1; ++j) {
            while (k < n && a[i] + a[j] > a[k]) {
                ++k;
            }
            res += k - j - 1;
        }
    }

    cout << res;

    time();
    return 0;
}