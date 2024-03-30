#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    string st;
    getline(cin, st);

    for(int z = 1; z <= 26; ++z) {
        string res = "";
        for(int i = 0; i < st.length(); ++i) {
            if(st[i] - '0' + z > 26) {
                res += toupper((char)(st[i] - 26 + z + '0'));
            } else {
                res += toupper((char)(st[i] + z + '0'));
            }
        }
        cout << res << endl;
    }
}