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

    int max_len = 0;
    for(int i = 0; i < s.size(); ++i) {
        int tmp = 0;
        while(s[i] == s[i + 1]) {
            ++i;
            ++tmp;
        }
        max_len = max(max_len, tmp);
    }

    cout << max_len + 1;

    return 0;
}