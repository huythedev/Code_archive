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

    ll a, b;
    cin >> a >> b;

    ll n = b - a + 1;
    vector<pair<string, ll>> nums(n);

    for (ll i = 0; i < n; i++) {
        ll x = a + i;
        nums[i] = {to_string(x), i};
    }

    sort(nums.begin(), nums.end());

    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        if (nums[i].second != i) {
            ans++;
            swap(nums[i], nums[nums[i].second]);
            i--;
        }
    }

    cout << ans << "\n";
    return 0;
}