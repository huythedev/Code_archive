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

    ld tong, hieu; cin >> tong >> hieu;

    ld A = (tong + hieu) / 2.0, B = tong - A;

    if(A == (ll)A && B == (ll)B)
        cout << fixed << setprecision(0) << A << ln << B;
    else 
        cout << fixed << setprecision(1) << A << ln << B;

    return 0;
}