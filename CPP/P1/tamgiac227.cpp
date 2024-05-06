#include <bits/stdc++.h>
using namespace std;

#define NAME "tamgiac227"
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

    int x1, y1, x2, y2, x3, y3; cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    double a = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)),
           b = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3)),
           c = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));

    double p = (a + b + c) / 2.0;

    double area = sqrt(p * (p - a) * (p - b) * (p - c));

    cout << fixed << setprecision(3) << area << ln 
         << area * 2.0 / c << ' ' << area * 2.0 / b << ' ' << area * 2.0 / a;

    return 0;
}