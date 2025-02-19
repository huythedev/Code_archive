#include <bits/stdc++.h>
using namespace std;
    int d=0, b[10]={0}, k;
    string s;
int main()
{
    //freopen ("SOTK.inp","r",stdin);
    //freopen ("SOTK.out","w",stdout);
    getline (cin, s);
    cin >> k;
    for (int i=0; i<s.length (); i++)
    {
        b[s[i]-48]++;
    }
    for (int i=9; i>=0; i--)
    {
        if (b[i]>=1) 
        {
            d++;
        }
        if (d==k) 
        {
            cout <<i;
            break;
        }
    }
    return 0;
}