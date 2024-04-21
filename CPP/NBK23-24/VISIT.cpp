#include <bits/stdc++.h>
using namespace std;

#define NAME "VISIT"
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
    int distance[n], consumption[m], arr[m];
    for(int i = 0; i < n; ++i) 
        cin >> distance[i];

    pair<int, int> pos[m];
    for(int i = 0; i < m; ++i) {
        cin >> consumption[i];
        pos[i] = {consumption[i], i};
    }

    sort(distance, distance + n, greater<int>());
    sort(pos, pos + m);

    ll res = 0;
    int position[n] = {0};
    for(int i = 0; i < n; ++i) {
        res += distance[i] * pos[i].first;
        position[i] = pos[i].second;
    }

    cout << res << ln;
    for(int i = 0; i < n; ++i) {
        cout << position[i] + 1 << " ";
    }

    return 0;
}