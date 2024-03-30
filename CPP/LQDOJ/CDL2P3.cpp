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

    ll a, b, c;
    cin >> a >> b >> c;

    if(a > 0 && b > 0 && c > 0) 
        cout << "Ca ba so deu duong";
    else 
        cout << "It nhat mot so am";

    return 0;
}