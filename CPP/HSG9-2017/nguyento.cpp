#include <bits/stdc++.h>
using namespace std;

#define NAME "nguyento"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if(ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

bool isPrime(int n) {
    for(int i = 2; i * i <= n; ++i) 
        if(n % i == 0) 
            return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    int n; cin >> n;
    ++n;
    while(!isPrime(n)) 
        ++n;

    cout << n;

    return 0;
}