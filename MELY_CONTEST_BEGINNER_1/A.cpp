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

    string a, b;
    cin >> a >> b;

    if (b.length() < a.length()) {
        cout << "NO";
        return 0;
    }

    for (ll i = 0; i < b.length(); ++i) {
        if (b[i] != a[i]) {
            b.erase(i, 1);
            i--;
        }

        if (b.length() < a.length()) {
            cout << "NO";
            return 0;
        }
    }

    if (a == b) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
