#include <bits/stdc++.h>
using namespace std;

ifstream fin("TONGSOUOC.INP");
ofstream fout("TONGSOUOC.OUT");

long long countDivisors(long long x) {
    long long cnt = 0;
    for (long long i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            cnt++;
            if (i != x / i) cnt++;
        }
    }
    return cnt;
}

int main() {
    long long L, R;
    fin >> L >> R;
    long long res = 0;
    
    for (long long i = L; i <= R; i++) {
        res += countDivisors(i);
    }

    fout << res << "\n";
    return 0;
}
