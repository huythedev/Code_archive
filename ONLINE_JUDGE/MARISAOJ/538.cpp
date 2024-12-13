// Author: Perry (https://perrythedev.com)
// Problem Link: https://marisaoj.com/problem/538
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

    int n; cin >> n;
    vector<int> a(n);
    int last_negative_index = -1;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] < 0)
            last_negative_index = i;
    }
    vector<int> positive_numbers;
    cout << last_negative_index << ln;
    for(int i = 0; i <= last_negative_index; i++) {
        if(a[i] < 0)
            cout << a[i] << ' ';
        else 
            positive_numbers.push_back(a[i]);
    }
    reverse(positive_numbers.begin(), positive_numbers.end());
    for(int i = last_negative_index + 1; i < n; i++)
        cout << a[i] << ' ';
    for(int i : positive_numbers)
        cout << i << ' ';

    time();
    return 0;
}