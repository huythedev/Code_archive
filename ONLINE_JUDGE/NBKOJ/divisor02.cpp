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

    int N;
    cin >> N;

    int cntdiv = 0, sumdiv = 0;
    for(int i = 1; i * i <= N; i++) {
        if(N % i == 0) {
            cntdiv++;
            sumdiv += i;
            if(i * i != N) {
                cntdiv++;
                sumdiv += N / i;
            }
        }
    }

    cout << cntdiv << ' ' << sumdiv;

    return 0;
}