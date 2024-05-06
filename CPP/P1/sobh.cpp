#include <bits/stdc++.h>
using namespace std;

#define NAME "sobh"
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

    cout << (a + 1) / 2 + (b + 1) / 2 + (c + 1) / 2;

    return 0;
}