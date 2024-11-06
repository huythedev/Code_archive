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

    string s; cin >> s;

    cout << s << ln;

    int char_2 = 0;
    for(char c : s) 
        if(c - '0' == 2) ++char_2;
    cout << char_2 << ln;

    if(s[0] == s[s.size() - 1])
        cout << "YES" << ln;
    else 
        cout << "NO" << ln;

    reverse(s.begin(), s.end());
    cout << s << ln;

    return 0;
}