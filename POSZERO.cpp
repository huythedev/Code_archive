#include <iostream>
#include <fstream>
#include <string>

#define NAME "NAME"

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

    std::string st;
    getline(std::cin, st);

    ll pos;
    for(ll i = st.length() - 1; i >= 0; --i) {
        if(st[i] == '0') {
            pos = i;
            break;
        }
    }

    std::cout << pos + 1;

    return 0;
}