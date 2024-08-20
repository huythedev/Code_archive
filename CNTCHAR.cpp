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

    ll freq[300] = {0};

    std::string st;
    getline(std::cin, st);

    for(char c : st) {
        freq[c]++;
    }

    ll res = 0;
    for(ll i = 0; i < 300; ++i) {
        if(freq[i] == 1) {
            res++;
        }
    }

    std::cout << res;
    return 0;
}