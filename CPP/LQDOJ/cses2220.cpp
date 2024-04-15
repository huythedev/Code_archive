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

bool isNoTwoAdjacent(ll n) {
    string s = to_string(n);
    for(ll i = 1; i < s.size(); ++i) {
        if(s[i] == s[i-1]) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    ll a, b; cin >> a >> b;

    ll res = 0;
    for(ll i = a; i <= b; ++i) {
        if(isNoTwoAdjacent(i)) res++;
    }

    cout << res;

    return 0;
}