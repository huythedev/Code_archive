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
    for(int i = 2; i * i <= n; ++i) {
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

    int n; cin >> n;

    vector<int> res = ptts(n);
    cout << res.size() << ln;
    for(int i : res) 
        cout << i << " ";

    return 0;
}