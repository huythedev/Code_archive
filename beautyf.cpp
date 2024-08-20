#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
#define ln '\n'

typedef long long ll;
typedef long double ld;

const ll MAXN = 100000;

void docfile() {
    if(ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

vector<ll> beautyf;

bool isPrime(ll n) {
    if(n < 2) return false;
    for(ll i = 2; i * i <= n; ++i) {
        if(n % i == 0) return false;
    }
    return true;
}

bool isSumcsPrime(string n) {
    ll sum = 0;
    for(char c : n) {
        sum += (c - '0') * (c - '0');
    }

    return isPrime(sum);
}

void buildvec() {
    beautyf.push_back(11);
    ll tmp = 12;
    while(beautyf.size() < MAXN) {
        if(isSumcsPrime(to_string(tmp))) {
            beautyf.push_back(tmp);
        }
        ++tmp;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();
    buildvec();

    ll n;
    while(cin >> n) {
        cout << beautyf[n - 1] << ln;
    }

    return 0;
}