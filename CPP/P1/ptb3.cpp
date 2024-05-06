#include <bits/stdc++.h>
using namespace std;

#define NAME "ptb3"
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

    int x1, x2, x3; cin >> x1 >> x2 >> x3;

    cout << -(x1 + x2 + x3) << ' ' << x1 * x2 + x2 * x3 + x3 * x1 << ' ' << x1 * x2 * x3;

    return 0;
}