#include <bits/stdc++.h>
using namespace std;

#define NAME "bdxau2"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if (ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    string st;

    while(cin >> st) {
    	int cnt = 0;
    	for(int i = 0; i < st.size() / 2; ++i) {
    		if(st[i] != st[st.size() - i - 1])
    			++cnt;
            if(cnt > 2)
                break;
    	}

    	if(cnt > 2) 
    		cout << "NO" << ln;
    	else 
    		cout << "YES" << ln;
    }

    return 0;
}
