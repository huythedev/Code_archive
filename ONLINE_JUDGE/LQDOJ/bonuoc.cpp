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

bool isQuadDiv(int n) {
    int div = 0;
    for(int i = 1; i * i <= n; ++i) {
        if(n % i == 0) {
            div++;
            if(i * i != n)
                div++;
        }
        if(div > 4)
            return false;
    }
    if(div < 4)
        return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    int n; cin >> n;

    int res = 0;
    for(int i = 1; i * i <= n; ++i) {
        if(n % i == 0) {
            if(isQuadDiv(i))
                ++res;
            if(i * i != n)
                if(isQuadDiv(n / i))
                    ++res;
        }
    }

    cout << res;

    return 0;
}