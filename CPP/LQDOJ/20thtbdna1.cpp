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

    int k;
    cin >> k;

    if(k % 10 == 0 || (k % 2 == 1 && k != 1))
        cout << -1;
    else {
        int cnt = 0;
        while(k != 1) {
            if(k % 6 == 0)
                k /= 6;
            else    
                k *= 3;
            ++cnt;
        }
        cout << cnt;
    }

    return 0;
}