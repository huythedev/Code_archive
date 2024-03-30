#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll mins;
	cin >> mins;
	
	cout << (mins / 60) % 24 << " " << mins % 60;
	
    return 0;
}