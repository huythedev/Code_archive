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

    int N;
    cin >> N;

    vector<int> a(N);
    for(int i = 0; i < N; i++)
        cin >> a[i];

    vector<ll> prefixsum = buildprefixsum(a);
    ll res = 0;
    for(int i = 0; i < N; i++) {
        for(int j = i; j < N; j++) {
            ll sum = prefixsum[j + 1] - prefixsum[i];
            res = max(res, sum);
        }
    }

    cout << res;

    return 0;
}