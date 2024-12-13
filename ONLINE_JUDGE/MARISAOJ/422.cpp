// Author: Perry (https://perrythedev.com)
// Problem Link: https://marisaoj.com/problem/422
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

int main() {
    fastio();
    docfile();

    int n; cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) 
        cin >> A[i];
    int x, y; cin >> x >> y;
    --x; --y; 

    int clockwise_distance = 0, counter_clockwise_distance = 0;
    for (int i = x; i != y; i = (i + 1) % n) {
        clockwise_distance += A[i];
    }
    for (int i = x; i != y; i = (i - 1 + n) % n) {
        counter_clockwise_distance += A[(i - 1 + n) % n];
    }

    cout << min(clockwise_distance, counter_clockwise_distance) << endl;

    time();
    return 0;
}