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

    int n, m, k; cin >> n >> m >> k;
    vector<int> a;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            a.push_back(i * j);
        }
    }

    sort(a.begin(), a.end());

    cout << a[k - 1];

    return 0;
}