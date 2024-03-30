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

    ll n, m;
    cin >> n >> m;

    vector<ll> robot_health(n), navi_attack(m);

    for(ll i = 0; i < n; ++i) {
        cin >> robot_health[i];
    }
    for(ll i = 0; i < m; ++i) {
        cin >> navi_attack[i];
    }

    ll res = 0;
    sort(robot_health.begin(), robot_health.end());
    sort(navi_attack.begin(), navi_attack.end());

    ll i = 0, j = 0;
    while(i < n && j < m) {
        if(navi_attack[j] >= robot_health[i]) {
            res++;
            i++;
        }   
        j++;
    }
    cout << res;

    return 0;
}