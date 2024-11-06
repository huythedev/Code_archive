#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1234567891;

struct Constrall {
    ll type, l, r;
};

vector<Constrall> cs;
ll n, m;

struct State {
    ll pos;
    unsigned long long mask;

    bool operator==(const State& other) const {
        return pos == other.pos && mask == other.mask;
    }
};

struct StateHash {
    size_t operator()(const State& state) const {
        return hash<ll>()(state.pos) ^ (hash<unsigned long long>()(state.mask) << 1);
    }
};

unordered_map<State, ll, StateHash> memo;

ll power(ll base, ll exp) {
    ll result = 1;
    base %= MOD;
    while(exp > 0) {
        if(exp & 1) result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

inline bool check_constrall(ll pos, ll val, unsigned long long& satisfied_mask) {
    unsigned long long old_mask = satisfied_mask;

    for(ll i = 0; i < m; i++) {
        if (satisfied_mask & (1u << i)) continue;  // Already satisfied, skip

        const auto& c = cs[i];

        // Check if the current position is within the constraint range
        if (pos >= c.l - 1 && pos <= c.r - 1) {
            // Ensure the value satisfies the constraint
            if ((c.type == 1 && val == 0) || (c.type == 2 && val == 1)) {
                satisfied_mask |= (1u << i);
            }
        }

        // If at the upper bound of the range and the constraint isn't satisfied, revert
        if (pos == c.r - 1 && !(satisfied_mask & (1u << i))) {
            satisfied_mask = old_mask;  // Revert the mask to the state before this check
            return false;
        }
    }
    return true;
}


ll solve_dp(ll pos, unsigned long long satisfied_mask) {
    if(pos == n) {
        return (satisfied_mask == (1u << m) - 1) ? 1 : 0;
    }

    State state = {pos, satisfied_mask};
    auto it = memo.find(state);
    if(it != memo.end()) return it->second;

    ll result = 0;
    for(ll val = 0; val <= 1; val++) {
        unsigned long long new_mask = satisfied_mask;
        if(check_constrall(pos, val, new_mask)) {
            result = (result + solve_dp(pos + 1, new_mask)) % MOD;
        }
    }
    return memo[state] = result;
}

ll solve_small() {
    ll maxval = 1LL << n;
    ll result = 0;

    for(ll mask = 0; mask < maxval; mask++) {
        bool valid = true;
        for(const auto &c : cs) {
            bool found = false;
            for(ll pos = c.l-1; pos < c.r; pos++) {
                if(c.type == 1 && !(mask & (1LL << pos))) found = true;
                if(c.type == 2 && (mask & (1LL << pos))) found = true;
            }
            if(!found) {
                valid = false;
                break;
            }
        }
        if(valid) result = (result + 1) % MOD;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    if(m >= 32) {
        cout << "0\n";
        return 0;
    }

    cs.reserve(m);
    for(ll i = 0; i < m; i++) {
        ll type, l, r;
        cin >> type >> l >> r;
        cs.push_back({type, l, r});
    }

    if(m == 0) {
        cout << power(2, n) << "\n";
        return 0;
    }

    if(n <= 18) {
        cout << solve_small() << "\n";
        return 0;
    }

    cout << solve_dp(0, 0) << "\n";
    return 0;
}
