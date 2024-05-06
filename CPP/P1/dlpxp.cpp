#include <bits/stdc++.h>
using namespace std;

#define NAME "dlpxp"
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

    int a, b, u, v, x, y; cin >> a >> b >> u >> v >> x >> y;

    cout << (x - y) * (a + u) + y * (b + v);

    return 0;
}