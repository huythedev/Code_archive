// Author: huythedev (https://huythedev.com)
// Problem Link: https://codeforces.com/contest/2078/problem/C

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

void solve() {
    int n;
    cin >> n;
    
    vector<ll> b(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> b[i];
    }
    
    // Sort the array to make it easier to work with
    sort(b.begin(), b.end());
    
    // For each potential missing value, try to construct a valid sequence
    for (int missing_pos = 0; missing_pos <= 2 * n; missing_pos++) {
        // Try different values for the missing element
        for (int sign = -1; sign <= 1; sign += 2) {
            // Calculate the value for the missing element
            ll sum = 0;
            for (int i = 0; i < 2 * n; i++) {
                if (i % 2 == 0) {
                    sum += b[i];
                } else {
                    sum -= b[i];
                }
            }
            
            // If the missing position has an effect on the sum
            ll x;
            if (missing_pos % 2 == 0) {
                // Missing element was at an even position (would be added)
                x = sign * sum;
            } else {
                // Missing element was at an odd position (would be subtracted)
                x = -sign * sum;
            }
            
            // Check if x is valid (not in b and positive)
            if (x > 0 && !binary_search(b.begin(), b.end(), x)) {
                // Construct the sequence a
                vector<ll> a;
                a.insert(a.end(), b.begin(), b.end());
                a.push_back(x);
                sort(a.begin(), a.end());
                
                // Now reorder a to satisfy the alternating sum property
                vector<ll> result(2 * n + 1);
                
                // Start with a[0] = a[1] - a[2] + a[3] - ... + a[2n] - a[2n+1]
                // Solve for a[0]
                if (sign == 1) {
                    // Place values in alternating positions
                    set<int> used;
                    int next_pos = 1;
                    
                    // First place the missing value at position 0
                    result[0] = x;
                    used.insert(x);
                    
                    // Then place the rest with alternating signs
                    for (ll val : a) {
                        if (val != x) {
                            result[next_pos] = val;
                            used.insert(val);
                            next_pos++;
                        }
                    }
                } else {
                    // Place the missing value at position 2n
                    result[2 * n] = x;
                    
                    // Place the rest of the values
                    int next_pos = 0;
                    for (ll val : a) {
                        if (val != x) {
                            if (next_pos == 2 * n) next_pos = 0;
                            result[next_pos] = val;
                            next_pos++;
                        }
                    }
                }
                
                // Verify the alternating sum property
                ll alternating_sum = result[0];
                for (int i = 1; i <= 2 * n; i++) {
                    if (i % 2 == 1) {
                        alternating_sum -= result[i];
                    } else {
                        alternating_sum += result[i];
                    }
                }
                
                if (alternating_sum == 0) {
                    // Output the result
                    for (int i = 0; i <= 2 * n; i++) {
                        cout << result[i] << " ";
                    }
                    cout << endl;
                    return;
                }
            }
        }
    }
    
    // Try a completely different approach by directly constructing a valid sequence
    ll max_val = b[2 * n - 1] + 1;
    vector<ll> a(2 * n + 1);
    
    // Put b values in first 2n positions
    for (int i = 0; i < 2 * n; i++) {
        a[i] = b[i];
    }
    
    // Set a[2n] to a value that ensures a[0] = a[1] - a[2] + ... + a[2n]
    ll alternating_sum = 0;
    for (int i = 1; i < 2 * n; i++) {
        if (i % 2 == 1) {
            alternating_sum += a[i];
        } else {
            alternating_sum -= a[i];
        }
    }
    
    a[2 * n] = alternating_sum - a[0];
    
    // If a[2n] is already in the sequence or not positive, use a different value
    if (a[2 * n] <= 0 || binary_search(b.begin(), b.end(), a[2 * n])) {
        // Reconstruct the sequence with different approach
        a[0] = max_val; // New first element
        
        // Recalculate alternating sum for positions 1 through 2n-1
        alternating_sum = 0;
        for (int i = 1; i < 2 * n; i++) {
            if (i % 2 == 1) {
                alternating_sum += a[i];
            } else {
                alternating_sum -= a[i];
            }
        }
        
        // Solve for a[2n]
        a[2 * n] = a[0] - alternating_sum;
        
        // If still not valid, increment a[0] until we find a valid solution
        while (a[2 * n] <= 0 || binary_search(b.begin(), b.end(), a[2 * n])) {
            a[0]++;
            a[2 * n] = a[0] - alternating_sum;
        }
    }
    
    // Output the result
    for (int i = 0; i <= 2 * n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

signed main() {
    fastio();
    docfile();
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}