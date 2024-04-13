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

    string b, a; cin >> b >> a;

    int res = 0;
    for(int i = 0; i < b.size(); i++) {
        string tmp = b.substr(i, a.size());
        if(tmp == a) {
            res++;
            i += a.size() - 1;
        }
    }

    cout << res;

    return 0;
}