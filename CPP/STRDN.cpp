#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if (ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    docfile();

    string S = "a";
    string st;
    getline(cin, st);
    S += st;

    ll Q;
    cin >> Q;
    ll l = S.length() - 1;

    while (Q--) {
        ll x;
        cin >> x;
		
		swap(S[x], S[l - x + 1]);
    }

	S.erase(0, 1);
    cout << S;

    return 0;
}
