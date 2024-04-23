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

    int tests; cin >> tests;
    while(tests--) {
        string s;
        cin >> s;

        string s2 = s;
        reverse(s2.begin(), s2.end());
        if(s == s2 && s.size() % 2 == 0) 
            cout << "YES" << ln;
        else 
            cout << "NO" << ln;
    }

    return 0;
}