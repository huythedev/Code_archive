#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

void reverseArray(vector<ll>& arr, ll start, ll end) {
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main() {
    ll n;
    cin >> n;

    vector<ll> arr(n + 1);
    for (ll i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    ll flips = 0;
    vector<pair<ll, ll> > flipOperations;

    for (ll i = n; i >= 1; i--) {
        ll maxIndex = max_element(arr.begin() + 1, arr.begin() + i + 1) - arr.begin();
        if (maxIndex != i) {
            flips++;
            flipOperations.push_back({1, maxIndex});
            reverseArray(arr, 1, maxIndex);
        }

        flips++;
        flipOperations.push_back({1, i});
        reverseArray(arr, 1, i);
    }

    cout << flips << endl;
    for (const auto& op : flipOperations) {
        cout << op.first << " " << op.second << endl;
    }

    return 0;
}
