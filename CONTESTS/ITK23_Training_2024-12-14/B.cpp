// Author: Perry (https://perrythedev.com)
// Problem Link: https://codeforces.com/group/G0iFI97YZN/contest/573643/problem/B
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

int main() {
    fastio();
    docfile();

    int n, m; cin >> n >> m;
    vector<int> leaders(m);
    for(int i = 0; i < m; ++i) {
        cin >> leaders[i];
    }

    vector<int> a(n, -1);
    unordered_set<int> used;
    bool possible = true;

    for(int i = 0; i < m - 1; ++i) {
        int current = leaders[i] - 1;
        int next = leaders[i + 1] - 1;
        int distance = (next - current + n) % n;
        if(distance == 0) 
            distance = n;

        if(a[current] == -1) {
            if(used.count(distance)) {
                possible = false;
                break;
            }
            a[current] = distance;
            used.insert(distance);
        } 
        else if(a[current] != distance) {
            possible = false;
            break;
        }
    }

    if(!possible) {
        cout << -1 << ln;
    } 
    else {
        for(int i = 0; i < n; ++i) {
            if(a[i] == -1) {
                for(int j = 1; j <= n; ++j) {
                    if(!used.count(j)) {
                        a[i] = j;
                        used.insert(j);
                        break;
                    }
                }
            }
        }
        for(int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }
        cout << ln;
    }

    time();
    return 0;
}