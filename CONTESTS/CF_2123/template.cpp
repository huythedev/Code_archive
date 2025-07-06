#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long m;
        int q;
        cin >> n >> m >> q;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> divisors;
        for (int i = 1; (long long)i * i <= m; ++i) {
            if (m % i == 0) {
                divisors.push_back(i);
                if ((long long)i * i != m) {
                    divisors.push_back(m / i);
                }
            }
        }

        map<int, pair<vector<int>, long long>> mp;
        for (int g : divisors) {
            vector<int> rem(n);
            for (int i = 0; i < n; ++i) {
                rem[i] = a[i] % g;
            }
            long long decSum = 0;
            if (n > 1) {
                for (int i = 0; i < n - 1; ++i) {
                    if (rem[i] > rem[i + 1]) {
                        decSum++;
                    }
                }
            }
            mp[g] = {rem, decSum};
        }

        while (q--) {
            int type;
            cin >> type;
            if (type == 1) {
                int i, x;
                cin >> i >> x;
                i--;
                for (auto& it : mp) {
                    int g = it.first;
                    vector<int> rem = it.second.first;
                    long long& decSum = it.second.second;
                    if (n <= 1) continue;
                    int neww = x % g;
                    int oldd = rem[i];
                    if (oldd == neww) continue;

                    if (i > 0) {
                        if (rem[i - 1] > oldd) decSum--;
                        if (rem[i - 1] > neww) decSum++;
                    }
                    if (i < n - 1) {
                        if (oldd > rem[i + 1]) decSum--;
                        if (neww > rem[i + 1]) decSum++;
                    }
                    rem[i] = neww;
                }
                a[i] = x;
            }
            else {
                int k;
                cin >> k;
                int g = gcd((int)k, (int)m);
                const auto& tmp = mp.at(g);
                vector<int> vec = tmp.first;
                long long decSum = tmp.second;
                bool result;
                if (n <= 1) {
                    result = true;
                }
                else {
                    result = (decSum * g + vec[n - 1]) < m;
                }
                if (result) {
                    cout << "YES" << ln;
                }
                else {
                    cout << "NO" << ln;
                }
            }
        }
    }
    return 0;
}