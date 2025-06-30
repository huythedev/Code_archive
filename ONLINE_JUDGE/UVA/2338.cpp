// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "2338"
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

const int MAXN = 2e6 + 1;
vector<int> prime_factors(MAXN, 0);
vector<int> nums;

bool comp(int &a, int &b) {
    if (prime_factors[a] == prime_factors[b])
        return a < b;
    return prime_factors[a] < prime_factors[b];
}

void precompute() {
    for (int i = 2; i < MAXN; ++i) {
        if (prime_factors[i] == 0) {
            for (int j = i; j < MAXN; j += i) {
                int x = j;
                int count = 0;
                while (x % i == 0) {
                    count++;
                    x /= i;
                }
                prime_factors[j] += count;
            }
        }
    }

    prime_factors[1] = 0;

    nums.reserve(MAXN - 1);
    for (int i = 1; i < MAXN; ++i) {
        nums.push_back(i);
    }

    sort(nums.begin(), nums.end(), comp);
}

void solve() {
    int n, case_num = 1;
    while (cin >> n && n != 0) {
        cout << "Case " << case_num << ": " << nums[n - 1] << ln;
        ++case_num;
    }
}

signed main() {
    docfile();
    fastio();
    precompute();

    // for (int i = 0; i < 50; ++i) cout << nums[i] << ' ';
    // cout << ln;

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}
