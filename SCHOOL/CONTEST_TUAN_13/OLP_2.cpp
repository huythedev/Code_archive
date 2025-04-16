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

struct TeamState {
    ll total_laps;
    ll time_in_current_lap;
    ll current_lap_time; 

    bool is_better_than(const TeamState& other) const {
        if (total_laps != other.total_laps) {
            return total_laps > other.total_laps;
        }
        unsigned __int128 lhs = (unsigned __int128)time_in_current_lap * other.current_lap_time;
        unsigned __int128 rhs = (unsigned __int128)other.time_in_current_lap * current_lap_time;
        return lhs > rhs;
    }
};

TeamState calculate_state(ll t, int n, const vector<ll>& team_laps, ll cycle_t) {
    if (t == 0) {
         return {0, 0, (n > 0 ? team_laps[0] : 1)};
    }

    if (cycle_t == 0) {
        return {0, 0, 1}; 
    }

    ll full_cycles = t / cycle_t;
    ll laps_from_cycles = full_cycles * n;
    ll remaining_time = t % cycle_t;

    if (remaining_time == 0) {
        return {laps_from_cycles, 0, team_laps[0]};
    }

    ll laps_in_remainder = 0;
    ll time_into_lap = 0;
    ll current_runner_lap_time = team_laps[0]; 

    for (int j = 0; j < n; ++j) {
        if (remaining_time <= team_laps[j]) {
            time_into_lap = remaining_time;
            current_runner_lap_time = team_laps[j];
            break; 
        }
        remaining_time -= team_laps[j];
        laps_in_remainder++;
    }

    return {laps_from_cycles + laps_in_remainder, time_into_lap, current_runner_lap_time};
}

signed main() {
    fastio();
    docfile();

    int m, n, q; cin >> m >> n >> q; 

    vector<vector<ll>> a(m, vector<ll>(n));
    vector<ll> cycle_time(m, 0); 

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            cycle_time[i] += a[i][j];
        }
        if (cycle_time[i] == 0 && n > 0) {
        }
    }

    while (q--) {
        ll t; cin >> t;

        if (m == 0) continue; 

        int best_team_index = 0;
        TeamState best_state = calculate_state(t, n, a[0], cycle_time[0]);

        for (int i = 1; i < m; ++i) {
            TeamState current_state = calculate_state(t, n, a[i], cycle_time[i]);
            if (current_state.is_better_than(best_state)) {
                best_state = current_state;
                best_team_index = i;
            }
        }
        cout << best_team_index + 1 << ln;
    }

    time();
    return 0;
}