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
    vector<int> vec(m + n);
    vector<int> a(m), b(n);
    
    int tmp = 0;
    for(int i = 0; i < m + n; ++i) {
        cin >> vec[i];
        if(tmp < n)
            a[tmp] = vec[i];
        else
            b[tmp - n] = vec[i];
        ++tmp;
    }

    sort(vec.begin(), vec.end());
    for(int i : a)
        cout << i << ' ';

    time();
    return 0;
}