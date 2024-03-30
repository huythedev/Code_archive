#include <iostream>
using namespace std;

int main() {
    string st;
    getline(cin, st);

    for (int i = 1; i <= 25; ++i) {
        string res = "";
        for (char c : st) {
            if (c != ' ') {
                if (isupper(c)) {
                    if ((int)c + i > 90)
                        res += (char)((int)c + i - 26);
                    else
                        res += (char)((int)c + i);
                } else {
                    if ((int)c + i > 122)
                        res += (char)((int)c + i - 26);
                    else
                        res += (char)((int)c + i);
                }
            } else {
                res += " ";
            }
        }

        cout << res << endl;
    }

    return 0;
}
