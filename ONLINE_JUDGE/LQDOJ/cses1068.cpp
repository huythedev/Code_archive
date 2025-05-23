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

    ll n; cin >> n;

    while(n != 1) {
        cout << n << " ";

        if(n % 2 == 0)
            n /= 2;
        else
            n = n * 3 + 1;
    }

    cout << 1;

    return 0;
}