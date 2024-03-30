#include <bits/stdc++.h>
using namespace std;

#define NAME "CHUMDEN"
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

    int N, K; cin >> N >> K;

    vector<int> A(N);
    for(int i = 0; i < N; ++i) 
        cin >> A[i];

    int res = 0;
    for(int i = 0; i < N; ++i) {
        int oddCount = 0;
        for(int j = i; j < N; ++j) {
            if(A[j] % 2 != 0) 
                ++oddCount;
            
            if(oddCount == K) 
                ++res;
            else if(oddCount > K) 
                break;
        }
    }

    cout << res;
    return 0;
}