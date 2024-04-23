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

    string s; getline(cin, s);
    
    while(s[0] == ' ') 
        s.erase(0, 1);

    s += ' ';

    int res = 0;
    vector<string> st_res;
    for(int i = 0; i < s.size(); ++i) {
        string tmp = "";

        while(s[i] != ' ') {
            if(s[i] - '0' >= 0 && s[i] - '0' <= 9) 
                res += s[i] - '0';
            else 
                tmp += s[i];
            ++i;
        }

        st_res.push_back(tmp);
    }

    cout << res << ' ';
    for(string i : st_res) {
        reverse(i.begin(), i.end());
        cout << i << ' ';
    }

    return 0;
}
