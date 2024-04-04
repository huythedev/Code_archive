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

    ll n, X;
    cin >> n >> X;

    vector<int> a(n * 2);
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    ll sum = 0;
    for(int i : a) 
        sum += i;

    if(sum < X) {
        cout << -1;
        return 0;
    }

    for(int i = 0; i < n; ++i) {
        a[i + n] = a[i];
    }

    ll min_length = LLONG_MAX;
    for(int i = 0; i < n; ++i) {
        ll length = 1;
        ll tmp = a[i];
        if(tmp >= X) {
            min_length = 1;
            break;
        }

        for(int j = i + 1; j < i + n; ++j) {
            ++length;
            tmp += a[j];
            if(tmp >= X) {
                min_length = min(min_length, length);
                break;
            }
        }
    }

    if(min_length == LLONG_MAX) 
        cout << -1;
    else 
        cout << min_length;

    return 0;
}