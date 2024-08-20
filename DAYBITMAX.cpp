#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string st;
    getline(cin, st);

    ll tmp = 0, tmp1 = 0, Max = 0, t = 1;
    for (ll i = 0; i < st.length();) {
        if(tmp == 0 && tmp1 == 0) {
        	while (i < st.length() && st[i] == '0') {
            	++tmp;
            	++i;
        	}
        }
        while (i < st.length() && st[i] - '0' == t) {
            ++tmp1;
            ++i;
        }

        Max = max(Max, min(tmp, tmp1) * 2);
        tmp = tmp1;
        tmp1 = 0;
        if(t == 1) {
        	t = 0;
        }
        else {
        	t = 1;
        }
    }

    cout << Max;
    return 0;
}
	