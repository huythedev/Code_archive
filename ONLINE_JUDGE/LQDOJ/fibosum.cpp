#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

// Hàm nhân hai ma trận 2x2
void multiplyMatrices(long long a[2][2], long long b[2][2], long long res[2][2]) {
    long long temp[2][2];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            temp[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                temp[i][j] = (temp[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            res[i][j] = temp[i][j];
        }
    }
}

// Hàm tính số Fibonacci thứ n
long long fib(long long n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    long long base[2][2] = {{0, 1}, {1, 1}};
    long long result[2][2] = {{1, 0}, {0, 1}};
    
    while (n > 0) {
        if (n % 2 == 1) {
            long long temp[2][2];
            multiplyMatrices(result, base, temp);
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    result[i][j] = temp[i][j];
                }
            }
        }
        long long temp[2][2];
        multiplyMatrices(base, base, temp);
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                base[i][j] = temp[i][j];
            }
        }
        n /= 2;
    }
    
    return result[0][1];
}

// Hàm tính tổng dãy Fibonacci từ 0 đến n
long long sumFib(long long n) {
    return (fib(n + 2) - 1 + MOD) % MOD;
}

int main() {
    long long n;
    cin >> n;
    cout << sumFib(n) << endl;
    return 0;
}