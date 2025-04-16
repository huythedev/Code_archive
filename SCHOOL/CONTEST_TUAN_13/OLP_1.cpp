// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "OLP"
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

const int MAXN = 1e3 + 5;

signed main() {
    fastio();
    docfile();

    int teams, students_per_team, queries; cin >> teams >> students_per_team >> queries;
    vector<vector<int>> a(MAXN, vector<int> (MAXN));
    for (int i = 0; i < teams; ++i) {
        for (int j = 0; j < students_per_team; ++j) {
            cin >> a[i][j];
        }
    }

    // Input reading: O(teams * students_per_team)
    
    // For each query: O(queries)
    int teams, students_per_team, queries;
    cin >> teams >> students_per_team >> queries;

    // Input times for each student in each team
    vector<vector<ll>> a(teams, vector<ll>(students_per_team));
    for (int i = 0; i < teams; ++i) {
        for (int j = 0; j < students_per_team; ++j) {  // Corrected to students_per_team
            cin >> a[i][j];
        }
    }

    // Compute prefix sums for each team
    vector<vector<ll>> p(teams, vector<ll>(students_per_team + 1, 0));
    for (int i = 0; i < teams; ++i) {
        for (int j = 1; j <= students_per_team; ++j) {
            p[i][j] = p[i][j - 1] + a[i][j - 1];
        }
    }

    // Process each query
    while (queries--) {
        ll t;
        cin >> t;

        ll best_k = -1;       // Best number of full laps
        ll best_num = -1;     // Best numerator for fraction
        ll best_den = -1;     // Best denominator for fraction
        int best_index = -1;  // Best team index

        for (int i = 0; i < teams; ++i) {
            // Binary search to find largest k where total time <= t
            ll left = 0, right = 1e18;
            while (left < right) {
                ll mid = left + (right - left + 1) / 2;
                ll q = mid / students_per_team;
                ll r = mid % students_per_team;
                __int128 sum_mid = (__int128)q * p[i][students_per_team] + p[i][r];
                if (sum_mid <= t) {
                    left = mid;
                } else {
                    right = mid - 1;
                }
            }
            ll k = left;
            ll q = k / students_per_team;
            ll r = k % students_per_team;
            __int128 sum_k = (__int128)q * p[i][students_per_team] + p[i][r];
            ll sum_up_to_k = (ll)sum_k;  // Safe cast since sum_k <= t <= 10^12
            ll numerator = t - sum_up_to_k;
            ll denominator = a[i][k % students_per_team];

            // Update best team if this team is strictly ahead
            if (i == 0 || k > best_k || 
                (k == best_k && (ll)numerator * best_den > (ll)best_num * denominator)) {
                best_k = k;
                best_num = numerator;
                best_den = denominator;
                best_index = i;
            }
        }
        // Output 1-based index
        cout << best_index + 1 << ln;
    }

    // The overall time complexity is O(queries * teams * students_per_team)
    // Breaking it down:
    // - Input reading: O(teams * students_per_team)
    // - For each query: O(queries)
    //   - For each team: O(teams)
    //     - Calculate cycle time: O(students_per_team)
    //     - Calculate additional laps: O(students_per_team) in worst case
    //     - Other operations inside team loop: O(1)
    //
    // With constraints of m, n, q ≤ 1000, worst case is O(10^9) operations
    // This is on the edge of acceptable for competitive programming time limits

    time();
    return 0;
}