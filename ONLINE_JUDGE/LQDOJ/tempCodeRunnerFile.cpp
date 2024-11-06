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

ll sumdiv(int n) {
    ll res = 0;
    for(int i = 1; i * i <= n; ++i) {
        if(n % i == 0) {
            res += i;
            if(i * i != n)
                res += n / i;
        }
    }

    return res - n;
}

bool isSpecial(int n) {
    return sumdiv(n) > n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    int L, R; cin >> L >> R;

    int res = 0;
    for(int i = L; i <= R; ++i)
        if(isSpecial(i))
            ++res;

    cout << res;

    return 0;
}