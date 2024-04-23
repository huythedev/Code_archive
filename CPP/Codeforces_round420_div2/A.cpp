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

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;

        map<int, int> freq;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            freq[x]++;
        }

        if(n < 3) 
            cout << 0 << ln;
        else {
            int res = 0;
            for(auto &kv : freq) {
                res += kv.second / 3;
            }

            cout << res << ln;
        }
    }

    return 0;
}