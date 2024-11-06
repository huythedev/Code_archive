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

    int a, b, u, v, x, y;
    cin >> a >> b >> u >> v >> x >> y;

    cout << "Tong so tien ve: " << (a + u) * (x - y) + (b + v) * y << " nghin dong.";

    return 0;
}