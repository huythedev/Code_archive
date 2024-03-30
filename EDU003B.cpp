#include <iostream>
#include <set>

int main() {
    std::string st;
    getline(std::cin, st);

    int tmp = 0;
    for(int i = 0; i < st.length(); ++i) {
        if(st[i] == ' ') {
            st.erase(st.begin() + i);
            i--;
            ++tmp;
        }
    }

    int freq[123] = {0};
    for (char c : st) {
        freq[c]++;
    }

    int res = 0;
    if(tmp >= 2) {
        res++;
    }
    for (int i = 65; i <= 90; ++i) {
        if (freq[i] >= 2) {
            res++;
        }
    }
    for (int i = 97; i <= 122; ++i) {
        if (freq[i] >= 2) {
            res++;
        }
    }

    std::cout << res;
    return 0;
}
