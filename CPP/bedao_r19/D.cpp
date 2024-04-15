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

    int n, q; cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> b(n);
    for(int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    while(q--) {
        int l, r, x, y; cin >> l >> r >> x >> y;
        l--; r--; x--; y--;
        
        set<int> a1, b1;
        for(int i = l; i <= r; ++i) {
            a1.insert(a[i]);
        }
        for(int i = x; i <= y; ++i) {
            b1.insert(b[i]);
        }

        if(a1 == b1) {
            cout << "YES" << ln;
        } else {
            cout << "NO" << ln;
        }
    }

    return 0;
}