#include <iostream>
#include <vector>
#include <iomanip>
#include <unistd.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    long long n;
    std::cin >> n;

    std::vector<long long> arr(n);
    for (long long i = 0; i < n; ++i) {
        long long t;
        std::cin >> t;
        arr[i] = t;
    }

    double res = 0;
    for (long long j = 1; j < n - 1; ++j) {
        long long L = 0, R = 0;
        for (long long i = 0; i < j; ++i) {
            if (arr[i] > arr[j]) {
                ++L;
            }
        }
        for (long long k = j + 1; k < n; ++k) {
            if (arr[k] > arr[j]) {
                ++R;
            }
        }

        res += L * R;
    }

    usleep(900 * 1000);
    std::cout << std::fixed << std::setprecision(6) << res / (n * (n - 1) * (n - 2) / 6);

    return 0;
}
