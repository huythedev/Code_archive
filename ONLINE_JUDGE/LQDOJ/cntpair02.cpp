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

ll demcap(vector<int> arr, int n,int k) {
    map<int, int> freq;
    int cnt = 0;

    for (int i = 0; i < n; ++i) {
        int t = k - arr[i];
        if (freq.find(t) != freq.end()) {
            cnt += freq[t];
        }
        freq[arr[i]]++;
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) 
        cin >> arr[i];

    ll res = demcap(arr, n, k);
    cout << res;

    return 0;
}