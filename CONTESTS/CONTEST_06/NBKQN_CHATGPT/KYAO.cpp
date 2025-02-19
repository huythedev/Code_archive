#include <bits/stdc++.h>
using namespace std;

ifstream fin("KYAO.INP");
ofstream fout("KYAO.OUT");

const int MOD = 1e9 + 7;

struct Box {
    int a, b;
    bool operator<(const Box &other) const {
        return a < other.a || (a == other.a && b < other.b);
    }
};

int main() {
    int N;
    fin >> N;
    vector<Box> boxes(N);

    for (int i = 0; i < N; i++) {
        fin >> boxes[i].a >> boxes[i].b;
    }

    sort(boxes.begin(), boxes.end());

    map<int, pair<int, int>> dp;
    dp[0] = {0, 1};

    for (auto [a, b] : boxes) {
        auto it = prev(dp.upper_bound(a));
        int waste = it->second.first + (b - it->first);
        int count = it->second.second;

        if (dp.count(b) == 0 || dp[b].first > waste) {
            dp[b] = {waste, count};
        } else if (dp[b].first == waste) {
            dp[b].second = (dp[b].second + count) % MOD;
        }
    }

    auto best = min_element(dp.begin(), dp.end(), [](auto &x, auto &y) {
        return x.second.first < y.second.first;
    });

    fout << best->second.first << " " << best->second.second << "\n";
    return 0;
}
