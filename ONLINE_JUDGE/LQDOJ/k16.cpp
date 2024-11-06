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

    int tests; cin >> tests;
    while(tests--) {
        int n; cin >> n;

        int res = 0;
        for(int i = 1; i * i <= n; ++i) {
            if(n % i == 0) {
                if(i % 2 == 0)
                    ++res;
                if(i * i != n)
                    if((n / i) % 2 == 0)
                        ++res;
            }
        }

        cout << res << ln;
    }

    return 0;
}