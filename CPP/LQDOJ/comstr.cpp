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

string compress(string st) {
    string res = "";
    for(int i = 0; i < st.length(); ++i) {
        int tmp = 1, j;
        for(int j = i + 1; j < st.length(); ++j) {
            if(st[i] == st[j])
                ++tmp;
            else 
                break;
        }
        if(tmp > 1) {
            res += to_string(tmp);
            res += st[i];
        }
        else {
            res += st[i];
        }
        i += tmp - 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    string st;
    cin >> st;

    cout << compress(st);

    return 0;
}