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

    ll a, b;
    cin >> a >> b;

    if(2 * a < b) 
        cout << N * a;
    else {
        if(N % 2 != 0) 
            cout << (N - 1) / 2 * b + a;
        else    
            cout << N / 2 * b;
    }

    return 0;
}