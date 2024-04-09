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

const int MAX_N = 1e5 + 5; 

int sumDiv[MAX_N];

void buildvec() {
    for(int i = 1; i < MAX_N; ++i) {
        for(int j = i * 2; j < MAX_N; j += i) {
            sumDiv[j] += i;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    buildvec();

    int Q;
    cin >> Q;

    while(Q--) {
        ll res = 0;
        ll L, R, X;
        cin >> L >> R >> X;

        if(L < X && R >= X) {
            for(ll i = X; i <= R; ++i) {
                if(sumDiv[i] > X) {
                    res++;
                }
            }
        }
        else if(L < X && R < X) {
            res = 0;
        }
        else {
            for(ll i = L; i <= R; ++i) {
                if(sumDiv[i] > X) {
                    res++;
                }
            }
        }
        
        cout << res << ln;
    }

    return 0;
}
