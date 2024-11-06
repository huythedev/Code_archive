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

    int a, b, c; cin >> a >> b >> c;

    ld p = (a + b + c) / 2.0;
    cout << fixed << setprecision(2) << "Dien tich tam giac: " << sqrt(p * (p - a) * (p - b) * (p - c));

    return 0;
}