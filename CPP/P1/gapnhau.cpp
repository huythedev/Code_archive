#include <bits/stdc++.h>
using namespace std;

#define NAME "gapnhau"
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

    int d, v1, v2; cin >> d >> v1 >> v2;

    cout << fixed << setprecision(5) << (double)d / (v1 + v2);

    return 0;
}