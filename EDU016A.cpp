#include <iostream>

void docfile() {
    freopen("COOR.INP", "r", stdin);
    freopen("COOR.OUT", "w", stdout);
}

int main() {
    docfile();
    std::string st;
    getline(std::cin, st);

    int x = 0, y = 0;
    for(char c : st) {
        if(c == 'N') {
            y++;
        }
        else if(c == 'S') {
            y--;
        }
        else if(c == 'E') {
            x++;
        }
        else if(c == 'W') {
            x--;
        }
    }

    std::cout << x << " " << y;
    return 0;
}