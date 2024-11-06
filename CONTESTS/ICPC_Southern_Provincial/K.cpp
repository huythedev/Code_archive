#include <bits/stdc++.h>
using namespace std;

#define ln "\n"

typedef long long ll;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main() {
    fastio();

    int matrix_size, number_of_pacmans, number_of_operations;
    cin >> matrix_size >> number_of_pacmans >> number_of_operations;

    vector<array<int, 3>> pacmans(number_of_pacmans); // {u, v, direction}

    for (int i = 0; i < number_of_pacmans; i++) {
        cin >> pacmans[i][0] >> pacmans[i][1] >> pacmans[i][2];
    }

    // Read operations
    for (int i = 0; i < number_of_operations; ++i) {
        char operation; 
        int K; 
        cin >> operation >> K;

        if (operation == 'A') {
            // Calculate effective movement for all pacmans
            for (int j = 0; j < number_of_pacmans; j++) {
                int& u = pacmans[j][0];
                int& v = pacmans[j][1];
                int direction = pacmans[j][2];

                // Adjust movement based on direction
                if (direction == 1) { // North
                    u = (u - K + matrix_size) % matrix_size;
                } else if (direction == 2) { // East
                    v = (v + K) % matrix_size;
                } else if (direction == 3) { // South
                    u = (u + K) % matrix_size;
                } else if (direction == 4) { // West
                    v = (v - K + matrix_size) % matrix_size;
                }
            }
        } else if (operation == 'R') {
            // Optimize rotation using modulo
            for (int j = 0; j < number_of_pacmans; j++) {
                pacmans[j][2] = (pacmans[j][2] - 1 + K) % 4 + 1;
            }
        } else if (operation == 'Z') {
            // Teleport operation
            for (int j = 0; j < number_of_pacmans; j++) {
                pacmans[j][0] = K / matrix_size; // u
                pacmans[j][1] = K % matrix_size; // v
            }
        }
    }

    // Output results
    for (int i = 0; i < number_of_pacmans; i++) {
        cout << pacmans[i][0] << " " << pacmans[i][1] << ln;
    }

    return 0;
}
