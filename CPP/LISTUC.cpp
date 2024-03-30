#include <iostream>

int main() {
	int n, m;
	std::cin >> n >> m;
	
	for(int i = 1; i <= std::min(m, n); ++i) {
		if(n % i == 0 && m % i == 0) {
			std::cout << i << " ";
		}
	}
}