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

    for(ll i = 0; i < st.size(); ++i) {
        if(st[i] == toupper(st[i])) {
            st[i] = tolower(st[i]);
        } else {
            st[i] = toupper(st[i]);
        }
    }

    std::cout << st;

    return 0;
}