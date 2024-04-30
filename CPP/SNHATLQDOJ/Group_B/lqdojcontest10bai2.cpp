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

int sumnum(int n) {
    int res = 0;
    while(n) {
        res += n % 10;
        n /= 10;
    }
    return res;
}

bool isPrime(int n) {
    if(n < 2) return false;
    for(int i = 2; i <= sqrt(n); ++i) 
        if (n % i == 0) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    int L, R; cin >> L >> R;

    int res = 0;
    for(int i = L; i <= R; ++i) {
        if(sumnum(i) % 5 == 0) 
            if(isPrime(i)) ++res;
    }

    cout << res;

    return 0;
}