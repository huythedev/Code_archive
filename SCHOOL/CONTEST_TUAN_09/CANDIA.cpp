#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<long long> other, object;
    long long power = 1;
    while (n > 0) {
        long long rem = n % 3;
        if (rem == 1) {
            other.push_back(power);
            n -= 1;
        } else if (rem == 2) {
            object.push_back(power);
            n += 1;
        }
        n /= 3;
        power *= 3;
    }
    sort(other.begin(), other.end());
    sort(object.begin(), object.end());
    for (size_t i = 0; i < other.size(); i++) cout << other[i] << (i < other.size() - 1 ? " " : "");
    cout << endl;
    for (size_t i = 0; i < object.size(); i++) cout << object[i] << (i < object.size() - 1 ? " " : "");
    cout << endl;
    return 0;
}