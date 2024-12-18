// Author: Perry (https://perrythedev.com)
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "CPERMPRI"
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
    cerr << ln << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << ln;
}

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int countPrimePairs(int N) {
    vector<int> perm(N);
    iota(perm.begin(), perm.end(), 1); // Fill with 1, 2, ..., N

    vector<vector<int>> permutations;
    do {
        permutations.push_back(perm);
    } while (next_permutation(perm.begin(), perm.end()));

    int count = 0;
    int totalPerms = permutations.size();
    for (int i = 0; i < totalPerms; ++i) {
        for (int j = i + 1; j < totalPerms; ++j) {
            bool isPrimePair = true;
            for (int k = 0; k < N; ++k) {
                if (!isPrime(permutations[i][k] + permutations[j][k])) {
                    isPrimePair = false;
                    break;
                }
            }
            if (isPrimePair) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    fastio();
    docfile();

    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        cout << countPrimePairs(N) << ln;
    }

    time();
    return 0;
}