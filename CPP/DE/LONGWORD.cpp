#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void docfile() {
    freopen("LONGWORD.inp", "r", stdin);
    freopen("LONGWORD.out", "w", stdout);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    //docfile();
    string st;
    getline(cin, st);

    vector <string> res;
    vector <ll> pos;

    ll lonnhat = 0;
    for (ll i = 0; i < st.length(); ++i) {
        ll tmp = 0;
        if (st[i] != ' ') {
            for (ll j = i + 1; j < st.length(); ++j) {
                if (st[j] == ' ') {
                    tmp = j - 1;
                    lonnhat = max(lonnhat, j - i - 1);
                    break;
                }
                if (j == st.length() - 1) {
                    lonnhat = max(lonnhat, j - i + 1);
                    tmp = j;
                }
            }
        }
        if (tmp != 0) {
            reverse(st.begin() + i, st.begin() + tmp + 1);
            res.push_back(st.substr(i, tmp - i + 1));
            pos.push_back(i);
            i = tmp + 1;
        }
    }

    for (ll i = 0; i < res.size(); ++i) {
        if (res[i].length() == lonnhat) {
            cout << res[i] << " " << pos[i] + 1 << endl;
        }
    }
    return 0;
}
