// Author: Perry (https://perrythedev.com)
// Problem Link: https://lqdoj.edu.vn/problem/23ththnc2
#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
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

bool isPrime(int n) {
    if (n < 2) return false;
    if (n < 4) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

bool isSumPrime(ll num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return isPrime(sum);
}

int main() {
    fastio();
    docfile();

    int t;
    cin >> t;
    vector<ll> queries(t);
    ll maxK = 0;

    for (int i = 0; i < t; ++i) {
        cin >> queries[i];
        maxK = max(maxK, queries[i]);
    }

    vector<ll> sequence;
    ll num = 1;
    while (sequence.size() < maxK) {
        if (isSumPrime(num)) {
            sequence.push_back(num);
        }
        num++;
    }

    for (int i = 0; i < t; ++i) {
        cout << sequence[queries[i] - 1] << endl;
    }

    time();
    return 0;
}