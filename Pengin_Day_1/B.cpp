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

vector<ll> buildprefixsum(vector<ll> vec) {
    int vs = vec.size();
    vector<ll> res(vs + 1, 0);
    res[0] = 0;
    for(int i = 1; i <= vs; ++i) 
        res[i] = res[i - 1] + vec[i - 1];

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    int N, q;
    cin >> N >> q;

    vector<ll> a(N);
    for(int i = 0; i < N; ++i) 
        cin >> a[i];

    vector<ll> prefixsum = buildprefixsum(a);

    while(q--) {
        int l, r;
        cin >> l >> r;
        cout << prefixsum[r] - prefixsum[l - 1] << ln;
    }

    return 0;
}