#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string st; getline(cin, st);

	while(st[0] == ' ')
		st.erase(0, 1);

	for(int i = 0; i < (int)st.size(); ++i) {
		if(st[i] == ' ' && st[i + 1] == ' ') {
			st.erase(i + 1, 1);
			i--;
		}
		
			
			
		
	}
	while(st[st.size() - 1] == ' ')
		st.erase(st.size() - 1, 1);
	cout << st;
	return 0;
}
