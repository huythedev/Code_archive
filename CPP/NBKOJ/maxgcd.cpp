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

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<pair<int, pair<int, int>>> gcd_pairs;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            gcd_pairs.emplace_back(gcd(a[i], a[j]), make_pair(i, j));
        }
    }

    sort(gcd_pairs.begin(), gcd_pairs.end(), greater<pair<int, pair<int, int>>>());

    int max_sum = 0;
    for (int i = 0; i < gcd_pairs.size(); i++) {
        for (int j = i + 1; j < gcd_pairs.size(); j++) {
            int gcd1 = gcd_pairs[i].first;
            int gcd2 = gcd_pairs[j].first;
            int sum = gcd1 + gcd2;
            if (sum > max_sum &&
                gcd_pairs[i].second.first != gcd_pairs[j].second.first &&
                gcd_pairs[i].second.first != gcd_pairs[j].second.second &&
                gcd_pairs[i].second.second != gcd_pairs[j].second.first &&
                gcd_pairs[i].second.second != gcd_pairs[j].second.second) {
                max_sum = sum;
            }
        }
    }

    cout << max_sum << endl;

    return 0;
}