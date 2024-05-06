#include <bits/stdc++.h>
using namespace std;

#define NAME "bt"
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
    
    cout << 12 + 9 << ln << 12 - 9 << ln << 12 * 9 << ln << (ll)pow(12, 9);

    return 0;
}
