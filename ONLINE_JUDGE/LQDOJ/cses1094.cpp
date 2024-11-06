#include <bits/stdc++.h>
using namespace std;

#define NAME "cses1094"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if (ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    int n; cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i];

    ll res = 0;
    for (int i = 1; i < n; ++i)
        if (x[i] < x[i - 1]) {
            res += abs(x[i] - x[i - 1]);
            x[i] = x[i - 1];
        }


    cout << res;

    return 0;
}