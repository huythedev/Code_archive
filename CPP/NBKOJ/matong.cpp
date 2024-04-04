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

int cntdiv(int n) {
    int res = 0;
    for(int i = 1; i*i <= n; i++) {
        if(n%i == 0) {
            if(i*i == n) res++;
            else res += 2;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    int N;
    cin >> N;

    ll res = 0;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        res += a * cntdiv(a);
    }

    cout << res;


    return 0;
}