// Author: Perry (https://perrythedev.com)
// Problem Link: https://marisaoj.com/problem/409
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

    // Given an array A of n

    // integer elements, count the number of dominant elements in the array. An element is considered dominant if it is greater than all the elements to its right in the array.

    // The last element cannot not be a dominant element as there is no element to its right in the array.

    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    int ans = 0, max_val = INT_MIN;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] > max_val) {
            max_val = a[i];
            ans++;
        }
    }
    cout << ans;

    time();
    return 0;
}