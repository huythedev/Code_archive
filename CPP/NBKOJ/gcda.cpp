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

    int res = 0;
    vector<int> a(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
       if(res == 0)
            res = a[i];
        else
            res = __gcd(res, a[i]);
    }

    cout << res;

    return 0;
}