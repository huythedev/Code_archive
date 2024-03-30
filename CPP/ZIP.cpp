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
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    string S;
    cin >> S;

    string res = "";
    ll M = LLONG_MIN;

    for (ll i = 0; i < S.length(); ++i) {
        ll j = i + 1;
        while (j < S.length() && S[j] == S[i]) {
            ++j;
        }

        res += S[i];
        res += to_string(j - i);
        M = max(M, j - i);
        
        i = j - 1;
    }

    cout << res << ln << M;

    return 0;
}
