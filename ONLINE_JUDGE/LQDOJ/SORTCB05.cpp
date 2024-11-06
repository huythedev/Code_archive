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

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first)
        return a.second > b.second;
    return a.first > b.first;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> powers;
    for (int i = 0; i < n; ++i) {
        int phys_dmg, magic_dmg;
        cin >> phys_dmg >> magic_dmg;
        powers.push_back({phys_dmg, magic_dmg});
    }

    sort(powers.begin(), powers.end(), compare);

    cout << powers[m - 1].first << " " << powers[m - 1].second << endl;

    return 0;
}