#include <iostream>

void docfile() {
    freopen("FINDNAME.INP", "r", stdin);
    freopen("FINDNAME.OUT", "w", stdout);
}

int main() {
    docfile();
    std::string S;
    getline(std::cin, S);

    for (int i = 1; i < S.length(); ++i) {
        if ((S[i - 1] == 'u' || S[i - 1] == 'e' || S[i - 1] == 'o' || S[i - 1] == 'a' || S[i - 1] == 'i' || S[i - 1] == 'y') &&
            S[i] == 'm') {
            S.erase(S.begin() + i);
        }
    }

    std::cout << S;
    return 0;
}
