#include <bits/stdc++.h>
using namespace std;

#define NAME "HCN2D"
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

    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    int u1, v1, u2, v2; cin >> u1 >> v1 >> u2 >> v2;
    
    int x = max(0, min(x2, u2) - max(x1, u1));
    int y = max(0, min(y2, v2) - max(y1, v1));

    cout << x * y;

    return 0;
}