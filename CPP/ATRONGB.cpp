#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	string B, A;
    cin >> B;
    cin >> A;
    ll res = 0;
    for (ll i = 0; i < B.length();) {
        if (B.substr(i, A.length()) == A) {
            ++res;
            i += A.length();
        }
        else {
            ++i;
        }
    }
    
    cout << res;
    return 0;
}