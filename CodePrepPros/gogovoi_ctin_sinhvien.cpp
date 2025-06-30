// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "gogovoi_ctin_sinhvien"
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

struct SinhVien {
    int toan, van, anh;
    int tong() const {
        return toan + van + anh;
    }
};

void solve() {
    int n; cin >> n;
    vector<SinhVien> a(n);
    for (int i = 0; i < n; ++i) 
        cin >> a[i].toan >> a[i].van >> a[i].anh;
    
    int res = 0;
    for (int i = 0; i < n; ++i) 
        res = max(res, a[i].tong());
    
    cout << res << ln;
}

signed main() {
    docfile();
    fastio();

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}