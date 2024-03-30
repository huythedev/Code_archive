#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll p, q, r;
    cin >> p >> q >> r;
    if (p > q && p > r) {
    	cout << "AN";
    }
    else if (q > p && q > r) {
    	cout << "VINH";
    }
    else if (r > p && r > q){
    	cout << "QUANG";
    }
    else {
    	cout << "BAU LAI";
    }
    

    return 0;
}