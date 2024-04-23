#include <iostream>
using namespace std;

int main() {
    long long res = 0;
    for(int i = 0; i <= (int)1e9; ++i) {
        for(int j = 0; j <= (int)1e9; ++j) {
            for(int k = 0; k <= int(1e9); ++k)
                ++res;
        }
    }
    cout << res;
}