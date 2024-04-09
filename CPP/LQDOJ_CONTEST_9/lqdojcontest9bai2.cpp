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

    ll N;
    cin >> N;

    ll le, chan;
    if(N % 2 == 0) {
        le = N / 2;
        chan = N / 2;
    } else {
        le = N / 2 + 1;
        chan = N / 2;
    }

    cout << le * chan;

    return 0;
}