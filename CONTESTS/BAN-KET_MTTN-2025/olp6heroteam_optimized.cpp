// Author: huythedev (optimized version)
// Problem Link: https://oj.vku.udn.vn/problem/olp6heroteam
#include <bits/stdc++.h>
using namespace std;

#define NAME "olp6heroteam"
#define ln "\n"

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
    cerr << ln << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << ln;
}

const ll MOD = 998244353;

int func(ll x) {
    return (x > 0) ? 1 : ((x < 0) ? -1 : 0);
}

struct Hero {
    ll power;
    ll skill;
};

int main() {
    fastio();
    docfile();

    int n; cin >> n;
    
    vector<Hero> heroes(n);
    for (int i = 0; i < n; i++) {
        cin >> heroes[i].power >> heroes[i].skill;
    }
    
    sort(heroes.begin(), heroes.end(), [](const Hero& a, const Hero& b) {
        return a.power < b.power;
    });
    
    ll res = 0;
    
    vector<vector<ll>> powers(n, vector<ll>(4));
    for (int i = 0; i < n; i++) {
        powers[i][1] = heroes[i].power % MOD;
        for (int p = 2; p <= 3; p++) {
            powers[i][p] = (powers[i][p-1] * powers[i][1]) % MOD;
        }
    }
    
    for (int j = 1; j < n-1; j++) {
        map<pair<int, int>, vector<pair<ll, int>>> pattern_to_heroes;
        
        for (int i = 0; i < j; i++) {
            int s1 = func(heroes[i].skill - heroes[j].skill);
            for (int s2_val = -1; s2_val <= 1; s2_val++) {
                pattern_to_heroes[{s1, s2_val}].push_back({heroes[i].power, i});
            }
        }
        
        for (auto& [pattern, hero_list] : pattern_to_heroes) {
            sort(hero_list.begin(), hero_list.end());
        }
        
        for (int k = j+1; k < n; k++) {
            ll threshold = heroes[k].power; 
            ll yj = heroes[j].skill, zk = heroes[k].skill;
            
            for (auto& [pattern, hero_list] : pattern_to_heroes) {
                int s1 = pattern.first;
                int expected_s2 = pattern.second;
                
                for (auto& [power_i, idx_i] : hero_list) {
                    if (threshold >= power_i + heroes[j].power)
                        continue;
                    
                    ll xi = heroes[idx_i].skill;
                    int actual_s2 = func(xi*yj - xi*zk + zk*zk - yj*zk);
                    
                    if (actual_s2 != expected_s2)
                        continue;
                    
                    int D = 1 + abs(s1) + abs(actual_s2);
                    if (D > 3) continue;
                    
                    ll total_power = ((power_i + heroes[j].power) % MOD + threshold) % MOD;
                    
                    if (D == 1) {
                        res = (res + total_power) % MOD;
                    } 
                    else if (D == 2) {
                        res = (res + (total_power * total_power) % MOD) % MOD;
                    } 
                    else if (D == 3) {
                        res = (res + (((total_power * total_power) % MOD) * total_power) % MOD) % MOD;
                    }
                }
            }
        }
    }
    
    cout << res << ln;

    time();
    return 0;
}
