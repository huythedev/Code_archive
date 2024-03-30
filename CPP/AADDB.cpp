#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>

#define NAME "NAME"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if(std::ifstream(NAME".inp")) {
        std::freopen(NAME".inp", "r", stdin);
        std::freopen(NAME".out", "w", stdout);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
    docfile();

    std::string a, b;
    std::cin >> a >> b;

    std::string res = "";
    ll carry = 0;
    for(ll i = a.length() - 1, j = b.length() - 1; i >= 0 || j >= 0; --i, --j) {
        ll x = (i >= 0) ? a[i] - '0' : 0;
        ll y = (j >= 0) ? b[j] - '0' : 0;
        ll sum = x + y + carry;
        res = std::to_string(sum % 10) + res;
        carry = sum / 10;
    }

    if(carry) res = std::to_string(carry) + res;

    std::cout << res;

    return 0;
}