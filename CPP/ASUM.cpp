#include <bits/stdc++.h>
using namespace std;

#define NAME "ASUM"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if(ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

vector<ll> buildprefixsym(vector<int> &a) {
    int n = a.size();
    vector<ll> res(n + 1, 0);
    for(int i = 1; i <= n; i++) 
        res[i] = res[i - 1] + a[i - 1];

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    ll n, S; cin >> n >> S;
    int res = 0;
    vector<int> a(n);
    for(int &x : a) {
        cin >> x;
        if(abs(x) > S) res++;
    }
    
    vector<ll> prefixsum = buildprefixsym(a);
    
    for(int i = 1; i < prefixsum.size() - 1; i++) {
        for(int j = i + 1; j < prefixsum.size(); ++j) {
            if(abs(prefixsum[j] - prefixsum[i - 1]) > S) res++;
        }
    }

    cout << res;

    return 0;
}