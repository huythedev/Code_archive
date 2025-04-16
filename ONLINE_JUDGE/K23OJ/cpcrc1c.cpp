// Author: huythedev (https://huythedev.com)
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

ll sumUpTo(ll n) {
    if (n < 0) return 0;
    if (n < 10) return (n * (n + 1)) / 2;
    
    string s = to_string(n);
    int len = s.length();
    ll res = 0;
    
    ll firstDigit = s[0] - '0';
    ll remaining = stoll(s.substr(1));
    
    // Sum for complete powers of 10
    for (int i = 0; i < len-1; i++) {
        res += 45 * pow(10, i) * (len - 1 - i);
    }
    
    res += firstDigit * (remaining + 1);
    res += firstDigit * (firstDigit - 1) / 2 * pow(10, len-1);
    
    if (remaining >= 0)
        res += sumUpTo(remaining);
        
    return res;
}

int main() {
    fastio();
    docfile();

    ll a, b; cin >> a >> b;
    
    cout << sumUpTo(b) - sumUpTo(a-1) << ln;

    time();
    return 0;
}