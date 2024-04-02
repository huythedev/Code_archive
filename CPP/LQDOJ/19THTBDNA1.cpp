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

    ll count = 0;
    for(char c : st) {
        if((c - '0') % 2 != 0) 
            ++count;
    }

    std::cout << count;

    return 0;
}
