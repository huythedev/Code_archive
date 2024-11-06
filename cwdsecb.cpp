#include <bits/stdc++.h>
using namespace std;

#define NAME "cwdsecb"
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
    cerr << ln << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." 
         << ln;
}

int main() {
    fastio();
    docfile();

    int n; cin >> n;
    vector<pair<int, int>> nums_and_pos(n);
    for (int i = 0; i < n; i++) {
        cin >> nums_and_pos[i].first;
        nums_and_pos[i].second = i;
    }

    sort(nums_and_pos.rbegin(), nums_and_pos.rend());

    cout << nums_and_pos[1].second + 1;

    time();
    return 0;
}