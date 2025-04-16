// Author: huythedev (https://huythedev.com)
// Problem Link: https://codeforces.com/gym/592085/problem/C
// davul
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

bool check(const string& s, int k, const vector<int>& prefixA, const vector<int>& prefixB, const vector<int>& prefixC) {
    for (int i = 0; i <= s.size() - k; ++i) {
        int cntA = prefixA[i + k] - prefixA[i];
        int cntB = prefixB[i + k] - prefixB[i];
        int cntC = prefixC[i + k] - prefixC[i];
        if (cntA > k / 2 || cntB > k / 2 || cntC > k / 2) {
            return true;
        }
    }
    return false;
}

int main() {
    fastio();
    docfile();

    int n;
    string s;
    cin >> n >> s;
    
    vector<int> prefixA(n + 1, 0), prefixB(n + 1, 0), prefixC(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefixA[i] = prefixA[i - 1] + (s[i - 1] == 'a');
        prefixB[i] = prefixB[i - 1] + (s[i - 1] == 'b');
        prefixC[i] = prefixC[i - 1] + (s[i - 1] == 'c');
    }
    
    int l = 1, r = n, res = 0;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(s, mid, prefixA, prefixB, prefixC)) {
            res = mid;
            l = mid + 1;
        } 
        else {
            r = mid - 1;
        }
    }
    
    cout << res << ln;

    time();
    return 0;
}