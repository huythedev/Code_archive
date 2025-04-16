// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "GAME"
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

vector<int> grundy(6561, -1);

int getGrundy(int a, int b, int c, int d) {
    int index = a + 9 * b + 81 * c + 729 * d;
    
    if (grundy[index] != -1) return grundy[index];
    
    set<int> s;
    
    if (a >= 2 && b >= 1 && d >= 2) {
        s.insert(getGrundy(a - 2, b - 1, c, d - 2));
    }
    if (a >= 1 && b >= 1 && c >= 1 && d >= 1) {
        s.insert(getGrundy(a - 1, b - 1, c - 1, d - 1));
    }
    if (c >= 2 && d >= 1) {
        s.insert(getGrundy(a, b, c - 2, d - 1));
    }
    if (b >= 3) {
        s.insert(getGrundy(a, b - 3, c, d));
    }
    if (a >= 1 && d >= 1) {
        s.insert(getGrundy(a - 1, b, c, d - 1));
    }
    
    int mex = 0;
    while (s.find(mex) != s.end()) {
        mex++;
    }
    
    grundy[index] = mex;
    return mex;
}

signed main() {
    fastio();
    docfile();

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int g = getGrundy(a, b, c, d);
        if (g == 0) {
            cout << "BINH" << ln;
        } else {
            cout << "AN" << ln; 
        }
    }

    time();
    return 0;
}