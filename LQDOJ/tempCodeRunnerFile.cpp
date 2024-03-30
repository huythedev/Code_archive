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

    int X, Y;
    cin >> X >> Y;

    if(X >= (X + Y) / 100 * 10) {
        cout << "Arabica duoc mua." << ln 
             << "He so gia ban: " << 2;
    }
    else {
        cout << "Arabica mat mua." << ln 
             << "He so gia ban: " << 3;
    }

    return 0;
}