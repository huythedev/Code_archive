#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if(ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    int n, m; cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    while(m--) {
        int l, r; cin >> l >> r;
        --l; --r;

        int hcv = 0, hcb = 0, hcd = 0;
        for(int i = l; i <= r; ++i) {
            if(a[i] == 1) ++hcv;
            else if(a[i] == 2) ++hcb;
            else ++hcd;
        }

        cout << hcv << ' ' << hcb << ' ' << hcd << ln;
    }

    return 0;
}