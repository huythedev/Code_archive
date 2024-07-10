#include <bits/stdc++.h>
using namespace std;

#define NAME "SQL"
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

    int n, m, v; cin >> n >> m >> v;

    vector<int> a(n + 1, 0);
    while(m--) {
        int i, j; cin >> i >> j;
        i--; j--;
        a[i]++;
        if(j + 1 < n) 
            a[j + 1]--;
    }

    for(int i = 1; i < n; ++i) 
        a[i] += a[i - 1];
    a.pop_back(); 

    sort(a.rbegin(), a.rend());

    cout << (ll)v * (a[0] + a[1] + a[2]);
    cerr << ln << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}
