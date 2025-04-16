// Author: huythedev (https://huythedev.com)
// Problem Link: https://marisaoj.com/problem/35
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

int main() {
    fastio();
    docfile();

    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i) 
        cin >> a[i];
    for(int i = 0; i < n; ++i)
        cin >> b[i];

    bool equal = true;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(int i = 0; i < n; ++i) {
        if(a[i] != b[i]) {
            equal = false;
            break;
        }
    }

    cout << (equal ? "YES" : "NO") << ln;

    time();
    return 0;
}