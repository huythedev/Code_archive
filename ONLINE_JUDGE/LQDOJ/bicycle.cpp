#include <bits/stdc++.h>
using namespace std;

#define NAME "bicycle"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if (ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

const double PI = 3.141592653589793238462643383;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    ll a, b;
    ld R, n;
    cin >> a >> b >> R >> n;

    ld length = 2 * PI * R;
    n *= 100000;

    ld tmp = n / length;

    ll res = tmp / b * a;

    cout << res;

    return 0;
}