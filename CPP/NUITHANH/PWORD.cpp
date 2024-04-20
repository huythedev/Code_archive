#include <bits/stdc++.h>
using namespace std;

#define NAME "PWORD"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if(ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

bool isnum(char c) {
    return c >= '0' && c <= '9';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    string s; getline(cin, s);
    int res = 0;
    for(char c : s) {
        if(isnum(c)) 
            res += c - '0';
    }
    cout << res;

    return 0;
}