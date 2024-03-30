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

    ld sumab, diffab;
    cin >> sumab >> diffab;

    ld a = (sumab + diffab) / 2;
    ld b = sumab - a;

    cout << fixed << setprecision(0) << a << ln << b;

    return 0;
}