#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    
    for (long long T = M; ; T++) {
        bool found = false;
        for (long long a = 1; a * a <= T; a++) {
            if (T % a == 0) {
                long long b = T / a;
                if (a <= N && b <= N) {
                    found = true;
                    break;
                }
            }
        }
        if (found) {
            cout << T << endl;
            return 0;
        }
    }
    
    cout << -1 << endl;
    return 0;
}
