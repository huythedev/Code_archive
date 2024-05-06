#include <bits/stdc++.h>
using namespace std;

#define NAME "pr"
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
    
    for(int i = 0; i < 5; ++i) 
    	cout << "Xin chao" << ln;

    return 0;
}
