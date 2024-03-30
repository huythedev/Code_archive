#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N;
    cin >> N;
    N *= N;

    vector<long long> vec;
    for (long long i = 0; i < N; ++i) {
        long long tmp;
        cin >> tmp;
        vec.push_back(tmp);
    }

    vector<long long> hang, cot;
    for (long long i = 0; i < N; i += sqrt(N)) {
        long long tmp = 0;
        for (long long j = 0; j < sqrt(N); ++j) {
            tmp += vec[i + j];
        }
        hang.push_back(tmp);
    }

    for (long long i = 0; i < sqrt(N); ++i) {
        long long tmp = 0;
        for (long long j = 0; j < N; j += sqrt(N)) {
            tmp += vec[i + j];
        }
        cot.push_back(tmp);
    }

    long long res = 0;
    for (long long i = 0; i < sqrt(N); ++i) {
        for (long long j = 0; j < sqrt(N); ++j) {
            if (hang[i] == cot[j]) {
                ++res;
            }
        }
    }

    cout << res;
    return 0;
}