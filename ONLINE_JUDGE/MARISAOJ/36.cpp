// Author: Perry (https://perrythedev.com)
// Problem Link: https://marisaoj.com/problems/36
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
    unordered_map<int, int> freq;
    vector<int> vec;

    for(int i = 0; i < n; ++i) {
        int x; cin >> x;
        if(freq[x] == 0) {
            vec.push_back(x);
        }
        freq[x]++;
    }

    sort(vec.begin(), vec.end());

    for(int i : vec)
        cout << i << ' ';

    time();
    return 0;
}