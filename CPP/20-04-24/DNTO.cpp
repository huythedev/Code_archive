#include <bits/stdc++.h>
using namespace std;

#define NAME "DNTO"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if(ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

bool isPrime(int x) {
    if(x < 2) return false;
    for(int i = 2; i * i <= x; ++i) 
        if(x % i == 0) return false;
    return true;
}

int cntprime(int N) {
    int res = 0;
    for(int i = 2; i <= N; ++i) 
        if(isPrime(i)) ++res;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    int N; cin >> N;

    cout << cntprime(N);

    return 0;
}