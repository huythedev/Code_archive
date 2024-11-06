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

    string st1, st2; cin >> st1 >> st2;
    map<char, int> m1, m2;
    for(char c : st1) m1[c]++;
    for(char c : st2) m2[c]++;

    int commonchar = 0;
    for(auto [c, cnt] : m1) {
        if(m2[c] > 0) {
            commonchar += min(cnt, m2[c]);
        }
    }

    cout << commonchar;

    return 0;
}