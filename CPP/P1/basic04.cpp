#include <bits/stdc++.h>
using namespace std;

#define NAME "basic04"
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

    int a,b,c,m,n,k;
    cin >> a >> b >> c >> n >> m >> k;
    int d = n - m;
    cout << k * a + (m - k) * b + d * c;  


    return 0;
}