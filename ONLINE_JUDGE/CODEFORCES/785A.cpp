// Author: huythedev (https://huythedev.com)
// Problem Link: https://codeforces.com/problemset/problem/785/A

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
    unordered_map<string, int> polyhedrons = {
        {"Tetrahedron", 4},
        {"Cube", 6},
        {"Octahedron", 8},
        {"Dodecahedron", 12},
        {"Icosahedron", 20}
    };

    int total_faces = 0;
    for (int i = 0; i < n; ++i) {
        string polyhedron;
        cin >> polyhedron;
        total_faces += polyhedrons[polyhedron];
    }

    cout << total_faces << ln;

    time();
    return 0;
}