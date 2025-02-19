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

int main() {
    fastio();
    docfile();

    int n, p1, p2;
    cin >> n >> p1 >> p2;
    
    vector<int> a(n);
    unordered_map<int, int> freq;
    
    for (int &x : a) {
        cin >> x;
        freq[x]++;
    }

    vector<int> colors;
    for (auto &[c, f] : freq) colors.push_back(c);
    
    sort(colors.begin(), colors.end(), [&](int x, int y) {
        return freq[x] > freq[y];
    });

    unordered_set<int> white, black;
    int max_score = 0;
    
    for (int c : colors) {
        if (white.count(c) || black.count(c)) continue;
        white.insert(c);
        max_score += p1;
        if (freq[c] == 1) {
            max_score += p2;
        } else {
            black.insert(c);
        }
    }

    cout << max_score << ln;
    return 0;
}
