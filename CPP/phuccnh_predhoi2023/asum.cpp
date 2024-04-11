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

vector<ll> buildprefixsum(vector<int> &vec) {
    int N = vec.size();
    vector<ll> res(N + 1);
    for(int i = 1; i <= N; i++) {
        res[i] = res[i - 1] + vec[i - 1];
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    int N, S;
    cin >> N >> S;

    ll res = 0;
    vector<int> vec(N);
    for(int i = 0; i < N; i++) {
        cin >> vec[i];
    }

    vector<ll> prefixsum = buildprefixsum(vec);
    for(int i = 1; i < prefixsum.size() - 1; ++i) {
        if(abs(prefixsum[i]) >= S) res++;
        for(int j = i + 1; j < prefixsum.size(); ++j) {
            if(abs(prefixsum[j] - prefixsum[i - 1]) >= S) {
                res++;
            }
        }
    }

    cout << res;

    return 0;
}