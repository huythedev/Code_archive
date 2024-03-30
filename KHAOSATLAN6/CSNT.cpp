#include <bits/stdc++.h>
using namespace std;

bool checknto(long long n) {
    if (n < 2) {
        return false;
    }
    for (long long i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    string S;
    getline(cin, S);

    set<long long> res;
    for (char c : S) {
        long long tmp = c - '0';
        if (checknto(tmp)) {
            res.insert(tmp);
        }
    }

    for (long long i : res) {
        cout << i << " ";
    }
    return 0;
}