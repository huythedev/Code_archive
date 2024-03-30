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

vector<ll> buildprefixsum(vector<ll> vec) {
	ll vec_length = vec.size();
	vector<ll> res(vec_length + 1);
	
	res[0] = 0;
	for(ll i = 0; i < vec_length; ++i) {
		res[i + 1] = res[i] + vec[i];
	}
	
	return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

	int T;
	cin >> T;
	
	while(T--)  {
		int N;
		cin >> N;
		
		ll resklt = 0, reslt = 0, max_am = LLONG_MIN;
		
		vector<ll> vec1(N);
		for(int i = 0; i < N; ++i) {
			cin >> vec1[i];
			if(vec1[i] > 0) 	
				resklt += vec1[i];
			max_am = max(max_am, vec1[i]);
		}
			
		vector<ll> prefixsum = buildprefixsum(vec1);
		for(ll i = 1; i < prefixsum.size() - 1; ++i) {
			for(ll j = i + 1; j < prefixsum.size(); ++j) {
				reslt = max(reslt, (prefixsum[j] - prefixsum[i - 1]));
			}
		}
		
		if(resklt == 0) {
			cout << max_am << " ";
		}
		else {
			cout << resklt << " ";
		}
		
		cout << reslt << ln;
		
	}	

    return 0;
}