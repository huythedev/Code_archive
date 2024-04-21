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

int A[1001], B[1001], res;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    int N; cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        B[A[i]]++;
    }

    for(int i = 0; i <= 1000; ++i) {
        if(B[i] > 0) 
            ++res;
    }

    cout << res << ln;

    for(int i = 0; i <= 1000; ++i) {
        if(B[i] > 0) 
            cout << i << ' ';
    }

    return 0;
}