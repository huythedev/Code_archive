#include <bits/stdc++.h>
using namespace std;

int main() {
    string st;
    cin >> st;
    
    int duc = 0, nhi = 0;
    for(char c : st) {
        if(c == 'D')
           ++duc;
        if(c == 'N')
           ++nhi;
    }
    
    cout << duc << " " << nhi;
    return 0;
}
