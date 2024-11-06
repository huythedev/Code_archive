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

vector<ll> buildprefixsum(vector<int> vec) {
    vector<ll> res(vec.size() + 1);
    res[0] = 0;
    for(int i = 1; i <= vec.size(); ++i)
        res[i] = res[i - 1] + vec[i - 1];

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    int n, x, q;
    cin >> n >> x >> q;

    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    vector<ll> prefixsum = buildprefixsum(a);
    int res = 0;
    while(q--) {
        int l, r;
        cin >> l >> r;
        if((prefixsum[r] - prefixsum[l - 1]) < x)
            res++;
    }

    cout << res;

    return 0;
}