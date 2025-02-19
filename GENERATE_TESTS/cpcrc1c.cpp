// Author: Perry (https://perrythedev.com)
// Problem Link: https://k23oj.site/problem/cpcrc1c
#include <bits/stdc++.h>
using namespace std;

#define NAME "cpcrc1c"
#define ln "\n"
#define sz size()

typedef long long ll;
typedef long double ld;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void docfile() {
    if (ifstream(NAME ".INP")) {
        freopen(NAME ".INP", "r", stdin);
        freopen(NAME ".OUT", "w", stdout);
    }
}

void time() {
    cerr << ln << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." 
         << ln;
}

ll digitSum(ll n) {
    ll sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

ll sumDigitsFrom1ToN(ll n) {
    if (n < 10) return (n * (n + 1)) / 2;

    string s = to_string(n);
    int len = s.length();
    ll firstDigit = s[0] - '0';
    ll remaining = n - firstDigit * pow(10, len - 1);

    ll sum = 0;
    for (int i = 0; i < firstDigit; ++i) {
        sum += i * pow(10, len - 1) + (len - 1) * 45 * pow(10, len - 2);
    }
    sum += firstDigit * (remaining + 1) + sumDigitsFrom1ToN(remaining);

    return sum;
}

int main() {
    fastio();
    docfile();

    ll a, b; cin >> a >> b;
        cout << sumDigitsFrom1ToN(b) - sumDigitsFrom1ToN(a - 1) << '\n';

    time();
    return 0;
}