// Author: huythedev (https://huythedev.com)
// Problem Link: https://coder.husc.edu.vn/problem/olpicpc074c16e
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "olpicpc074c16e"
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

int n, m;
string A, B;
unordered_set<string> ust;

bool isLucky(const string& s) {
    return ust.find(s) != ust.end();
}

int bfs() {
    queue<pair<string, int>> q;
    unordered_set<string> visited;
    q.push({A, 0});
    visited.insert(A);

    while (!q.empty()) {
        auto [current, steps] = q.front();
        q.pop();

        if (current == B) return steps;

        for (int i = 0; i < n; ++i) {
            string next = current;
            next[i] = (current[i] - '0' + 1) % 10 + '0';
            if (next == B || isLucky(next)) {
                if (visited.find(next) == visited.end()) {
                    q.push({next, steps + 1});
                    visited.insert(next);
                }
            }

            next[i] = (current[i] - '0' - 1 + 10) % 10 + '0';
            if (next == B || isLucky(next)) {
                if (visited.find(next) == visited.end()) {
                    q.push({next, steps + 1});
                    visited.insert(next);
                }
            }
        }
    }

    return -1;
}

int main() {
    fastio();
    docfile();

    cin >> n >> m;
    cin >> A >> B;
    for (int i = 0; i < m; ++i) {
        string st;
        cin >> st;
        ust.insert(st);
    }

    int res = bfs();
    if (res == -1) {
        cout << ":(" << ln;
    } 
    else {
        cout << res << ln;
    }

    time();
    return 0;
}