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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        if(t % 2 == 0) {
            a[i] = 0;
        }
        else {
            a[i] = 1;
        }
    }
    

    map<int, int> cnt;
    int prefix_sum = 0, res = 0;

    for(int i = 0; i < n; ++i) {
        prefix_sum += a[i];
        
        if(prefix_sum == m)
            res++;
            
        if(cnt.find(prefix_sum - m) != cnt.end())
            res += cnt[prefix_sum - m];

        cnt[prefix_sum]++;
    }

    cout << res;

    return 0;
}
