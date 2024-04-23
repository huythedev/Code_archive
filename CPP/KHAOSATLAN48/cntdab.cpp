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

    int m; cin >> m;
    int p[m], k[m];
    for(int i = 0; i < m; ++i) 
        cin >> p[i] >> k[i];
    
    for(int i = 0; i < 3; ++i) {
        int A, B; cin >> A >> B;

        int res = 0;
        for(int j = A; j <= B; ++j) {
            for(int &k : p) {
                if(j % k == 0) {
                    res++;
                    break;
                }
            }
        }

        cout << res << ln;
    }

    return 0;
}