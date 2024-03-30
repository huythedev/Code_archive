#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool checkfriend(ll a, ll b) {
	ll tmp1 = 0, tmp2 = 0;
	
	for(ll i = 1; i <= sqrt(a); i++){
        if(a % i == 0){
            tmp1 += i; 
            if(i != a / i){
                tmp1 += a / i; 
            }
        }
    }
    
    for(ll i = 1; i <= sqrt(b); i++){
        if(b % i == 0){
            tmp1 += i; 
            if(i != b / i){
                tmp2 += b / i; 
            }
        }
    }
    
    if (tmp1 == b && tmp2 == a) {
    	return true;
    }
    return false;
} 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll M, N;
	cin >> M >> N;
	
	for (ll i = M; i < N - 1; ++i) {
		for (ll j = M + 1; j < N; ++j) {
			if(checkfriend(i, j)) {
				cout << i << " " << j << endl;
			}
		}
	}

    return 0;
}