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

ll giaithua(int n) {
    ll res = 1;
    for(int i = 1; i <= n; ++i) {
        res *= i;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        cout << giaithua(n) << ln;
    }

    return 0;
}