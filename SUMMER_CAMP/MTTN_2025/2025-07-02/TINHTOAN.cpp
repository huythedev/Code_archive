#include <iostream>
#include <string>
#include <vector>
#include <numeric> // For std::gcd in C++17, or use custom implementation
#include <algorithm> // For std::max and std::min
#include <stdexcept>

// Custom GCD for compatibility
long long custom_gcd(long long a, long long b) {
    return std::abs(std::gcd(a, b));
}

// Forward declaration
long long evaluate(const std::string& s, int& pos);

// Function to parse a number from the string
long long parse_number(const std::string& s, int& pos) {
    long long number = 0;
    while (pos < s.length() && isdigit(s[pos])) {
        number = number * 10 + (s[pos] - '0');
        pos++;
    }
    return number;
}

// Main evaluation function
long long evaluate(const std::string& s, int& pos) {
    if (isdigit(s[pos])) {
        return parse_number(s, pos);
    }

    // It's a function call
    std::string func_name;
    while (isalpha(s[pos])) {
        func_name += s[pos];
        pos++;
    }

    pos++; // Skip '('

    long long arg1 = evaluate(s, pos);
    pos++; // Skip ','
    long long arg2 = evaluate(s, pos);
    pos++; // Skip ')'

    if (func_name == "SUM") return arg1 + arg2;
    if (func_name == "DIF") return arg1 - arg2;
    if (func_name == "MAX") return std::max(arg1, arg2);
    if (func_name == "MIN") return std::min(arg1, arg2);
    if (func_name == "GCD") return custom_gcd(arg1, arg2);

    // Should not happen for valid expressions
    throw std::runtime_error("Unknown function: " + func_name);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string expression;
    std::cin >> expression;

    int pos = 0;
    long long result = evaluate(expression, pos);
    std::cout << result << std::endl;

    return 0;
}
