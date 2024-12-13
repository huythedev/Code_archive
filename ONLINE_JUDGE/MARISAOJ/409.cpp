// Author: Perry (https://perrythedev.com)
// Problem Link: https://marisaoj.com/problem/409
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
    vector<int> a(n);
    for (int &x : a) cin >> x;

    reverse(a.begin(), a.end());
    int max_val = a[0], ans = 0;
    for(int i = 1; i < n; ++i) {
        if(a[i] > max_val) {
            max_val = a[i];
            ans++;
        }
    }
    cout << ans;

    time();
    return 0;
}