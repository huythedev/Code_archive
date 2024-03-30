#include <bits/stdc++.h>
#define NAME "SEQLEN"
using namespace std;

typedef long long ll;

void docfile() {
	if (ifstream(NAME".inp")) {
        freopen(NAME".inp","r",stdin);
        freopen(NAME".out","w",stdout);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();
    
    ll n;
    cin >> n;

    string s = to_string(n);
    ll tongcs = 0;
    for(ll i = 1; i < s.size(); i++) {
        tongcs += 9 * pow(10, i - 1);
    }

    tongcs += (n - (ll)pow(10, s.size() - 1) + 1) * s.size();

    cout << tongcs;

    return 0;
}