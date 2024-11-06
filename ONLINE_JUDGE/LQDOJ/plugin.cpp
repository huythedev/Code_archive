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

    int n, m; cin >> n >> m;
    vector<int> a(n);
    int tmp = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        tmp += a[i];
    }

    if(tmp - n + 1 < m)
        cout << -1;
    else if(m == 1) 
        cout << 0;
    else {
        int res = 1, t = 0;
        sort(a.rbegin(), a.rend());
        t += a[0];
        for(int i = 1; i < n; ++i) {
            if(t >= m) break;
            t += a[i] - 1;
            ++res;
        }

        cout << res;
    }

    return 0;
}