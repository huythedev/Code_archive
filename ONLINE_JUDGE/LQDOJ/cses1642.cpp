// Author: huythedev (https://huythedev.com)^
#include <bits/stdc++.h>
using namespace std;

#define NAME "cses1642"
#define ln endl

typedef long long ll;
typedef long double ld;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void docfile() {
    if(ifstream(NAME".INP")) {
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
}

void time() {
    cerr << ln << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << ln;
}

int main() {
    fastio();
    docfile();

    int n, x; cin >> n >> x;
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }

    sort(a.begin(), a.end());
    for(int i = 0; i < n - 3; ++i) {
        for(int j = i + 1; j < n - 2; ++j) {
            int left = j + 1;
            int right = n - 1;
            while(left < right) {
                ll sum = (ll)a[i].first + a[j].first + a[left].first + a[right].first;
                if(sum == x) {
                    vector<int> ans = {a[i].second, a[j].second, a[left].second, a[right].second};
                    sort(ans.begin(), ans.end());
                    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << ' ' << ans[3];
                    return 0;
                }
                else if(sum < x) 
                    ++left;
                else 
                    --right;
            }
        }
    }

    cout << "IMPOSSIBLE";
    
    time();
    return 0;
}