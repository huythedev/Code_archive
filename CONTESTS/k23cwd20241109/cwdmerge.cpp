// Author: Perry (https://perrythedev.com)
// Problem Link: https://nbk.homes/problem/cwdmerge
#include <bits/stdc++.h>
using namespace std;

#define NAME "cwdmerge"
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

    int n, m; cin >> n >> m;
    vector<int> vec;
    vector<int> a(n), b(m);
    
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        vec.push_back(a[i]);
    }
    for(int i = 0; i < m; ++i) {
        cin >> b[i];
        vec.push_back(b[i]);
    }

    sort(vec.begin(), vec.end());
    map<int, int> hehe;
    
    for(int i = 0; i < m + n; ++i) {
        hehe[vec[i]] = i;
    }

    for(int i : a)
        cout << hehe[i] << ' ';
    cout << ln;
    for(int i : b)
        cout << hehe[i] << ' ';

    time();
    return 0;
}