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

bool isPrime(int n) {
    if(n < 2) return false;
    for(int i = 2; i <= sqrt(n); i++) 
        if(n % i == 0) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    string N; getline(cin, N);
    set<int> s;
    for(char c : N) 
        s.insert(c - '0');
    vector<int> vec;
    for(int i : s) 
        vec.push_back(i);

    int Q; cin >> Q;
    if(Q > vec.size()) {
        cout << -1;
        return 0;
    }
    
    sort(vec.begin(), vec.end());
    cout << vec[Q - 1] << " ";
    if(isPrime(vec[Q - 1]))
        cout << "Yes";
    else 
        cout << "No";

    return 0;
}