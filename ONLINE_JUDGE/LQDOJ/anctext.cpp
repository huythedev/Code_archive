// Author: huythedev (https://huythedev.com)^
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
const ll MOD = 1234567891;

ll solve(const string& s, const vector<pair<int, string>>& constraints, const vector<pair<int, int>>& ranges) {
    vector<ll> results;
    for (auto& range : ranges) {
        int l = range.first - 1;
        int r = range.second - 1;
        string sub = s.substr(l, r - l + 1);
        
        unordered_map<string, int> freq;
        for (int i = 0; i < sub.size(); ++i) {
            for (auto& c : constraints) {
                string pattern = c.second;
                if (i + pattern.size() <= sub.size()) {
                    if (sub.substr(i, pattern.size()) == pattern) {
                        freq[pattern]++;
                    }
                }
            }
        }
        
        bool valid = true;
        for (auto& c : constraints) {
            if (freq[c.second] != c.first) {
                valid = false;
                break;
            }
        }
        
        if (valid) results.push_back(1);
        else results.push_back(0);
    }
    
    ll final_result = 1;
    for (auto& result : results) {
        final_result = (final_result * result) % MOD;
    }
    return final_result;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int m;
        cin >> m;

        vector<pair<int, string>> constraints(m);
        for (int i = 0; i < m; i++) {
            cin >> constraints[i].first >> constraints[i].second;
        }

        int q;
        cin >> q;

        vector<pair<int, int>> ranges(q);
        for (int i = 0; i < q; i++) {
            cin >> ranges[i].first >> ranges[i].second;
        }

        cout << solve(s, constraints, ranges) << endl;
    }
    
    return 0;
}
