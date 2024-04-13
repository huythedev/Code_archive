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

    int N; cin >> N;
    double t, minscore = 10.0, res = 0;
    while(cin >> t) {
        minscore = min(minscore, t);
        res += t;
    }

    cout << fixed << setprecision(1) << res + 10.0 - minscore;

    return 0;
}