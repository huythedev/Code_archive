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
    vector<pair<int, int>> operations;
    for (int i = 0; i < n; i++) {
        // Find the minimum element's index from i to n-1
        int min_val = a[i];
        int min_idx = i;
        for (int k = i + 1; k < n; k++) {
            if (a[k] < min_val) {
                min_val = a[k];
                min_idx = k;
            }
        }
        // If the minimum is not at position i, perform a reversal
        if (min_idx != i) {
            reverse(a.begin() + i, a.begin() + min_idx + 1);
            operations.push_back({i + 1, min_idx + 1}); // Store 1-based indices
        }
    }
    
    // Output the number of operations and the operations themselves
    cout << operations.size() << "\n";
    for (auto [start, end] : operations) {
        cout << start << " " << end << "\n";
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
    
    // if (n <= 1e3)
    //     subtask1();
    // else
        subtask2();

    time();
    return 0;
}