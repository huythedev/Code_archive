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

bool isnum(char c) {
    return c >= '0' && c <= '9';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    string st; cin >> st;
    
    for(int i = 0; i < st.size(); i++) {
        if(!isnum(st[i])) {
            cout << st[i];
            continue;
        }
        int x = 0;
        while(i < st.size() && isnum(st[i])) {
            x = x * 10 + (st[i] - '0');
            i++;
        }
        while(x--) 
            cout << st[i];
    }

    return 0;
}