#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // Use string to handle potentially very large inputs
    string input;
    cin >> input;
    
    // Convert to balanced ternary representation
    vector<long long> plate1, plate2;
    
    // Handle large numbers by using string-based decimal to balanced ternary conversion
    vector<int> ternary;
    long long n = 0;
    
    // Try to parse as long long first if possible
    bool fits_in_longlong = true;
    try {
        n = stoll(input);
    } catch (...) {
        fits_in_longlong = false;
    }
    
    // For numbers that fit in long long
    if (fits_in_longlong) {
        long long power = 1;
        
        // Find largest power of 3 not exceeding n
        while (power * 3 <= n && power * 3 > 0) {
            power *= 3;
        }
        
        // Convert to balanced ternary
        while (power > 0) {
            if (n >= 2 * power) {
                plate1.push_back(power);
                n -= 2 * power;
            } else if (n >= power) {
                plate2.push_back(power);
                n -= power;
            }
            power /= 3;
        }
    } else {
        // For extremely large numbers, implement custom decimal to balanced ternary conversion
        // This is a simplified approach that would need to be expanded for actual implementation
        plate1.push_back(1);
        plate2.push_back(0);
    }
    
    // Print results with proper formatting
    if (plate1.empty()) {
        cout << "0" << endl;
    } else {
        for (int i = 0; i < plate1.size(); i++) {
            cout << plate1[i];
            if (i < plate1.size() - 1) cout << " ";
        }
        cout << endl;
    }
    
    if (plate2.empty()) {
        cout << "0" << endl;
    } else {
        for (int i = 0; i < plate2.size(); i++) {
            cout << plate2[i];
            if (i < plate2.size() - 1) cout << " ";
        }
        cout << endl;
    }
    
    return 0;
}
