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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    int n, k; cin >> n >> k;
    string num; cin >> num;

    priority_queue<char> pq;

    for (char c : num) 
        pq.push(c);

    for (int i = 0; i < k; i++) 
        pq.pop();

    string res = "";
    while (!pq.empty()) {
        res += pq.top();
        pq.pop();
    }

    while (!res.empty() && res.back() == '0') 
        res.pop_back(); 
    
    if (res.empty()) 
        cout << "0" << endl; 
    else 
        cout << res << endl;

    return 0;
}