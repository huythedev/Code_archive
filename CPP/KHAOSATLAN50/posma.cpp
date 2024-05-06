#include <bits/stdc++.h>
using namespace std;

#define NAME "posma"
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
    
    int n; cin >> n;

    int maxnum = 0, i = 0, pos = 0;
    while(n--) {
    	int t; cin >> t;
    	if(t > maxnum) {
    		maxnum = t;
    		pos = i;
    	}
    	++i;
    }

    cout << maxnum << ln << pos + 1;

    return 0;
}
