#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>

#define NAME "NAME"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
if(std::ifstream(NAME".inp")) {
std::freopen(NAME".inp", "r", stdin);
std::freopen(NAME".out", "w", stdout);
}
}

int main() {
std::ios_base::sync_with_stdio(false);
std::cin.tie(NULL); std::cout.tie(NULL);

docfile();

ll N, K;
std::cin >> N >> K;

if(K - N >= N) {
std::cout << 0;
}
else {
ll ans = 0;
for(ll i = N; i >= 1; i--) {
if(K - i >= 1 && K - i <= N) {
ans++;
}
}
std::cout << ans;
}

return 0;
}