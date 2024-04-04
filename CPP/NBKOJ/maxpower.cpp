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

int maxk(int n, int m) {
    int k = 0;
    int p = m;
    while (n >= p) {
        k += n / p;
        p *= m;
    }
    
    if (k == 0) {
        return -1;
    } else {
        return k;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    int n, m;
    cin >> n >> m;

    cout << maxk(n, m);

    return 0;
}