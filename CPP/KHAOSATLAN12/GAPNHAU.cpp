#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll d, v1, v2;
	cin >> d >> v1 >> v2;
	
	cout << fixed << setprecision(5) << (float)d / (v1 + v2);
    return 0;
}