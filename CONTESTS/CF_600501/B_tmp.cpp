#include <bits/stdc++.h>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define int long long
#define FOR(i, l, r) for(int i = (l); i <= (r); i++)
#define FOD(i, r, l) for(int i = (r); i >= (l); i--)
#define fi first
#define se second
const int maxn = 1e6 + 10;
const int mod  = 1e9 + 7;

int rand(int l, int r)
{
    return l + rng() % (r - l + 1);
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int tt;
    cin >> tt;
    while (tt--)
    {
        int p = 0, last = 0;
        vector<int> ans(64, 0);
        //cout << "- " << 0 << endl;
        cin >> last;
        while (true)
        {   
            if (last == 0) break;
            cout << "- " << pow(2,p) << endl;
            int cnt = 0;
            cin >> cnt;
            if (cnt == last - 1) 
            {
                ans[p] = 1;
                p++;
            }else 
            {
                int nxt = p + cnt - last + 1;
                ans[nxt] = 1;
                int num = 0;
                FOR(i, p, nxt - 1) 
                {
                    num += (1 << i);
                }
                cout << "- " << num << endl;
                cin >> cnt;
                p = nxt + 1;
            }
            last = cnt;
        }
        
        int tot = 0;
        FOR(i, 0, 63) 
        {
            tot += (1 << i) * ans[i];
        }
        cout << "! " << tot << endl;
    }
    return 0;
}