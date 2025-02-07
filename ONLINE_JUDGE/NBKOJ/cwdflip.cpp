#include <cstdio>
#include <iostream>
#include <string>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::string s; std::cin >> s;
	for (char c : s) {
		if (c - '0' == 0)
			std::cout << 1;
		else
			std::cout << 0;
	}
	return 0;
}
