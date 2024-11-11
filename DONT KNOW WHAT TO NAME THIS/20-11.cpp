#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const int MAXC = 105;

int n;
int color[MAXN];
int cnt[MAXC]; // Đếm số lượng mỗi màu
ll dp[MAXN][MAXC]; // dp[i][c]: số cách sắp xếp i phần tử đầu, kết thúc bằng màu c

ll solve() {
    // Đếm số lượng mỗi màu
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < n; i++) {
        cnt[color[i]]++;
    }
    
    // Khởi tạo cho vị trí đầu tiên
    memset(dp, 0, sizeof(dp));
    for(int c = 1; c <= 100; c++) {
        if(cnt[c] > 0) {
            dp[1][c] = cnt[c];
        }
    }
    
    // QHĐ cho các vị trí tiếp theo
    for(int i = 2; i <= n; i++) {
        for(int last = 1; last <= 100; last++) {
            if(dp[i-1][last] == 0) continue;
            
            // Thử đặt các màu khác màu last
            for(int c = 1; c <= 100; c++) {
                if(c != last && cnt[c] > 0) {
                    // Số cách = số cách đến i-1 * số lượng màu c còn lại
                    int remaining = cnt[c];
                    if(c == color[i-2]) remaining--; // Nếu đã dùng màu này ở vị trí trước
                    if(remaining > 0) {
                        dp[i][c] = (dp[i][c] + dp[i-1][last] * remaining) % MOD;
                    }
                }
            }
        }
    }
    
    // Tổng hợp kết quả
    ll result = 0;
    for(int c = 1; c <= 100; c++) {
        result = (result + dp[n][c]) % MOD;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> color[i];
    }
    
    cout << solve() << endl;
    return 0;
}