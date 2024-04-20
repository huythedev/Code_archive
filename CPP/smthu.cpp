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

ll sumdiv(int n) {
    ll sum = 0;
    for(int i = 1; i <= sqrt(n); i++) {
        if(n % i == 0) {
            sum += i;
            if(i != n / i) sum += n / i;
        }
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    int q; cin >> q;
    vector<int> a(q);
    for(int &i : a) cin >> i;

    for(int i : a) {
        cout << sumdiv(i) << ' ';
    }

    return 0;
}
