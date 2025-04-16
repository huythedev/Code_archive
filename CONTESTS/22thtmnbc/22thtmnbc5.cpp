// Author: huythedev (https://huythedev.com)
// Problem Link: https://lqdoj.edu.vn/problem/22thtmnbc5
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "22thtmnbc5"
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
    srand(time(0));

    int n, m;
    cin >> n >> m;
    
    vector<vector<ll>> coordination(n+1, vector<ll>(n+1, 0));
    for (int i = 0; i < m; i++) {
        int u, v;
        ll c;
        cin >> u >> v >> c;
        coordination[u][v] = coordination[v][u] = c;
    }
    
    vector<bool> best_group;
    ll best_coordination = 0;
    
    if (n <= 20) {
        best_group.resize(n+1, false);
        
        for (int mask = 1; mask < (1 << n); mask++) {
            vector<bool> group(n+1, false);
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    group[i+1] = true;  
                }
            }
            
            ll total_coordination = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = i+1; j <= n; j++) {
                    if (group[i] && group[j]) {
                        total_coordination += coordination[i][j];
                    }
                }
            }
            
            if (total_coordination > best_coordination) {
                best_coordination = total_coordination;
                best_group = group;
            }
        }
    } else {
        best_group.resize(n+1, false);
        
        const int num_restarts = 1000;
        const int local_search_steps = 1000;
        
        for (int restart = 0; restart < num_restarts; restart++) {
            vector<bool> in_group(n+1, false);
            
            for (int i = 1; i <= n; i++) {
                in_group[i] = (rand() % 2 == 1);
            }
            
            ll current_coordination = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = i+1; j <= n; j++) {
                    if (in_group[i] && in_group[j]) {
                        current_coordination += coordination[i][j];
                    }
                }
            }
            
            for (int step = 0; step < local_search_steps; step++) {
                int student = rand() % n + 1;
                
                ll change = 0;
                for (int i = 1; i <= n; i++) {
                    if (i != student && in_group[i]) {
                        change += coordination[student][i];
                    }
                }
                
                bool old_state = in_group[student];
                if (old_state) {
                    in_group[student] = false;
                    change = -change;
                } else {
                    in_group[student] = true;
                }
                
                ll new_coordination = current_coordination + change;
                if (new_coordination > current_coordination) {
                    current_coordination = new_coordination;
                } else {
                    in_group[student] = old_state;
                }
            }
            
            if (current_coordination > best_coordination) {
                best_coordination = current_coordination;
                best_group = in_group;
            }
        }
    }
    
    vector<int> group;
    for (int i = 1; i <= n; i++) {
        if (best_group[i]) {
            group.push_back(i);
        }
    }
    
    cout << group.size() << ln;
    for (int student : group) {
        cout << student << " ";
    }
    cout << ln;

    time();
    return 0;
}