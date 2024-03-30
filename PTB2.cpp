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

ll GCD(ll a, ll b) {
    while(b) {
        ll tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();
    
    ll a, b, c;
    cin >> a >> b >> c;

    ld delta = b * b - 4 * a * c;

    if (delta < 0) {
        std::cout << "PT vo nghiem";
    } 
    else if (delta == 0) {
        cout << -b << "/" << (2 * a);
    } 
    else {
    	cout << (-b + sqrt(delta)) / (2 * a) << " " << ((-b - sqrt(delta)) / (2 * a)); 
    }

    return 0;
}
