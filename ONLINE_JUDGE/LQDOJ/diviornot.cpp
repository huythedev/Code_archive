#include <bits/stdc++.h>
using namespace std;

#define NAME "diviornot"
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

    for(int i = 1; i <= n; ++i) 
    	if(i % 3 == 0 && i % 5 != 0)
    		cout << i << ' ';

    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
    return 0;
}
