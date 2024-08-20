#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

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
    std::string s1 = s;
    
    reverse(s1.begin(), s1.end());

    if(s1 == s)
        std::cout << "YES";
    else
        std::cout << "NO";

    return 0;
}
