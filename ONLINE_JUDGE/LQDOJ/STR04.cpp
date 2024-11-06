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

    while(st[0] == ' ') {
        st.erase(0, 1);
    }

    while(st[st.size() - 1] == ' ') {
        st.erase(st.size() - 1, 1);
    }

    for(ll i = 0; i < st.size(); ++i) {
        if(st[i] == ' ' && st[i + 1] == ' ') {
            st.erase(i, 1);
            i--;
        }
    }
    std::cout << st << "\n";

    return 0;
}