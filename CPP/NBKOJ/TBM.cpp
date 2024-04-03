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

    ld a, b, c;
    cin >> a >> b >> c;

    a *= 2;
    b *= 2;

    ld tbm = (a + b + c) / 5.0;

    if(tbm >= 8)
        cout << "gioi";
    else if(tbm >= 6.5)
        cout << "kha";
    else if(tbm >= 5.0)
        cout << "trung binh";
    else
        cout << "yeu";

    return 0;
}