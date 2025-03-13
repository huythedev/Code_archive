// Author: Perry (https://perrythedev.com)
// Problem Link: 
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "DEMCHAN"
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

const int maxn = 1e6 + 5, maxq = 1e5 + 5;

int N, Q;
vector<int> even_numbers(maxn), odd_numbers(maxn);
ll sus = 0;
bool tmp = false;

signed main() {
    fastio();
    docfile();

    cin >> N >> Q;
    int idx_even = 0, idx_odd = 0, even_cnt = 0, odd_cnt = 0;
    for (int i = 0; i < N; ++i) {
        int x; cin >> x;
        if (x % 2 == 0) {
            even_numbers[idx_even++] = x;
            even_cnt++;
        }
        else {
            odd_numbers[idx_odd++] = x;
            odd_cnt++;
        }
    }

    even_numbers.resize(even_cnt);
    odd_numbers.resize(odd_cnt);
    
    sort(even_numbers.begin(), even_numbers.end());
    sort(odd_numbers.begin(), odd_numbers.end());

    while (Q--) {
        int type; cin >> type;

        if (type == 1) {
            int V; cin >> V;
            V -= sus; 
            
            vector<int>& vec = tmp ? odd_numbers : even_numbers;
            int res = 0;
            res = upper_bound(vec.begin(), vec.end(), V) - vec.begin();
            
            cout << res << ln;
        }
        else {
            int W; cin >> W;
            sus += (ll)W;
            
            if (W % 2 != 0) {
                tmp = !tmp;
            }
        }
    }

    time();
    return 0;
}