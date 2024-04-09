#include <iostream>
#include <vector>

int main() {
    const size_t bytes_in_gb = 1024 * 1024 * 1024;
    const size_t num_elements = bytes_in_gb / sizeof(char);

    std::vector<char> stress_vector(num_elements);

    return 0;
}
