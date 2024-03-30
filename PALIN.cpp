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

    ll T;
    cin >> T;

    cin >> ws;

    while(T--) {
        string st;
        cin >> ws;
        getline(cin, st);

        string st1 = st;
        reverse(st1.begin(), st1.end());

        if(st1 == st) cout << "YES" << ln;
        else cout << "NO" << ln;
    }

    return 0;
}