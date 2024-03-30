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
    vector<ll> res(vec.size() + 1);
    res[0] = 0;
    
    for(ll i = 1; i <= vec.size(); ++i) {
        res[i] = res[i - 1] + vec[i - 1];
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    ll N;
    cin >> N;
    
    vector<ll> vec(N);
    for(ll i = 0; i < N; ++i) 
        cin >> vec[i];
        
    vector<ll> prefixsum = buildprefixsum(vec);    
    
    ll res = 0;
    map<ll, ll> freq;
    for(ll L = 1; L < prefixsum.size() - 1; ++L) {
        for(ll R = L + 1; R < prefixsum.size(); ++R) {
            freq[prefixsum[R] - prefixsum[L - 1]]++;
        }
    }
    
    ll max_doan = 0;
    for(auto &kv : freq) {
        ll tmp = kv.second;
        max_doan = max(max_doan, tmp);
    }
    
    cout << max_doan;  

    return 0;
}
