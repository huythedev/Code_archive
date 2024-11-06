#include <bits/stdc++.h>
using namespace std;

#define NAME "2022thtc2b1"
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
    
    double X; cin >> X;

    int tmp = X * 10;

    if(tmp % 10 <= 5) 
    	cout << int(X);
   	else
   		cout << int(X) + 1;

    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
    return 0;
}
