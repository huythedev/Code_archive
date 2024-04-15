#include <bits/stdc++.h>
using namespace std;

#define NAME "LONGWORD"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if(ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

string reverse_word(string st) {
    string res = "";
    string tmp = "";

    for (int i = 0; i < st.length(); i++) {
        if (st[i] == ' ') {
            reverse(tmp.begin(), tmp.end());
            res += tmp + " ";
            tmp = "";
        } else {
            tmp += st[i];
        }
    }

    reverse(tmp.begin(), tmp.end());
    res += tmp;

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    string st1; getline(cin, st1);

    int maxlen = 0;
    vector<string> res;
    vector<int> pos;
    string st = reverse_word(st1);

    for(int i = 0; i < st.size(); ++i) {
        if(st[i] != ' ') {
            int len = 0;
            while(i < st.size() && st[i] != ' ') {
                ++len;
                ++i;
            }
            if(len > maxlen) {
                maxlen = len;
                res.clear();
                pos.clear();

                res.push_back(st.substr(i - len, len));
                pos.push_back(i - len);
            } 
            else if(len == maxlen) {
                res.push_back(st.substr(i - len, len));
                pos.push_back(i - len);
            }
        }
    }

    cout << st << ln;
    for(int i = 0; i < res.size(); ++i) {
        cout << res[i] << " " << pos[i] + 1 << ln;
    }

    return 0;
}