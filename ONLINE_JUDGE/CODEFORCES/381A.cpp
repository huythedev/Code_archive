// Author: huythedev (https://huythedev.com)
// Problem Link: https://codeforces.com/problemset/problem/381/A

#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
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

signed main() {
    fastio();
    docfile();

    int n;
    cin >> n;
    vector<int> cards(n);
    for (int i = 0; i < n; ++i) {
        cin >> cards[i];
    }

    int sereja = 0, dima = 0;
    bool serejaTurn = true;
    while (!cards.empty()) {
        if (cards.front() > cards.back()) {
            if (serejaTurn) {
                sereja += cards.front();
            } else {
                dima += cards.front();
            }
            cards.erase(cards.begin());
        } else {
            if (serejaTurn) {
                sereja += cards.back();
            } else {
                dima += cards.back();
            }
            cards.pop_back();
        }
        serejaTurn = !serejaTurn;
    }

    cout << sereja << " " << dima << ln;

    time();
    return 0;
}