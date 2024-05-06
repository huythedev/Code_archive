#include <bits/stdc++.h>
using namespace std;

#define NAME "dtron"
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

    int r; cin >> r;

    ld c = 2 * r * M_PI, area = r * r * M_PI;

    cout << fixed << setprecision(4) << c << ln << area;

    return 0;
}