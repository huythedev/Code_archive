// Author: huythedev (https://huythedev.com)
// Problem Link: https://codeforces.com/group/G0iFI97YZN/contest/592900/problem/A

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

    string s; cin >> s;
    
    int n = s.size();
    vector<int> day(n, -1);  
    queue<pair<int, int>> q;  
    
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            day[i] = 0;
            q.push({i, 0});
        }
    }
    
    while (!q.empty()) {
        auto [pos, d] = q.front();
        q.pop();
        
        for (int next_pos : {pos-1, pos+1}) {
            if (next_pos >= 0 && next_pos < n && s[next_pos] == '0' && day[next_pos] == -1) {
                day[next_pos] = d + 1;
                q.push({next_pos, d + 1});
            }
        }
    }
    
    int res = 0;
    for (int i = 0; i < n; i++) {
        res = max(res, day[i]);
    }
    
    cout << res;

    time();
    return 0;
}