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

    int n, q;
    cin >> n >> q;
    vector<ll> a(n + 1);
    vector<ll> f(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    while (q--) {
        int L, R;
        ll V;
        cin >> L >> R >> V;
        f[L] += V;
        if (R + 1 <= n) {
            f[R + 1] -= V;
        }
    }

    for (int i = 1; i <= n; i++) {
        f[i] += f[i - 1];
    }

    for (int i = 1; i <= n; i++) {
        cout << a[i] + f[i] << " ";
    }


    return 0;
}