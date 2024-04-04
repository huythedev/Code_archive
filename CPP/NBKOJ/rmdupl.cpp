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

    string s;
    getline(cin, s);

    string res;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (res.empty() || res.back() != c) {
            res.push_back(c);
        } else {
            res.pop_back();
        }
    }
    
    cout << res << endl;

    return 0;
}