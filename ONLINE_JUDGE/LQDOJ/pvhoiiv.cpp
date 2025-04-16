// Author: huythedev (https://huythedev.com)^
#include <bits/stdc++.h>
#define MAX_HERO   10101
#define MAX_TURN   23

int numHero, numTurn, strength[MAX_HERO]; 
pair<char, int> turns; 



sort(strength, strength + numHero, greater<int> ());

#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
const long long INF = (long long)1e18 + 7LL;

long long f[MASK(MAX_TURN) + 1];
f[MASK(numTurn) - 1] = 0;

for (mask : MASK(numTurn) - 2 -> 0) [
	int i = __builtin_popcount(mask);
	
	if (turns[i + 1].first == 'p') { // nếu lượt tiếp theo là pick
		// j = con tướng mạnh nhất chưa sử dụng
		int j = 0;
		while (BIT(mask, j)) j++;
		f[mask] = f[mask | MASK(j)] + strength[j] * (turns[i + 1].sec == 1 ? +1 : -1);
	} else { // nếu lượt tiếp theo là ban
		f[mask] = turns[i + 1].second == 1 ? -INF : INF;
		for (j : 0 -> numTurn - 1) if (!BIT(mask, j)) {
			if (turns[i + 1].second == 1) maximize(f[mask], f[mask | MASK(j)]);
			else minimize(f[mask], f[mask | MASK(j)]);
		}
	}
}

cout << f[0] << endl;
}