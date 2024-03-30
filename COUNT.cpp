#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
#define ln '\n'

typedef long long ll;
typedef long double ld;

const int MAXN = 1e7 + 5;
ll freq[MAXN] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll N;
    cin >> N;

    ll maxfreq = 0;

    for (ll i = 0; i < N; ++i) {
        ll x;
        cin >> x;
        ++freq[x];
        maxfreq = max(maxfreq, freq[x]);
    }

    ll diffkitu = 0;
    for (int i = 0; i < MAXN; ++i) {
        if (freq[i] > 0) {
            ++diffkitu;
        }
    }

    cout << diffkitu << ln;
    cout << maxfreq;

    return 0;
}
