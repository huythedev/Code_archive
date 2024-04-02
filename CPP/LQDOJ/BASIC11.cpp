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

    std::string s;
    getline(std::cin, s);

    std::cout << s[0] << "\n" << s[1] << "\n" << s[2];

    return 0;
}