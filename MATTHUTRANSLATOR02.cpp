#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> vec;
    int t;

    while(cin >> t) {
        vec.push_back(t);
    }

    for(int i = 1; i <= 25; ++i) {
        string res = "";
        for(int n : vec) {
            if(n + i > 25 && n != 300) 
                res += (char)(n + i - 26 + 'A');
            else if(n != 300)
                res += (char)(n + i + 'A');
            
            if(n == 300) {
            	res += " - ";
            }
        }
        cout << res << endl;
    }

    return 0;
}
