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

    ll n;
    cin >> n;

    ll res = 0;
    if (n == 2)
        res = 1;
    else if (n == 4 || n == 1)
        res = 2;
    else {
        if (n % 3 == 0)
            res = n / 3;
        else if (n % 3 == 1)
            res = (n / 3) - 1 + 2;
        else 
            res = (n / 3) + 1;
    }

    cout << res << ln;

    return 0;
}
