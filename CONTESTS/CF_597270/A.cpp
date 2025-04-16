// Author: huythedev
// Problem Link: https://codeforces.com/group/VbkeP1fypp/contest/597270/problem/A
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

bool comp(pair<int, int> &a, pair <int, int> &b) {
    return a.second < b.second;
}

signed main() {
    fastio();
    docfile();

    int C, L; cin >> C >> L;
    
    vector<pair<int, int>> pigs(C); 
    for (int i = 0; i < C; i++) {
        cin >> pigs[i].first >> pigs[i].second;
    }
    
    vector<pair<int, int>> kcn(L);  
    for (int i = 0; i < L; i++) {
        cin >> kcn[i].first >> kcn[i].second;
    }
    
    sort(pigs.begin(), pigs.end(), comp);
    
    int res = 0;
    
    for (pair<int, int> pig : pigs) {
        int min_SPF = pig.first;
        int max_SPF = pig.second;
        
        int tmp = -1;
        
        for (int i = 0; i < L; i++) {
            int spf = kcn[i].first;
            int sec = kcn[i].second;
            
            if (sec > 0 && spf >= min_SPF && spf <= max_SPF) {
                if (tmp == -1 || spf < kcn[tmp].first) {
                    tmp = i;
                }
            }
        }
        
        if (tmp != -1) {
            kcn[tmp].second--;
            res++;
        }
    }
    
    cout << res << ln;

    time();
    return 0;
}