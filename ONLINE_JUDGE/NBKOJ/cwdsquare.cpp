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

bool isCP(string n) {
    int len = n.length();
    int digit = (len + 1) / 2;
    int sqrtVal = pow(10, digit);

    long long left = 0, right = sqrtVal;
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long midSquare = mid * mid;

        if (midSquare == stoull(n)) {
            return true;
        } else if (midSquare > stoull(n)) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    int T;
    cin >> T;

    while(T--) {
        cin >> ws;
        string n;
        getline(cin, n);

        cout << (isCP(n) ? "YES" : "NO") << ln;
    }

    return 0;
}