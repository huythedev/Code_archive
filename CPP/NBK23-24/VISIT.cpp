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

    int n, m; cin >> n >> m;
    vector<int> distance(n), consumption(m);
    for(int &x : distance) cin >> x;
    for(int &x : consumption) cin >> x;

    vector<int> vec = consumption;
    sort(distance.rbegin(), distance.rend());
    sort(consumption.begin(), consumption.end());
    
    ll res = 0;
    vector<int> pos;
    for(int i = 0; i < n; ++i) {
        res += distance[i] * consumption[i];
        auto it = find(vec.begin(), vec.end(), consumption[i]);
        pos.push_back(it - vec.begin());
    }

    cout << res << ln;
    for(int x : pos) 
        cout << x + 1 << ' ';

    return 0;
}