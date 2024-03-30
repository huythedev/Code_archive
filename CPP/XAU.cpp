#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>

#define NAME "XAU"
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

	std::string st;
	while(std::cin >> st) {
		std::string num = "", maxnum = "";
		for(char c : st) {
			if(c - '0' >= 0 && c - '0' <= 9) {
				num += c;
				maxnum += c;
			}
		}
		sort(maxnum.rbegin(), maxnum.rend());
		std::cout << num << ln << maxnum << ln;
	}

    return 0;
}