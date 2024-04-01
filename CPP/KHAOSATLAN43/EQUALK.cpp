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

    int n, k;
    cin >> n >> k;

    map<ll, int> freq;
    freq[0] = 1;
    ll prefix_sum = 0;
    ll res = 0;

    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        prefix_sum += x;
        res += freq[prefix_sum - k]; 
        freq[prefix_sum]++; 
    }

    cout << res;

    return 0;
}
