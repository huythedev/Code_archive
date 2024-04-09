#include <bits/stdc++.h>
using namespace std;

#define NAME "FIB"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if(ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

const ll maxn = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    vector<ll> fib(30);
    fib[0] = 1;
    fib[1] = 1;

    for(int i = 2; i < 30; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
        if(fib[i] > 2000) 
            break;
    }

    cout << fib[16];
    return 0;
}