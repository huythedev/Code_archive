#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if (ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    ll n;
    cin >> n;

    vector<ll> a(n);
    ll maxnum = LLONG_MIN, minnum = LLONG_MAX;
    ld avg = 0;
    map<ll, ll> freq;

    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        maxnum = max(maxnum, a[i]);
        minnum = min(minnum, a[i]);

        avg += a[i];

        freq[a[i]]++;
    }
    avg /= n;

    // The output of the maximum, minimum, and average
    cout << fixed << setprecision(12);
    cout << maxnum << ln 
         << minnum << ln
         << avg << ln;

    sort(a.begin(), a.end());

    // The output of the median
    ll median;
    if (n % 2 == 0) {
        median = max(a[n / 2], a[n / 2 - 1]);
    }
    else {
        median = a[(n + 1) / 2];
    }
    cout << median << ln;

    // Caculate the max freq of number in the vector
    ll maxfreq = 0, maxfreq_val;
    for(auto &i : freq) {
        if(i.second > maxfreq) {
            maxfreq = i.second;
            maxfreq_val = i.first;
        }

        if(i.second == maxfreq && i.first < maxfreq_val) {
            maxfreq_val = i.first;
        }
    }
    cout << maxfreq_val << ln;

    // Calculate sigma of the array
    ld tmp = 0;
    for (ll i = 0; i < n; ++i) {
        tmp += (a[i] - avg) * (a[i] - avg);
    }
    ld sigma = sqrt(tmp / (ld)n);
    cout << sigma;

    return 0;
}
