#include <iostream>
#include <fstream>
#include <string>

#define NAME "NAME"

typedef long long ll;
typedef long double ld;

const ll MOD = 1234567891;

void docfile() {
    if(std::ifstream(NAME".inp")) {
        std::freopen(NAME".inp", "r", stdin);
        std::freopen(NAME".out", "w", stdout);
    }
}

int maximize_sum(int n) {
    std::vector<int> digits;
    while (n > 0) {
        digits.push_back(n % 10);
        n /= 10;
    }
    std::reverse(digits.begin(), digits.end());

    int max_digit = *std::max_element(digits.begin(), digits.end());

    auto max_digit_it = std::find(digits.begin(), digits.end(), max_digit);
    int max_digit_index = std::distance(digits.begin(), max_digit_it);

    if (max_digit_index != 0) {
        std::swap(digits[0], digits[max_digit_index]);
    }

    int modified_number = 0;
    for (int digit : digits) {
        modified_number = modified_number * 10 + digit;
    }

    return modified_number;
}

int calculate_sum(int n, int m) {
    for (int i = 0; i < m; ++i) {
        n = maximize_sum(n);
    }

    return n;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
    docfile();

    int T;
    std::cin >> T;
    while(T--) {
        std::string n;
        std::cin >> n;

        ll res = 0;
        for(int i = 0; i < n.length() - 1; ++i) {
            for(int j = i + 1; j < n.length(); ++j) {
                std::swap(n[i], n[j]);
                std::cout << n << "\n";
                res = (res + std::stoi(n)) % MOD;
                std::swap(n[i], n[j]);
            }
        }
        std::cout << res << "\n";
    }
    
    return 0;
}