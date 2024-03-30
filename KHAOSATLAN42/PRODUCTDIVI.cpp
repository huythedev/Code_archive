#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
#define ln '\n'

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;

void docfile() {
    if(ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    docfile();

    int m;
    cin >> m;

    map<int, int> freq;
    int tmp = -1;
    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;
        if(tmp == -1) {
            tmp = x;
        }
        freq[x]++;
    }

    ll res = 1;
    for(auto &i : freq) {
        if(i.first != tmp) {
            res = (res * i.second) % MOD;
        }
    }

    for(int i = 1; i <= freq[tmp]; ++i) {
        res = (res * i) % MOD;
    }

    cout << res;

    return 0;
}
