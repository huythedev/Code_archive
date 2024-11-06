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

    int n, k; cin >> n >> k;

    vector<int> a(n);
    int t;
    for(int i = 0; i < n; ++i) 
        cin >> a[i];
    
    sort(a.begin(), a.end());

    int res = INT_MAX;
    for(int i = 0; i < k; ++i) {
        res = min(res, a[n - k + i] - a[i]);
    }

    cout << res;

    return 0;
}