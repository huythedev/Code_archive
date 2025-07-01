// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "gogovoi_alicebob"
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

struct State {
    set<int> alice, bob;
    bool operator==(const State& other) const {
        return alice == other.alice && bob == other.bob;
    }
};

struct HashState {
    size_t operator()(const State& s) const {
        size_t h1 = 0, h2 = 0;
        for (int x : s.alice) h1 = h1 * 31 + x;
        for (int x : s.bob) h2 = h2 * 31 + x;
        return h1 ^ h2;
    }
};

unordered_map<State, bool, HashState> memo;
int n;

bool beats(int a, int b) {
    return (a > b) || (a == 1 && b == n);
}

bool canAliceWin(const State& state) {
    if (state.alice.empty()) return false;
    if (state.bob.empty()) return true;
    if (memo.count(state)) return memo[state];
    for (int a : state.alice) {
        bool canWin = true;
        for (int b : state.bob) {
            State next;
            if (beats(a, b)) {
                next.alice = state.alice;
                next.alice.erase(a);
                next.alice.insert(b);
                next.bob = state.bob;
                next.bob.erase(b);
            } else {
                next.alice = state.alice;
                next.alice.erase(a);
                next.bob = state.bob;
                next.bob.insert(a);
            }
            if (!canAliceWin(next)) {
                canWin = false;
                break;
            }
        }
        if (canWin) {
            memo[state] = true;
            return true;
        }
    }
    memo[state] = false;
    return false;
}

void solve() {
    cin >> n;
        string s;
        cin >> s;
        State state;
        for (int j = 0; j < n; j++) {
            if (s[j] == 'A') state.alice.insert(j + 1);
            else state.bob.insert(j + 1);
        }
        memo.clear();
        cout << (canAliceWin(state) ? "Alice" : "Bob") << ln;
}

signed main() {
    docfile();
    fastio();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}