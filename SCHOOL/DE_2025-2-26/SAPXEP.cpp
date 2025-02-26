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

int main() {
    fastio();
    docfile();

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<pair<int, int>> operations;
    vector<pair<int, int>> pos(n); // stores {value, original_position}
    
    for(int i = 0; i < n; i++) {
        pos[i] = {a[i], i};
    }
    
    // Sort to determine target positions
    sort(pos.begin(), pos.end());
    
    vector<int> target_pos(n);
    for(int i = 0; i < n; i++) {
        target_pos[pos[i].second] = i;
    }
    
    // Use cycle following technique
    vector<bool> visited(n, false);
    
    for(int i = 0; i < n; i++) {
        if(visited[i] || target_pos[i] == i) continue;
        
        int cycle_start = i;
        int j = i;
        
        while(!visited[j]) {
            visited[j] = true;
            j = target_pos[j];
            
            if(j != cycle_start) {
                operations.push_back({min(cycle_start, j) + 1, max(cycle_start, j) + 1});
                
                // Simulate the reverse
                int left = min(cycle_start, j);
                int right = max(cycle_start, j);
                while(left < right) {
                    swap(a[left], a[right]);
                    swap(target_pos[left], target_pos[right]);
                    left++;
                    right--;
                }
            }
        }
    }
    
    cout << operations.size() << ln;
    for(auto op : operations) {
        cout << op.first << " " << op.second << ln;
    }

    time();
    return 0;
}