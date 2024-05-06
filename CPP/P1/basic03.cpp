#include <bits/stdc++.h>
using namespace std;

#define NAME "basic03"
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

    int t, n, m; cin >> t >> n >> m;

    cout << t * 3 + n * 2 + m * 5;

    return 0;
}