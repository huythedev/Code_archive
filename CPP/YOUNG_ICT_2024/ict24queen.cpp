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

    int T; cin >> T;
    while(T--) {
        int n, x, y, u, v;
        cin >> n >> x >> y >> u >> v;

        if(u > n || v > n) {
            cout << "NO" << ln;
        }
        else if(x == u || y == v) {
            cout << "YES" << ln;
        }
        else if(abs(x - u) == abs(y - v)) {
            cout << "YES" << ln;
        }
        else {
            cout << "NO" << ln;
        }
    }

    return 0;
}