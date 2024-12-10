
#include <bits/stdc++.h>
using namespace std;

void printPermutations(int n, int k) {
    vector<int> nums(n);
    iota(nums.begin(), nums.end(), 1);
    do {
        for (int i = 0; i < k; ++i) {
            cout << nums[i] << ' ';
        }
        cout << '\n';
    } while (next_permutation(nums.begin(), nums.end()));
}

int main() {
    int n, k;
    cin >> n >> k;
    printPermutations(n, k);
    return 0;
}