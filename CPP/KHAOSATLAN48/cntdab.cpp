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
    vector<int> p(m), k(m);
    for(int i = 0; i < m; ++i) 
        cin >> p[i] >> k[i];
    
    for(int i = 0; i < 3; ++i) {
        int res = 0;
        int A, B; cin >> A >> B;
        for(int j = A; j <= B; ++j) {
            if(j == 1)
                ++res;
            
            auto it = find(p.begin(), p.end(), j);
            if(it != p.end()) 
                ++res;
            else {
                for(int k = 2; k <= sqrt(j); ++k) {
                    if(j % k == 0) {
                        it = find(p.begin(), p.end(), k);
                        if(it != p.end()) {
                            ++res;
                            break;
                        }
                    }
                }
            }
        }
        
        cout << res << ln;
    }

    return 0;
}