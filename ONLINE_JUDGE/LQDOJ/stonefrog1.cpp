#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if(ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    int N;
    cin >> N;

    vector<int> h(N);
    for(int i = 0; i < N; ++i)
        cin >> h[i];

    vector<int> dp(N, 0);
    for(int i = 1; i < N; ++i) {
        dp[i] = dp[i - 1] + abs(h[i] - h[i - 1]);
        if(i > 1)
            dp[i] = min(dp[i], dp[i - 2] + abs(h[i] - h[i - 2]));
    }

    cout << dp[N - 1];

    return 0;
}