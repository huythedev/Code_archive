// Author: huythedev (https://huythedev.com)
// Problem Link: 

#include <bits/stdc++.h>
using namespace std;

#define NAME "SAPXEP"
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

const int MAXN = 100005;

int n;
vector<int> a, sorted_a;
vector<pair<int, int>> steps;

void check(int l, int r) {
    reverse(a.begin() + l, a.begin() + r + 1);
    steps.push_back({l + 1, r + 1});
}

void solve() {
    sorted_a = a;
    sort(sorted_a.begin(), sorted_a.end());

    for (int i = 0; i < n; i++) {
        if (a[i] != sorted_a[i]) {
            int j = find(a.begin() + i, a.end(), sorted_a[i]) - a.begin();
            check(i, j);
        }
    }

    cout << steps.size() << endl;
    for (auto [l, r] : steps) {
        cout << l << " " << r << endl;
    }
}

int main() {
    fastio();
    docfile();

    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    solve();

    time();
    return 0;
}