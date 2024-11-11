#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
const int MAXN = 16;

int n;
vector<int> colors;
ll dp[MAXN][1 << MAXN];
vector<int> positions[MAXN]; // Lưu các vị trí của mỗi màu

// Kiểm tra xem việc đặt màu color vào vị trí pos có hợp lệ không
bool isValid(int pos, int color, int mask) {
    // Kiểm tra nếu pos > 0, màu bên trái
    if (pos > 0) {
        int prevPos = -1;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                prevPos = i;
            }
        }
        if (prevPos != -1 && colors[prevPos] == color) return false;
    }
    return true;
}

// Hàm quy hoạch động
ll solve(int pos, int mask) {
    // Nếu đã đặt hết n vị trí
    if (pos == n) return 1;
    
    // Nếu đã tính trạng thái này
    if (dp[pos][mask] != -1) return dp[pos][mask];
    
    ll result = 0;
    // Thử đặt từng màu vào vị trí hiện tại
    for (int i = 0; i < n; i++) {
        if (!(mask & (1 << i))) { // Nếu chưa sử dụng vị trí i
            if (isValid(pos, colors[i], mask)) {
                result = (result + solve(pos + 1, mask | (1 << i))) % MOD;
            }
        }
    }
    
    return dp[pos][mask] = result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    // Đọc input
    cin >> n;
    colors.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> colors[i];
    }
    
    // Khởi tạo mảng dp
    memset(dp, -1, sizeof(dp));
    
    // Tính kết quả
    ll result = solve(0, 0);
    
    // In kết quả
    cout << result << endl;
    
    return 0;
}