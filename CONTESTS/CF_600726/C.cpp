// Author: huythedev
// Problem Link: https://codeforces.com/group/G0iFI97YZN/contest/600726/problem/C

#include <bits/stdc++.h>
using namespace std;
 
#define NAME "C"
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
 
void print_result(int i, int res) {
    cout << "Case #" << i << ": " << res << ln;
}

void solve(int t, int n, int p, vector<pair<int, int>>& scores) {
    // Collect unique scores that could be the max score
    set<int> unique_scores;
    for (auto& score : scores) {
        unique_scores.insert(score.first);
        unique_scores.insert(score.second);
    }
    
    int max_passing = 0;
    
    // For each possible max score, count passing students
    for (auto max_score : unique_scores) {
        int threshold = (max_score * (ll)p + 99) / 100; // Calculate minimum passing score
        
        // Check if this max score is achievable by any student
        bool achievable = false;
        int passing_count = 0;
        
        // One pass through all students
        for (auto& score : scores) {
            // Check if this student can achieve the max score
            if (score.first == max_score || score.second == max_score) {
                achievable = true;
            }
            
            // Get the best score this student can achieve (considering the max limit)
            int best_score = 0;
            if (score.first <= max_score) best_score = max(best_score, score.first);
            if (score.second <= max_score) best_score = max(best_score, score.second);
            
            // Check if student passes
            if (best_score >= threshold) {
                passing_count++;
            }
        }
        
        // Only update max if this max score is achievable
        if (achievable) {
            max_passing = max(max_passing, passing_count);
        }
    }
    
    print_result(t, max_passing);
}

signed main() {
    fastio();
    docfile();
 
    int testcases; cin >> testcases;
    for (int t = 1; t <= testcases; ++t) {
        int n, p; cin >> n >> p;
        vector<pair<int, int>> scores(n);
        for (int i = 0; i < n; ++i) cin >> scores[i].first >> scores[i].second;
        solve(t, n, p, scores);
    }

    time();
    return 0;
}