// Author: huythedev (https://huythedev.com)
// Problem Link: 
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "PALINPRIME"
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

string convert_to_string(ll n) {
    string res = "";
    while (n > 0) {
        res += (n % 10) + '0';
        n /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

bool isPalin(ll n) {
    string s = convert_to_string(n);
    string rev = s;
    reverse(rev.begin(), rev.end());
    return s == rev;
}

bool is_Prime(int n) {
    if (n <= 1) 
        return false;
    if (n <= 3) 
        return true;
    if (n % 2 == 0 || n % 3 == 0) 
        return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) 
            return false;
    }
    return true;
}

int sum_digit(ll num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

ll string_to_ll(string s) {
    ll res = 0;
    for (char c : s) {
        res = res * 10 + (c - '0');
    }
    return res;
}

vector<ll> gen(ll L, ll R) {
    vector<ll> res;
    for (int len = 1; len <= 12; ++len) {
        int half = (len + 1) / 2;

        ll start = pow(10, half - 1);
        ll end = pow(10, half);

        for (ll i = start; i < end; ++i) {
            string half = to_string(i);
            string revHalf = half;

            reverse(revHalf.begin(), revHalf.end());

            string tmp = half + revHalf.substr(len % 2);
            ll palin = string_to_ll(tmp);
            if (palin >= L && palin <= R) {
                res.push_back(palin);
            }
        }
    }
    return res;
}

int main() {
    fastio();
    docfile();

    ll L, R;
    cin >> L >> R;

    vector<ll> vec = gen(L, R);
    int res = 0;
    for (ll num : vec) {
        if (is_Prime(sum_digit(num))) {
            res++;
        }
    }

    cout << res;

    time();
    return 0;
}