#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>

#define NAME "VANBAN"
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

	std::string st, maxst = "";
	while(getline(std::cin, st)) {
		if(st.length() > maxst.length()) {
			maxst = st;
		}
	}
	
	std::cout << maxst.length() << ln << maxst;

    return 0;
}