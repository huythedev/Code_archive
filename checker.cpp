#include "testlib.h"
#include <cmath>
#include <iomanip>
#include <string>
#include <sstream>

// Function to compare results, trimming whitespace
bool compare_result(const std::string& a, const std::string& b) {
    return trim(a) == trim(b); // Use trim from testlib
}

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    
    long long A = inf.readLong();
    long long B = inf.readLong();
    long long C = inf.readLong();
    double discriminant = static_cast<double>(B) * B - 4 * A * C;

    // Read user output as string for "NO SOLUTION"
    std::string x1_user, x2_user;
    
    // Check for no real solutions (discriminant < 0)
    if (discriminant < 0) {
        x1_user = ouf.readString(); 
        
        // Ensure correct output
        ensuref(compare_result(x1_user, "NO SOLUTION"),
                "Expected 'NO SOLUTION', but got: '%s'", x1_user.c_str());
        quitf(_ok, "NO SOLUTION");
    }
    
    // Check for one real solution (discriminant == 0)
    else if (fabs(discriminant) < 1e-6) {
        double root = -static_cast<double>(B) / (2 * A);
        std::ostringstream expected;
        expected << std::fixed << std::setprecision(5) << root; // Ensure fixed precision
        
        x1_user = ouf.readToken(); // Read user output as token
        ensuref(compare_result(x1_user, expected.str()),
                "Expected root: %s, but got: '%s'", expected.str().c_str(), x1_user.c_str());
        quitf(_ok, "%s", expected.str().c_str());
    } 
    // Check for two distinct real solutions (discriminant > 0)
    else {
        double root1 = (-static_cast<double>(B) + sqrt(discriminant)) / (2 * A);
        double root2 = (-static_cast<double>(B) - sqrt(discriminant)) / (2 * A);
        
        std::ostringstream expected1, expected2;
        expected1 << std::fixed << std::setprecision(5) << root1;
        expected2 << std::fixed << std::setprecision(5) << root2;

        x1_user = ouf.readToken(); // Read first root as token
        x2_user = ouf.readToken(); // Read second root as token

        ensuref((compare_result(x1_user, expected1.str()) && compare_result(x2_user, expected2.str())) ||
                (compare_result(x1_user, expected2.str()) && compare_result(x2_user, expected1.str())),
                "Expected roots: '%s' and '%s', but got: '%s' and '%s'", expected1.str().c_str(), expected2.str().c_str(), x1_user.c_str(), x2_user.c_str());
        quitf(_ok, "%s %s", x1_user.c_str(), x2_user.c_str());
    }
    
    return 0;
}
