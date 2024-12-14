// Author: Perry (https://perrythedev.com)
// Problem Link: https://codeforces.com/group/G0iFI97YZN/contest/573643/problem/A
#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
#define ln "\n"
#define sz size()

typedef long long ll;
typedef long double ld;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void docfile() {
    if (ifstream(NAME ".INP")) {
        freopen(NAME ".INP", "r", stdin);
        freopen(NAME ".OUT", "w", stdout);
    }
}

void time() {
    cerr << ln << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." 
         << ln;
}

int main() {
    fastio();
    docfile();

    ll n, k; cin >> n >> k;
    // Có n
// học sinh tham gia vào olympic DHBB. Sau khi cuộc thi kết thúc, ban tổ chức tiến hành trao thưởng cho các học sinh này.

// Một số học sinh sẽ nhận được bằng khen, một số thì nhận được giấy chứng nhận tham gia cuộc thi, còn số còn lại thì không nhận được gì. Những học sinh nhận được bằng khen hoặc giấy chứng nhận được gọi là những người đạt giải. Để duy trì tầm vóc danh giá của kỳ thi, ban tổ chức đã đặt ra một số ràng buộc về số lượng giấy chứng nhận và bằng khen. Số lượng giấy chứng nhận phải nhiều gấp k
// lần số lượng bằng khen. Đồng thời, số lượng người đạt giải không được phép vượt quá một nửa tổng số thí sinh (nói cách khác, không vượt quá một nửa của n

// ). Thậm chí, tồn tại trường hợp không có người đạt giải nào.

// Bạn hãy lập trình xác định số lượng người đạt giải tối đa của kỳ thi đáp ứng tất cả các ràng buộc trên. Chương trình của bạn cũng cần phải in ra số lượng học sinh nhận bằng khen, số học sinh nhận được giấy chứng nhận và số lượng học sinh không đạt giải theo phương án bạn tìm được.

//     Input

// Một dòng duy nhất chứa hai số nguyên dương n
// và k (1≤n,k≤1012

// ).
// Output

// In ra ba số nguyên lần lượt là: số học sinh nhận bằng khen, số học sinh nhận giấy chứng nhận và số học sinh không đạt giải trong trường hợp số lượng người đạt giải là lớn nhất có thể.

// Bạn cần lưu ý rằng có thể tồn tại trường hợp không có người đạt giải nào.


    ll a = n / 2;
    ll b = n / 2;
    if (n % 2 == 1) {
        a++;
    }
    if (a % (k + 1) == 0) {
        a++;
        b--;
    }
    cout << a / (k + 1) << " " << b << " " << n - a - b << ln;

    time();
    return 0;
}