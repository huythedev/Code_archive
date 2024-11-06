#include <bits/stdc++.h>
using namespace std;
#define NAME "sotronthun"
#define ln "\n"
typedef long long ll;
typedef long double ld;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void docfile() {
    if (ifstream(NAME".INP")) {
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
}

void time() {
    cerr << ln << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << ln;
}

int digitSum(long long num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

long long solve(long long N) {
    if (N == 1) return 0; // Handle the base case
    
    long long count = 1; // Starting count with the first circular number '0'
    long long num = 19;  // Start from the first non-zero circular number
    
    while (count < N) {
        if (digitSum(num) % 10 == 0) {
            count++;
        }
        if (count < N) {
            num += 9;  // Increment by 9 to skip directly to the next likely circular number
        }
    }
    return num;
}

int main() {
    fastio();
    docfile();
    
    ll n;
    cin >> n;
    
    cout << solve(n) << ln;
    
    time();
    return 0;
}