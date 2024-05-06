#include <bits/stdc++.h>
using namespace std;

#define NAME "chuso"
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

    string s; cin >> s;
    int maxnum = 0;
    for(char c : s) 
        maxnum = max(maxnum, c - '0');

    cout << maxnum;

    return 0;
}