// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "ct3_rectnum"
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

void solve() {
    vector<string> nums(4);
    for (string &s : nums)
        cin >> s;
    
    int count = 0;
    int perm[4] = {0, 1, 2, 3};
    
    do {
        string top = nums[perm[0]];
        string right = nums[perm[1]];
        string bottom = nums[perm[2]];
        string left = nums[perm[3]];
        
        int lt = top.length();
        int lr = right.length();
        int lb = bottom.length();
        int ll = left.length();
        
        int maxW = min(lt - 1, lb - 1);
        int maxH = min(ll - 1, lr - 1);
        
        if (maxW < 1 || maxH < 1) 
            continue;
        
        bool found = false;
        for (int W = 1; W <= maxW && !found; W++) {
            for (int H = 1; H <= maxH && !found; H++) {
                for (int xt = W - lt + 1; xt <= 0 && !found; xt++) {
                    int itl = -xt, itr = W - xt;
                    if (itl < 0 || itl >= lt || itr < 0 || itr >= lt)
                        continue;
                    
                    for (int yl = H - ll + 1; yl <= 0 && !found; yl++) {
                        int iltl = -yl, ilbl = H - yl;
                        if (iltl < 0 || iltl >= ll || ilbl < 0 || ilbl >= ll)
                            continue;
                        
                        if (top[itl] != left[iltl]) 
                            continue;
                        
                        for (int yr = H - lr + 1; yr <= 0 && !found; yr++) {
                            int irtr = -yr, irbr = H - yr;
                            if (irtr < 0 || irtr >= lr || irbr < 0 || irbr >= lr) 
                                continue;
                            if (top[itr] != right[irtr]) 
                                continue;
                            
                            for (int xb = W - lb + 1; xb <= 0 && !found; xb++) {
                                int ibbl = -xb, ibbr = W - xb;
                                if (ibbl < 0 || ibbl >= lb || ibbr < 0 || ibbr >= lb) 
                                    continue;
                                
                                if (bottom[ibbl] == left[ilbl] && bottom[ibbr] == right[irbr]) {
                                    count++;
                                    found = true;
                                }
                            }
                        }
                    }
                }
            }
        }
    } while (next_permutation(perm, perm + 4));
    
    cout << count << ln;
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