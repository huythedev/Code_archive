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
    for(int i = 1; i <= vec.size(); i++)
        res[i] = res[i - 1] + vec[i - 1];
    
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    int n, q;
    cin >> n >> q;

    vector<int> x(n);
    for(int i = 0; i < n; i++)
        cin >> x[i];

    vector<ll> prefixsum = buildprefixsum(x);
    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int p, v;
            cin >> p >> v;
            p--;
            x[p] = v;
            prefixsum = buildprefixsum(x);
        }
        else {
            int l, r;
            cin >> l >> r;
            l--; r--;
            cout << prefixsum[r + 1] - prefixsum[l] << ln;
        }
    }

    return 0;
}