#include <iostream>
#include <fstream>
#include <string>

#define NAME "MATKHAU"

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
    
    std::string res = "";
    ll sumcsc = 0;
    for(char c : st) {
        if(c >= '0' && c <= '9' && (c - '0') % 2 == 0){
            sumcsc += c - '0';
        }
    }

    res += std::to_string(sumcsc);
    res += std::to_string(st.length());

    std::cout << res;

    return 0;
}