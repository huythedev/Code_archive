#include <bits/stdc++.h>
using namespace std;

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ (hash2 + 0x9e3779b9 + (hash1 << 6) + (hash1 >> 2));
    }
};

int main() {
    string s;
    cin >> s;
    int n = s.size();
    
    // Map to store frequency of (diff1, diff2) pairs
    map<pair<int, int>, int> freq;
    freq[{0, 0}] = 1; // Initial state before string starts
    
    int prefix_N = 0, prefix_A = 0, prefix_M = 0;
    long long answer = 0;
    
    // Iterate through the string
    for (char c : s) {
        // Update prefix counts
        if (c == 'N') prefix_N++;
        else if (c == 'A') prefix_A++;
        else if (c == 'M') prefix_M++;
        
        // Current differences
        pair<int, int> current = {prefix_N - prefix_A, prefix_N - prefix_M};
        
        // Add the number of previous occurrences of this pair
        if (freq.count(current)) {
            answer += freq[current];
        }
        
        // Increment the frequency of this pair
        freq[current]++;
    }
    
    cout << answer << endl;
    return 0;
}