#include <bits/stdc++.h>
using namespace std;

#define NAME "olp6arraypicker"
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

// Returns max possible score with optimal play
int solve(vector<int>& arr, int pos, vector<bool>& taken, map<int, int>& firstPick, 
          map<int, int>& colorCount, bool whiteTurn, int a, int b) {
    if (pos >= arr.size()) {
        int score = 0;
        // Score for picking color first
        for (auto& p : firstPick) {
            if (p.second == 1) score += a;
        }
        // Score for having all pieces of a color
        for (auto& p : colorCount) {
            if (p.second > 0) score += b;
        }
        return score;
    }

    if (taken[pos]) {
        return solve(arr, pos + 1, taken, firstPick, colorCount, whiteTurn, a, b);
    }

    int color = arr[pos];
    taken[pos] = true;

    // White's turn - maximize score
    if (whiteTurn) {
        if (firstPick[color] == 0) {
            firstPick[color] = 1;
        }
        colorCount[color]++;
        int score = solve(arr, pos + 1, taken, firstPick, colorCount, false, a, b);
        colorCount[color]--;
        if (firstPick[color] == 1) {
            firstPick[color] = 0;
        }
        taken[pos] = false;
        return score;
    }
    // Black's turn - minimize score
    else {
        if (firstPick[color] == 0) {
            firstPick[color] = 2;
        }
        int score = solve(arr, pos + 1, taken, firstPick, colorCount, true, a, b);
        if (firstPick[color] == 2) {
            firstPick[color] = 0;
        }
        taken[pos] = false;
        return score;
    }
}

int main() {
    fastio();
    docfile();

    int n, a, b;
    cin >> n >> a >> b;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<bool> taken(n, false);
    map<int, int> firstPick;  // 0: not picked, 1: white picked first, 2: black picked first
    map<int, int> colorCount; // Count of colors picked by white

    int result = solve(arr, 0, taken, firstPick, colorCount, true, a, b);
    cout << result << ln;

    time();
    return 0;
}