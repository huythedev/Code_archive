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

    string a, b;
    cin >> a >> b;

    while(a[0] == 0) {
        a.erase(0, 1);
    }

    while(b[0] == 0) {
        b.erase(0, 1);
    }

    if(a.length() > b.length()) {
        cout << "LON HON";
        return 0;
    }
    else if(a.length() < b.length()) {
        cout << "NHO HON";
        return 0;
    }
    else {
        for(ll i = 0; i < 1000000000; ++i) {
            if(a[i] < b[i]) {
                cout << "NHO HON";
                return 0;
            }

            if(a[i] > b[i]) {
                cout << "LON HON";
                return 0;
            }
        }
    }

    cout << "BANG NHAU";

    return 0;
}