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

vector<int> ptts(int n) {
    vector<int> res;
    for(int i = 2; i <= sqrt(n); i++) {
        while(n % i == 0) {
            res.push_back(i);
            n /= i;
        }
    }

    if(n > 1) 
        res.push_back(n);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    int tests; cin >> tests;
    while(tests--) {
        int n, m; cin >> n >> m;
        vector<int> snt_a, snt_b;

        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            vector<int> primes = ptts(x);
            snt_a.insert(snt_a.end(), primes.begin(), primes.end());
        }

        for(int i = 0; i < m; i++) {
            int x; cin >> x;
            vector<int> primes = ptts(x);
            snt_b.insert(snt_b.end(), primes.begin(), primes.end());
        }

        sort(snt_a.begin(), snt_a.end());
        sort(snt_b.begin(), snt_b.end());

        if(snt_a == snt_b) 
            cout << "YES" << ln;
        else 
            cout << "NO" << ln;
    }

    return 0;
}