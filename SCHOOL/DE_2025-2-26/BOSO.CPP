// Author: huythedev (https://huythedev.com)
// Problem Link: 
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "BOSO"
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

const int M = 100000;

vector<int> get_divisors(int x) {
    vector<int> divs;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            divs.push_back(i);
            if (i != x / i) divs.push_back(x / i);
        }
    }
    return divs;
}

int main() {
    fastio();
    docfile();

    int N;
    cin >> N;
    vector<int> a(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    
    vector<vector<int>> indices(M + 1);
    for (int i = 1; i <= N; i++) {
        vector<int> divs = get_divisors(a[i]);
        for (int d : divs) {
            indices[d].push_back(i);
        }
    }
    
    vector<int> left_max(N + 1, 0);
    for (int j = 2; j <= N; j++) {
        vector<int> divs = get_divisors(a[j]);
        for (int d : divs) {
            if (!indices[d].empty() && indices[d][0] < j) {
                left_max[j] = max(left_max[j], d);
            }
        }
    }
    
    vector<int> right_max(N + 1, 0);
    for (int k = 1; k <= N - 1; k++) {
        vector<int> divs = get_divisors(a[k]);
        for (int d : divs) {
            if (!indices[d].empty() && indices[d].back() > k) {
                right_max[k] = max(right_max[k], d);
            }
        }
    }
    
    vector<int> prefix_max(N + 1, 0);
    prefix_max[2] = left_max[2];
    for (int m = 3; m <= N - 1; m++) {
        prefix_max[m] = max(prefix_max[m - 1], left_max[m]);
    }
    
    int ans = 0;
    for (int k = 3; k <= N - 1; k++) {
        if (k - 1 >= 2) {
            ans = max(ans, prefix_max[k - 1] + right_max[k]);
        }
    }
    
    cout << ans << endl;
    
    time();
    return 0;
}