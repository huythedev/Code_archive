#include <bits/stdc++.h>
using namespace std;

#define NAME "SOK"
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
    int a[N], maxnum = 0, freq[5 * int(1e3) + 5] = {0};
    for(int i = 0; i < N; ++i) {
        cin >> a[i];
        freq[a[i]]++;
        maxnum = max(maxnum, a[i]);
    }
    
    int tmp = 0;
    while(maxnum--) {
        if(freq[maxnum] != 0) 
            ++tmp;
        if(tmp == K - 1) {
            cout << maxnum;
            return 0;
        }
    }

    return 0;
}