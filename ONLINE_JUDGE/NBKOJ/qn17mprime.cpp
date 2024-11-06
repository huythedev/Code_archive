#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if(ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int xuly(vector<vector<int>>& arr, int n, int m) {
    int res = INT_MAX;

    for (int i = 0; i < n; i++) {
        int thaotac = 0;
        for (int j = 0; j < m; j++) {
            int num = arr[i][j];
            if (!isPrime(num)) {
                thaotac += (num % 2 == 0) ? num / 2 : (num + 1) / 2;
            }
        }
        res = min(res, thaotac);
    }

    for (int j = 0; j < m; j++) {
        int thaotac = 0;
        for (int i = 0; i < n; i++) {
            int num = arr[i][j];
            if (!isPrime(num)) {
                thaotac += (num % 2 == 0) ? num / 2 : (num + 1) / 2;
            }
        }
        res = min(res, thaotac);
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    cout << xuly(arr, n, m) << endl;

    return 0;
}