#include <iostream>

void docfile() {
    freopen("UOCCHUNG.INP", "r", stdin);
    freopen("UOCCHUNG.OUT", "w", stdout);
}

long long GCD(long long a, long long b) {
    while(b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    docfile();
    long long A, B;
    std::cin >> A >> B;

    long long uocchung = GCD(A, B);

    while(true) {
        uocchung--;
        if(A % uocchung == 0 && B % uocchung == 0) {
            break;
        }
    }

    if(uocchung > 0) {
        std::cout << uocchung;
    }
    else {
        std::cout << "-1";
    }
    return 0;
}