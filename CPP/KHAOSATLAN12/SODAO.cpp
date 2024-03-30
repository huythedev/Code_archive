#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	string st;
	getline(cin, st);
	reverse(st.begin(), st.end());
	
	cout << stoll(st);
    return 0;
}