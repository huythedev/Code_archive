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

    int x, n, m;
    cin >> x >> n >> m;

    ll res = 0;
    for(int i = 0; i <= n; ++i)
        res = (res + (ll)pow(x, i)) % m;
    
    cout << res;

    return 0;
}