#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(nullptr));
    int maximizeReduce = rand() % 9 + 1;

    cout << "Don vi giam toi da: " << maximizeReduce << "\n";

    cout << "Nhap mot so bat ky nho hon 100 va lon hon 15: ";
    int n;
    while(true) {
        cin >> n;
        if(n > 15 && n < 100) break;
        cout << "Nhap lai: ";
    }

    while(n != 0) {
        int t; cin >> t;
        while(t > n) {
            cout << "Nhap lai: ";
            cin >> t;
        }

        n -= t;

        if(n - maximizeReduce < 0) {
            cout << abs(n - maximizeReduce) << "\n";
            cout << "Ban da thua!\n";
        }
        else {
            
        }
    }

    return 0;
}
