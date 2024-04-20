#include <bits/stdc++.h>
using namespace std;

#define NAME "DANVU"
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
    vector<int> b(m);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < m; ++i) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int res = 0;
    int j = 0;
    for (int i = 0; i < n && j < m; ++i) {
        if (a[i] > b[j]) {
            res++;
            j++;
        }
    }

    cout << res;

    return 0;
}
