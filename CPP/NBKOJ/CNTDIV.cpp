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

int cntDiv(int n) {
    int res = 0;
    int sqrt_n = sqrt(n);
    for(int i = 1; i <= sqrt_n; i++) {
        if(n % i == 0) {
            if(n / i == i)
                res++;
            else
                res += 2;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    int q;
    cin >> q;

    while(q--) {
        int n;
        cin >> n;

        cout << cntDiv(n) << ln;
    }

    return 0;
}