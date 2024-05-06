#include <bits/stdc++.h>
using namespace std;

#define NAME "baitap231"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if(ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

const double PI = 3.1415926535897;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    double r1, r2; cin >> r1 >> r2;

    cout << fixed << setprecision(4) << PI * (r1 * r1 - r2 * r2);

    return 0;
}