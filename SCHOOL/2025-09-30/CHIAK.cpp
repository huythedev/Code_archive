#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

// Hash an toàn cho unordered_map (tránh đụng độ gây TLE)
struct SafeHash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15ULL;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
        x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 n, k;
    if (!(cin >> n >> k)) return 0;

    // Ngưỡng dùng mảng đếm: 2e6 (≈16MB) — nhanh nhất khi k nhỏ
    const i64 THRESH = 2000000;

    i64 ans = 0;
    i64 pref = 0;

    if (k <= THRESH) {
        vector<i64> cnt((size_t)k, 0);
        cnt[0] = 1; // tiền tố rỗng
        for (i64 i = 0; i < n; ++i) {
            i64 x; cin >> x;
            // chuẩn hoá về [0..k-1]
            pref = (pref + x) % k;
            if (pref < 0) pref += k;
            ans += cnt[(size_t)pref];
            ++cnt[(size_t)pref];
        }
    } else {
        unordered_map<uint64_t, i64, SafeHash> cnt;
        // dự phòng đủ lớn để hạn chế rehash
        cnt.reserve((size_t)min<i64>(n * 2 + 5, 4000000));
        cnt[0] = 1; // tiền tố rỗng
        for (i64 i = 0; i < n; ++i) {
            i64 x; cin >> x;
            i64 r = (pref + x) % k;
            if (r < 0) r += k;
            pref = r;
            auto it = cnt.find((uint64_t)r);
            if (it != cnt.end()) {
                ans += it->second;
                ++(it->second);
            } else {
                cnt[(uint64_t)r] = 1;
            }
        }
    }

    cout << ans;
    return 0;
}
