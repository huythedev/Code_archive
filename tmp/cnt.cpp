#include <bits/stdc++.h>
using namespace std;

static long long cnt = 0; // global count as in the prompt

// Partition on subarray a[l..r], using the exact counting rules given
int partition_with_count(long long pivot, vector<long long> &a, int l, int r) {
    int left = l, right = r;
    while (left <= right) {
        while (a[left] < pivot) { // same structure as the prompt
            left++;
            cnt++;
        }
        while (a[right] > pivot) {
            right--;
            cnt++;
        }
        cnt += 2; // matches the given code
        if (left <= right) {
            swap(a[left], a[right]);
            left++;
            right--;
        }
    }
    return left - 1; // index in the original array
}

void quicksort_with_count(vector<long long> &a, int l, int r) {
    if (r > l) {
        long long pivot = (a[l] + a[r] + a[(l + r) / 2]) / 3; // integer division
        int i = partition_with_count(pivot, a, l, r);
        quicksort_with_count(a, l, i);
        quicksort_with_count(a, i + 1, r);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    cnt = 0;
    quicksort_with_count(a, 0, n - 1);
    cout << cnt << "\n";
    return 0;
}
