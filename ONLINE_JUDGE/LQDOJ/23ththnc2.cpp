// Author: Perry (https://perrythedev.com)^
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e6;
vector<ll> sequence;

// Function to check if a number is prime
bool is_prime(int n) {
    if(n < 2) return false;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

// Function to get digit sum
int digit_sum(ll n) {
    int sum = 0;
    while(n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

// Precompute sequence
void precompute() {
    sequence.push_back(0);  // 0th element (not used)
    ll num = 1;
    for(int i = 1; i <= MAXN; i++) {
        while(!is_prime(digit_sum(num))) num++;
        sequence.push_back(num);
        num++;
    }
}

// Function to find kth number
ll solve(ll k) {
    if(k <= MAXN) return sequence[k];
    
    // For larger k, start from last precomputed number
    ll num = sequence.back();
    for(ll i = MAXN; i < k; i++) {
        num++;
        while(!is_prime(digit_sum(num))) num++;
    }
    return num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    precompute();
    
    int t;
    cin >> t;
    while(t--) {
        ll k;
        cin >> k;
        cout << solve(k) << '\n';
    }
    
    return 0;
}