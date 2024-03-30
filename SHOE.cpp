#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n;
    cin >> n;
    n = n * 2 - 1;
    ll res = 0;
    while (n--) {
        ll tmp;
        cin >> tmp;
        res += tmp;
    }

    if (res > 0) {
        cout << "-1" << endl << res;
    }
    else {
        cout << "1" << endl << abs(res);
    }

    return 0;
}