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

    ll M;
    cin >> M;

    ll m200 = 0, m100 = 0;
    for(ll i = 0; i < M; ++i) {
        ll x;
        cin >> x;
        if(x == 200) {
            ++m200;
        } else {
            ++m100;
        }
    }

    if(m200 % 2 == 0 && m100 % 2 == 0) {
        cout << "YES";
    } else if(m200 % 2 == 1 && m100 % 2 == 0 && m100 >= 2) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}