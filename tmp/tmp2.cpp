#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 998244353LL; // đổi nếu đề dùng modulo khác

struct Query {
    int l, r, x;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<Query> queries(m);
        for (int i = 0; i < m; ++i) {
            cin >> queries[i].l >> queries[i].r >> queries[i].x;
        }

        // 1) Tính vec2[i] bằng sweep + min-heap theo (x, r)
        vector<vector<pair<int,int>>> vec(n + 2);
        for (auto &q : queries) vec[q.l].push_back({q.x, q.r});
        vector<int> vec2(n + 1, k);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // (x, r), min x trên top
        for (int i = 1; i <= n; ++i) {
            for (auto &vec3 : vec[i]) pq.push(vec3);
            while (!pq.empty() && pq.top().second < i) pq.pop();
            if (!pq.empty()) vec2[i] = pq.top().first; // min x của các khoảng phủ i
            else vec2[i] = k;
        }

        // Gom điều kiện theo x
        unordered_map<int, vector<pair<int,int>>> mp;
        mp.reserve(m * 2 + 7);
        for (auto &q : queries) mp[q.x].push_back({q.l, q.r});

        // Gom vị trí theo vec2 value
        map<int, vector<int>> pos; // dùng map để duyệt theo khóa có thứ tự (không bắt buộc)
        for (int i = 1; i <= n; ++i) pos[vec2[i]].push_back(i);

        // Nếu có x xuất hiện trong điều kiện nhưng không có vị trí vec2==x -> vô nghiệm
        bool impossible = false;
        for (auto &kv : mp) {
            int x = kv.first;
            if (!pos.count(x)) { // không có vị trí có vec2==x
                impossible = true; break;
            }
        }
        if (impossible) {
            cout << 0 << "\n";
            continue;
        }

        auto modpow = [&](ll a, ll e) {
            ll r = 1 % MOD;
            a %= MOD;
            while (e > 0) {
                if (e & 1) r = (r * a) % MOD;
                a = (a * a) % MOD;
                e >>= 1;
            }
            return r;
        };

        ll ans = 1;

        // Duyệt từng giá trị v xuất hiện trong vec2
        for (auto &pk : pos) {
            int v = pk.first; // giá trị vec2
            const vector<int> &vec3 = pk.second; // danh sách index i có vec2[i]==v
            int t = (int)vec3.size();

            // L[b] (1..t): max a của mọi điều kiện (sau khi ánh xạ) kết thúc tại b
            vector<int> L(t + 1, 0);

            if (mp.count(v)) {
                for (auto [l, r] : mp[v]) {
                    // tìm đoạn [a,b] trong vec3 nằm trong [l,r]
                    int a_idx = int(lower_bound(vec3.begin(), vec3.end(), l) - vec3.begin()) + 1; // 1-based
                    int b_idx = int(upper_bound(vec3.begin(), vec3.end(), r) - vec3.begin());     // 1-based
                    if (a_idx > b_idx) { // không có vị trí vec2==v trong [l,r] -> vô nghiệm
                        impossible = true; break;
                    }
                    L[b_idx] = max(L[b_idx], a_idx);
                }
                if (impossible) break;
            }

            // DP với bảng chữ cái: v lựa chọn, trong đó 1 lựa chọn "đặc biệt" (=v),
            // còn lại z = v-1 lựa chọn "< v"
            ll s = v % MOD;           // tổng lựa chọn tại 1 vị trí
            ll z = (v - 1 + MOD) % MOD; // số lựa chọn "< v" (v>=1)
            vector<ll> powz(t + 2, 1);
            for (int i = 1; i <= t + 1; ++i) powz[i] = (powz[i-1] * z) % MOD;

            vector<ll> dp(t + 1, 0);
            dp[0] = 1;
            for (int i = 1; i <= t; ++i) {
                ll cur = (s * dp[i-1]) % MOD; // thêm 1 vị trí: v cách
                if (L[i] > 0) {
                    int len = i - L[i] + 1;
                    ll bad = (powz[len] * dp[L[i]-1]) % MOD; // tất cả "<v" trong cửa sổ
                    cur = (cur - bad) % MOD;
                    if (cur < 0) cur += MOD;
                }
                dp[i] = cur;
            }
            ans = (ans * dp[t]) % MOD;
            if (ans == 0) break;
        }

        if (impossible) cout << 0 << "\n";
        else cout << (ans % MOD + MOD) % MOD << "\n";
    }

    return 0;
}
