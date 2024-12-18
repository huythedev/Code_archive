// Author: Perry (https://perrythedev.com)
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "DQBN06"
#define ln "\n"
#define sz size()

typedef long long ll;
typedef long double ld;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void docfile() {
    if (ifstream(NAME ".INP")) {
        freopen(NAME ".INP", "r", stdin);
        freopen(NAME ".OUT", "w", stdout);
    }
}

void time() {
    cerr << ln << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << ln;
}

int main() {
    fastio();
    docfile();

    int n, k;
    cin >> n >> k;
    
    vector<pair<int,int>> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    
    sort(a.begin(), a.end());
    
    vector<int> res;
    ll sum = 0;
    for(int i = 0; i < n; ++i) {
        if(sum + a[i].first <= k) {
            sum += a[i].first;
            res.push_back(a[i].second);
        }
    }
    
    cout << res.size() << ln;
    for(int x : res) cout << x << " ";

    time();
    return 0;
}