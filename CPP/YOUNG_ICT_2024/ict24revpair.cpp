#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if(ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

void sub1(ll N) {
    vector<string> a(N);
    for(ll i = 0; i < N; i++) {
        cin >> a[i];
    }

    ll res = 0;
    for(ll i = 0; i < N - 1; ++i) {
        for(ll j = i + 1; j < N; ++j) {
            string tmp = a[j];
            reverse(tmp.begin(), tmp.end());

            if(a[i] == tmp) {
                res++;
            }
        }
    }

    cout << res;
}

void othersubs(ll N) {
    map<string, ll> freq;
    vector<string> a(N);
    for(ll i = 0; i < N; i++) {
        string x; cin >> x;
        freq[x]++;
        a[i] = x;
    }

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    ll res = 0;
    for(ll i = 0; i < a.size() - 1; i++) {
        for(ll j = i + 1; j < a.size(); j++) {
            string tmp = a[j];
            reverse(tmp.begin(), tmp.end());
            if(a[i] == tmp) {
                res += freq[a[i]] * freq[a[j]];
                break;
            }
        }
    }

    cout << res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    ll N;
    cin >> N;

    if(N <= 1000) {
        sub1(N);
    }
    else {
        othersubs(N);
    }

    return 0;
}