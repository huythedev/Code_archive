#include <iostream>

int main() {
    int x;
    std::cin >> x;

    int tmp = 2;
    while(true) {
        if(x % tmp == 0) {
            break;
        }
        tmp++;
    }
    std::cout << x / tmp;
    return 0;
}