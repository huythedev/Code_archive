#include <bits/stdc++.h>
using namespace std;

#define NAME "PTICH"
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

    int N; cin >> N;
    for(int i = 2; i * i <= N; ++i) {
        int freq = 0;
        while(N % i == 0) {
            ++freq;
            N /= i;
        }
        if(freq != 0) 
            cout << i << ' ' << freq << ln;
    }

    if(N != 1)
        cout << N << ' ' << 1;

    return 0;
}