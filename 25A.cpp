#include <iostream>

int main() {
    int t;
    std::cin >> t;

    int TLE = 0, VNOI = 0, CF = 0;
    while(t--) {
        std::string st;
        std::cin >> st;

        int T = 0, C = 0, V = 0;
        for(char c : st) {
            if(c == 'T') {
                T++;
            }
            else if(c == 'C') {
                C++;
            }
            else if(c == 'V') {
                V++;
            }
        }
        if(T > C && T > V) {
            TLE++;
        }
        else if(C > T && C > V) {
            CF++;
        }
        else if(V > T && V > C) {
            VNOI++;
        }
        else if(T == C && T == V) {
            TLE++;
        }
        else {
            if(T == C || T == V) {
                TLE++;
            }
            else if(V == C) {
                VNOI++;
            }
            else {
                CF++;
            }
        }
    }

    std::cout << TLE << " " << VNOI << " " << CF;
    return 0;
}