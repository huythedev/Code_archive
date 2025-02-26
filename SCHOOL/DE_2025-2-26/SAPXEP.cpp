// Author: Perry (https://perrythedev.com)
// Problem Link: 
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "SAPXEP"
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

const int maxn = 1e5 + 5;
int n;
vector<int> a(maxn);

void subtask1() {
    vector<pair<int, int>> operations;
    
    for(int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for(int j = i + 1; j < n; j++) {
            if(a[j] < a[min_idx]) {
                min_idx = j;
            }
        }
        
        if(min_idx != i) {
            operations.push_back({i + 1, min_idx + 1});  
            reverse(a.begin() + i, a.begin() + min_idx + 1);
        }
    }
    
    cout << operations.size() << ln;
    for(auto op : operations) {
        cout << op.first << " " << op.second << ln;
    }
}

void subtask2() {
    vector<int> b = a;
    sort(b.begin(), b.end());
    
    queue<int> pos0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) pos0.push(i + 1); // 1-based
    }
    
    vector<pair<int, int>> ops;
    int p = 1;
    while (!pos0.empty()) {
        int q = pos0.front();
        pos0.pop();
        if (q > p) {
            ops.push_back({p, q});
        }
        p++;
    }
    
    cout << ops.size() << "\n";
    for (auto [i, j] : ops) {
        cout << i << " " << j << "\n";
    }
}

int main() {
    fastio();
    docfile();

    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    if (n <= 1e3) {
        subtask1();
    }
    else {
        subtask2();
    }

    time();
    return 0;
}