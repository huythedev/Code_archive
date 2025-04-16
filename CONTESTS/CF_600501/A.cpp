// Author: huythedev
// Problem Link: https://codeforces.com/group/G0iFI97YZN/contest/600501/problem/A
// davul
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
 
int n;
vector<int> vec(1e5 + 5, -1);

const int INF = 1e9 + 7;
 
int query(int i) {
    cout << "? " << i << ln;
    cout.flush();
    int x; cin >> x;
    return x;
}
 
signed main() {
    fastio();
    docfile();
 
    cin >> n;
    vec.resize(n + 2, -1);
    vec[0] = vec[n + 1] = INF;

    if (n == 1) {
        cout << "! 1" << ln;
        return 0;
    }
    
    int l = 1, r = n;
    while (l <= r) {
        int mid = (l + r) / 2;

        if (vec[mid] == -1) {
            vec[mid] = query(mid);
        }
        if (vec[mid - 1] == -1) {
            vec[mid - 1] = query(mid - 1);
        }
        if (vec[mid + 1] == -1) {
            vec[mid + 1] = query(mid + 1);
        }

        if (vec[mid - 1] > vec[mid] && vec[mid] < vec[mid + 1]) {
            cout << "! " << mid << ln;
            return 0;
        }
        else if (vec[mid] > vec[mid - 1])
            r = mid - 1;
        else
            l = mid + 1;
    }
 
    time();
    return 0;
}