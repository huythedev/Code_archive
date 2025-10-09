// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "ROOM"
#define ln "\n"
#define sz size()

typedef long long ll;
typedef long double ld;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void fileIO() {
    if (ifstream(NAME ".INP")) {
        freopen(NAME ".INP", "r", stdin);
        freopen(NAME ".OUT", "w", stdout);
    }
}

void time() {
    cerr << ln << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." 
         << ln;
}

struct Job {
    int start;
    int end;
    int profit;
};

bool comp(const Job& a, const Job& b) {
    return a.end < b.end;
}

int findjob(const vector<Job>& jobs, int idx) {
    int low = 0, high = idx - 1;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (jobs[mid].end <= jobs[idx].start) {
            result = mid;
            low = mid + 1;
        } 
        else {
            high = mid - 1;
        }
    }
    return result;
}

void solve() {
    int n;
    cin >> n;

    vector<Job> jobs(n);
    for (int i = 0; i < n; ++i) {
        cin >> jobs[i].start >> jobs[i].end >> jobs[i].profit;
    }

    sort(jobs.begin(), jobs.end(), comp);

    vector<ll> dp(n);

    dp[0] = jobs[0].profit;

    for (int i = 1; i < n; ++i) {
        ll profit = jobs[i].profit;
        int idx = findjob(jobs, i);
        
        if (idx != -1) {
            profit += dp[idx];
        }

        ll profit2 = dp[i - 1];
        
        dp[i] = max(profit, profit2);
    }

    cout << dp[n - 1] << ln;
}

signed main() {
    fastIO();
    fileIO();

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}