#include <bits/stdc++.h>
using namespace std;

#define int long long

const int maxn = 1e5 + 4;

unordered_map <int , int> cnt;
int a[maxn] , x[maxn];
int n;

void nhap()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if(ifstream("Bai_4-8.INP"))
    {
        freopen("Bai_4-8.INP" , "r" , stdin);
        freopen("Bai_4-8.OUT" , "w" , stdout);
    }
    cin >> n;
    for (int i = 1 ; i <= n ; i ++)
        cin >> a[i];
}

void ans()
{
    int t = 0;
    for (int i = 1 ; i <= n;  i ++)
        if (x[i])
            t += a[i];
        cnt[t] = 1;
}

void back_tracking(int k)
{
    for (int i = 0 ; i <= 1 ; i ++)
    {
        x[k] = i;
        if (k == n)
            ans();
        else
            back_tracking(k + 1);
    }
}

signed main()
{
    nhap();
    back_tracking(1);
    int m = 1;
    while (cnt[m])
    {
        m ++;
    }
    cout << m;
}
