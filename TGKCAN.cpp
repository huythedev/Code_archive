#include <iostream>

int main() {
	long long a, b, c;
	std::cin >> a >> b >> c;
	
	if(a != b && b != c && a != c && a + b > c && a + c > b && b + c > a) {
		std::cout << "YES";
	}
	else {
		std::cout << "NO";
	}
	
	return 0;
}