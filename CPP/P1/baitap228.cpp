#include <bits/stdc++.h>
using namespace std;

#define NAME "baitap228"
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

    double a, b; cin >> a >> b;

    cout << fixed << setprecision(6) << (a * a + b * b) / 2.0 << ln << (abs(a) + abs(b)) / 2.0;

    return 0;
}