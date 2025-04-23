// Author: huythedev (https://huythedev.com)
// Problem Link: https://codeforces.com/contest/2074/problem/F

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

vector<ll> decomp(int leftBound, int rightBound) {
    vector<ll> segmentCountForExponents(32, 0);
    int currentPosition = leftBound;
    
    while (currentPosition < rightBound) {
        int candidateSegmentLength = 1;
        
        while ((candidateSegmentLength << 1) <= (rightBound - currentPosition) &&
               (currentPosition % (candidateSegmentLength << 1) == 0)) {
            candidateSegmentLength <<= 1;
        }
        
        int exponentForCurrentSegment = __builtin_ctz(candidateSegmentLength);
        segmentCountForExponents[exponentForCurrentSegment]++;
        
        currentPosition += candidateSegmentLength;
    }
    
    return segmentCountForExponents;
}

signed main() {
    fastio();
    docfile();
    
    int t;
    cin >> t;
    
    while (t--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        
        vector<ll> vec1 = decomp(l1, r1), vec2 = decomp(l2, r2);
        
        ll res = 0;
        
        for (int i = 0; i < 32; i++) {
            if (vec1[i] == 0) continue;
            
            for (int j = 0; j < 32; j++) {
                if (vec2[j] == 0) continue;
                int tmp = abs(i - j);
                ll tmp2 = 1LL << tmp;
                res += vec1[i] * vec2[j] * tmp2;
            }
        }
        
        cout << res << ln;
    }
    
    time();
    return 0;
}