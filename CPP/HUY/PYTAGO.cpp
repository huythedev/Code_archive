#include <bits/stdc++.h>
using namespace std;

#define NAME "PITAGO"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if(ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

bool isPytago(int a, int b, int c) {
    if(a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a)
        return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    int a, b, c; cin >> a >> b >> c;

    if(isPytago(a, b, c))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}