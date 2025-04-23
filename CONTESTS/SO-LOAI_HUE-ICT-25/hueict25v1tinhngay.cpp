// Author: huythedev (https://huythedev.com)
// Problem Link: https://coder.husc.edu.vn/problem/hueict25v1tinhngay

#include <bits/stdc++.h>
using namespace std;

#define NAME "hueict25v1tinhngay"
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

const int maxn = 1e5 + 5;
int months_in_year, queries;
ll days_in_year = 0; 
vector<int> days_in_month;
vector<ll> prefix_sum;

ll calc_days(int date, int month, int year) {
    ll res = 0;
    res += (ll)year * days_in_year;
    if (month > 1) res += prefix_sum[month - 1];
    res += date;
    return res;
}

signed main() {
    fastio();
    docfile();

    cin >> months_in_year >> queries;
    days_in_month.resize(months_in_year);
    prefix_sum.resize(months_in_year + 1, 0);
    
    days_in_year = 0; 
    for (int i = 0; i < months_in_year; ++i) {
        cin >> days_in_month[i];
        days_in_year += days_in_month[i];
        prefix_sum[i + 1] = prefix_sum[i] + days_in_month[i];
    }

    while (queries--) {
        int date_in, month_in, year_in, date_out, month_out, year_out;
        cin >> date_in >> month_in >> year_in >> date_out >> month_out >> year_out;

        ll days_in = calc_days(date_in, month_in, year_in);
        ll days_out = calc_days(date_out, month_out, year_out);

        // cout << days_in << ' ' << days_out << ln;

        cout << days_out - days_in + 1 << ln;
    }

    time();
    return 0;
}