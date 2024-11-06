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

int MAXR = 1e6;

vector<int> divisors(MAXR + 1);
void pre_cacl() {
    for(int i = 1; i <= MAXR; i++) {
        for(int j = i; j <= MAXR; j += i) {
            divisors[j]++;
        }
    }
}

vector<ll> build_prefixsum(vector<int> vec) {
    vector<ll> res(vec.size() + 1);
    res[0] = 0;
    for(int i = 1; i < vec.size(); i++) 
        res[i] = res[i - 1] + vec[i];
    
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    pre_cacl();
    int T;
    cin >> T;
    vector<ll> prefixsum = build_prefixsum(divisors);

    while(T--) {
        int L, R;
        cin >> L >> R;

        cout << prefixsum[R] - prefixsum[L - 1] << ln;
    }

    return 0;
}