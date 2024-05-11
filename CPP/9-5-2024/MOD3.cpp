#include <bits/stdc++.h>
using namespace std;

#define NAME "MOD3"
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
	
	int L, R; cin >> L >> R;
        
    cout << (R / 3) - ((L - 1) / 3);    

    //cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
    return 0;
}
