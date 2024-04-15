#include <bits/stdc++.h>
using namespace std;

#define NAME "SOTK"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if(ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    string N; cin >> N;
    int K; cin >> K;

    set<int> nums;
    for(char c : N) 
        nums.insert(c - '0');

    vector<int> vec;
    for(int x : nums) 
        vec.push_back(x);

    sort(vec.rbegin(), vec.rend());
    
    cout << vec[K - 1];

    return 0;
}