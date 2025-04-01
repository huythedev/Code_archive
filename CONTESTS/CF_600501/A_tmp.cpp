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

int ask(int x)
{
    cout << "? " << x << endl;
    int res;
    cin >> res;
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<int> p(n + 2, -1);
    p[0] = p[n + 1] = 1e18;
    
    int l = 1, r = n;
    while (l <= r) 
    {
        int mid =  (l + r) / 2;
        if (p[mid] == -1) p[mid] = ask(mid);
        if (p[mid - 1] == -1) p[mid - 1] = ask(mid - 1);    
        if (p[mid + 1] == -1) p[mid + 1] = ask(mid + 1);

        if (p[mid] < p[mid - 1] && p[mid] < p[mid + 1]) 
        {
            cout << "! " << mid << endl;
            return 0;
        }

        if (p[mid] > p[mid - 1]) 
        {
            r = mid - 1;
        } else 
        {
            l = mid + 1;
        }
    }
    
    return 0;
}