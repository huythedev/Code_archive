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
const int MOD = 1e9 + 7;
const int MAX_LEN = 49;
const int MAX_SIZE = 8;

int dp[MAX_LEN][MAX_SIZE][MAX_SIZE];

int demduongdi(int i, int x, int y, const string& path) {
    if (i == MAX_LEN - 1) {
        return x == MAX_SIZE - 1 && y == 0;
    }

    if (dp[i][x][y] != -1) {
        return dp[i][x][y];
    }

    int cnt = 0;
    if (path[i] == '?') {
        cnt = (demduongdi(i + 1, x, y + 1, path) + demduongdi(i + 1, x, y - 1, path) +
                 demduongdi(i + 1, x + 1, y, path) + demduongdi(i + 1, x - 1, y, path)) % MOD;
    } else if (path[i] == 'D') {
        cnt = demduongdi(i + 1, x + 1, y, path);
    } else if (path[i] == 'U') {
        cnt = demduongdi(i + 1, x - 1, y, path);
    } else if (path[i] == 'L') {
        cnt = demduongdi(i + 1, x, y - 1, path);
    } else {  
        cnt = demduongdi(i + 1, x, y + 1, path);
    }

    dp[i][x][y] = cnt;
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    string st;
    cin >> st;

    memset(dp, -1, sizeof(dp));
    cout << demduongdi(0, 0, 0, st) << endl;

    return 0;
}