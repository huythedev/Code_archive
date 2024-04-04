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

    int max1, max2, pos1, pos2;
    for(int i = 0; i < n - 1; ++i) {
        for(int j = i + 1; j < n; ++j) {
            if(__gcd(a[i], a[j]) > max1) {
                max1 = __gcd(a[i], a[j]);
                pos1 = i;
                pos2 = j;
            }
        }
    }

    a.erase(a.begin() + pos1);
    pos2--;
    a.erase(a.begin() + pos2);

    for(int i = 0; i < n - 1; ++i) {
        for(int j = i + 1; j < n; ++j) {
            if(__gcd(a[i], a[j]) > max2) {
                max2 = __gcd(a[i], a[j]);
            }
        }
    }

    cout << max1 + max2;

    return 0;
}