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

    cout << "Hello world" << ln;
    for(int i = 1; i <= 5; ++i) {
        if(i <= 3) {
            for(int j = 0; j < i; ++j)
                cout << "*";
            cout << ln;
        }
        else {
            for(int j = 0; j < abs(5 - i + 1); ++j)
                cout << "*";
            cout << ln;
        }
    }

    return 0;
}