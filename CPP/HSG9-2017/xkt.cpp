#include <bits/stdc++.h>
using namespace std;

#define NAME "xkt"
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

    for(int i = 1; i < s.size(); ++i) {
        string s1 = s.substr(0, i);
        string s2 = s.substr(i, s.size() - i);

        string tmp = s2 + s1;
        string tmp_rev = tmp;
        reverse(tmp_rev.begin(), tmp_rev.end());
        
        if(tmp == tmp_rev) {
            cout << i;
            return 0;
        }
    }

    cout << 0;

    return 0;
}