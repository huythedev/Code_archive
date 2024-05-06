#include <bits/stdc++.h>
using namespace std;

#define NAME "csldt"
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

    double x; cin >> x;

    cout << ll(x * 10) % 10;

    return 0;
}