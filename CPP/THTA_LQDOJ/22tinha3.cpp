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

    int A, B; cin >> A >> B;

    ll res = 0;
    for(int x = A + 1; x < B; ++x) {
        if(x % 2 == 0 && x % 3 != 0) 
            res += x;
    }

    cout << res;

    return 0;
}