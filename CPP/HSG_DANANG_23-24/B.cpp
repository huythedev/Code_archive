#include <bits/stdc++.h>
using namespace std;

#define NAME "GAME"
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

    string st;
    getline(cin, st);

    int D = 0, N = 0, H = 0;

    for(char c : st) {
        if(c == 'D') ++D;
        else if(c == 'N') ++N;
        else if(c == 'H') ++H;
    }

    cout << D << ' ' << N;

    return 0;
}