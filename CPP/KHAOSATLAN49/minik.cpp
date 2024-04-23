#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if (ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    deque<int> tmp;
    for (int i = 0; i < k; ++i) {
        while (!tmp.empty() && arr[i] <= arr[tmp.back()])
            tmp.pop_back();
        tmp.push_back(i);
    }

    for (int i = k; i < n; ++i) {
        cout << arr[tmp.front()] << endl;

        while (!tmp.empty() && tmp.front() <= i - k)
            tmp.pop_front();

        while (!tmp.empty() && arr[i] <= arr[tmp.back()])
            tmp.pop_back();

        tmp.push_back(i);
    }

    cout << arr[tmp.front()] << endl;

    return 0;
}
