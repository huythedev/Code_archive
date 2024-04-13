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
    int n = vec.size();

    vector<ll> res(n + 1);
    res[0] = 0;
    for(int i = 1; i <= vec.size(); ++i) 
        res[i] = res[i - 1] + vec[i - 1];

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    vector<ll> prefixsum = buildprefixsum(a);
    for(int i = 1; i <= n; ++i) {
        if(prefixsum[n] - prefixsum[i - 1] == prefixsum[i - 1]) {
            cout << i - 1;
            return 0;
        }
    }

    cout << 0;

    return 0;
}