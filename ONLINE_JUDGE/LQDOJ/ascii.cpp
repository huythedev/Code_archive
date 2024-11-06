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

    string st; cin >> st;
    string res = "";
    for(int i = 0; i < st.length(); ++i) {
        if(st[i] == '1') {
            string tmp = st.substr(i, 3);
            int t = stoi(tmp);
            res += (char)t;
            i += 2;
        }
        else if(st[i] == '9'){
            string tmp = st.substr(i, 2);
            int t = stoi(tmp);
            res += (char)t;
            i += 1;
        }
    }

    cout << res;

    return 0;
}