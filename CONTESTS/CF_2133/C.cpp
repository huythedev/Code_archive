// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
#define ln "\n"
#define sz size()

typedef long long ll;
typedef long double ld;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void fileIO() {
    if (ifstream(NAME ".INP")) {
        freopen(NAME ".INP", "r", stdin);
        freopen(NAME ".OUT", "w", stdout);
    }
}

void time() {
    cerr << ln << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." 
         << ln;
}

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n + 1);
    int M = 0;
    for (int i = 1; i <= n; i++) {
        cout << "? " << i << ' ' << n << ' ';

        for (int j = 1; j <= n; j++) 
            cout << j << ' ';
        
        cout << ln;
        cout.flush();

        int tmp;
        cin >> tmp;

        vec[i] = tmp;
        M = max(M, tmp);
    }

    vector<vector<int>> vec2(M + 1);
    for (int i = 1; i <= n; i++)
        vec2[vec[i]].push_back(i);

    sort(vec2[M].begin(), vec2[M].end());

    vector<int> path;

    int curr = vec2[M][0];
    path.push_back(curr);
    int level = M;
    
    while (level > 1) {
        vector<int> tmp = vec2[level - 1];

        sort(tmp.begin(), tmp.end());

        while ((int)tmp.size() > 1) {
            int mid = (int)tmp.size() / 2;

            vector<int> D(tmp.begin(), tmp.begin() + mid);
            vector<int> D2 = D;

            D2.push_back(curr);
            sort(D2.begin(), D2.end());

            cout << "? " << curr << ' ' << (int)D2.size() << ' ';

            for (int x : D2) 
                cout << x << ' ';

            cout << ln;
            cout.flush();

            int tmp2;
            cin >> tmp2;
            
            if (tmp2 >= 2){
                tmp = D;
            }
            else {
                vector<int> newtmp(tmp.begin() + mid, tmp.end());
                tmp = newtmp;
            }
        }
        
        int next = tmp[0];
        path.push_back(next);
        curr = next;
        level--;
    }

    cout << "! " << (int)path.size() << ' ';
    for (int x : path)
        cout << x << ' ';
    
    cout << ln;
    cout.flush();
}

signed main() {
    fastIO();
    fileIO();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}