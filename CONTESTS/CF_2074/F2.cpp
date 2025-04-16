// Author: huythedev (https://huythedev.com)
// Problem Link: https://codeforces.com/contest/2074/problem/F
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "F"
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

inline bool isQuadTreeNode(ll l1, ll r1, ll l2, ll r2) {
    ll width = r1 - l1;
    ll height = r2 - l2;
    
    if (width != height) return false;
    if ((width & (width - 1)) != 0) return false; // Check if power of 2
    
    return (l1 & (width - 1)) == 0 && (l2 & (width - 1)) == 0;
}

// Scale down the coordinates by GCD
tuple<ll, ll, ll, ll> scaleDown(ll l1, ll r1, ll l2, ll r2) {
    // Try to find common factors between coordinates
    ll gcd_x = __gcd(l1, r1);
    ll gcd_y = __gcd(l2, r2);
    
    // Further reduce by common factors
    ll g = __gcd(gcd_x, gcd_y);
    
    if (g > 1) {
        return {l1/g, r1/g, l2/g, r2/g};
    }
    return {l1, r1, l2, r2};
}

int fastSolve(ll l1, ll r1, ll l2, ll r2) {
    // Use a compact key for memoization with integers
    struct Key {
        int l1, r1, l2, r2;
        
        bool operator==(const Key& other) const {
            return l1 == other.l1 && r1 == other.r1 && 
                   l2 == other.l2 && r2 == other.r2;
        }
    };
    
    struct KeyHash {
        size_t operator()(const Key& k) const {
            // Better distribution hash function
            return ((size_t)k.l1 * 37 + k.r1) * 37 + k.l2 * 37 + k.r2;
        }
    };
    
    unordered_map<Key, int, KeyHash> memo;
    memo.reserve(100000); // Pre-allocate space
    
    // Find smallest power of 2 >= x (fixed infinite loop)
    auto ceilPow2 = [](ll x) -> ll {
        ll p = 1;
        while (p < x && p < (1LL << 30)) p <<= 1; // Added upper bound check
        return p;
    };
    
    // Find largest power of 2 <= x (fixed infinite loop)
    auto floorPow2 = [](ll x) -> ll {
        if (x <= 0) return 1; // Safety check
        ll p = 1;
        while ((p << 1) <= x && p < (1LL << 30)) p <<= 1; // Added upper bound check
        return p;
    };
    
    // Get promising split points
    auto getSplits = [&](ll start, ll end) -> vector<ll> {
        vector<ll> splits;
        
        // Safety check
        if (end <= start) return splits;
        
        // Add midpoint
        splits.push_back((start + end) / 2);
        
        // Add power-of-2 aligned points
        for (ll p = floorPow2(end - start); p > 0; p >>= 1) {
            // Align from left
            ll pos = ((start + p - 1) / p) * p;
            if (pos > start && pos < end) 
                splits.push_back(pos);
                
            // Align from right
            pos = (end / p) * p;
            if (pos > start && pos < end)
                splits.push_back(pos);
        }
        
        sort(splits.begin(), splits.end());
        splits.erase(unique(splits.begin(), splits.end()), splits.end());
        return splits;
    };
    
    function<int(ll,ll,ll,ll)> dp = [&](ll l1, ll r1, ll l2, ll r2) -> int {
        // Safety check for invalid inputs
        if (r1 <= l1 || r2 <= l2) return 0;
        
        // Base case: valid quadtree node
        if (isQuadTreeNode(l1, r1, l2, r2)) return 1;
        
        // Check memo - ensure coordinates fit in int
        if (l1 > INT_MAX || r1 > INT_MAX || l2 > INT_MAX || r2 > INT_MAX) {
            // If coordinates are too large, scale them down
            auto [nl1, nr1, nl2, nr2] = scaleDown(l1, r1, l2, r2);
            return dp(nl1, nr1, nl2, nr2);
        }
        
        Key key = {(int)l1, (int)r1, (int)l2, (int)r2};
        auto it = memo.find(key);
        if (it != memo.end()) return it->second;
        
        int result = INT_MAX;
        
        // Try horizontal splits
        vector<ll> xSplits = getSplits(l1, r1);
        for (ll mid : xSplits) {
            if (mid > l1 && mid < r1) { // Extra safety check
                int cost = dp(l1, mid, l2, r2) + dp(mid, r1, l2, r2);
                result = min(result, cost);
                if (result <= 2) break; // Early exit
            }
        }
        
        // Try vertical splits if needed
        if (result > 2) {
            vector<ll> ySplits = getSplits(l2, r2);
            for (ll mid : ySplits) {
                if (mid > l2 && mid < r2) { // Extra safety check
                    int cost = dp(l1, r1, l2, mid) + dp(l1, r1, mid, r2);
                    result = min(result, cost);
                    if (result <= 2) break; // Early exit
                }
            }
        }
        
        return memo[key] = result;
    };
    
    return dp(l1, r1, l2, r2);
}

signed main() {
    fastio();
    docfile();

    int t;
    cin >> t;
    
    while (t--) {
        ll l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        
        // Scale down coordinates before solving
        tie(l1, r1, l2, r2) = scaleDown(l1, r1, l2, r2);
        
        // Compute answer
        cout << fastSolve(l1, r1, l2, r2) << ln;
    }

    time();
    return 0;
}