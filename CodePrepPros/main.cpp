#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <map>

using namespace std;

int n;
map<long long, bool> memo;

bool can_alice_win(long long alice_mask) {
    if (alice_mask == 0) {
        return false; // Alice has no cards, she loses
    }
    long long all_cards_mask = (1LL << (n + 1)) - 2; // Mask for cards 1 to n
    if (alice_mask == all_cards_mask) {
        return true; // Bob has no cards, Alice wins
    }

    if (memo.count(alice_mask)) {
        return memo[alice_mask];
    }

    vector<int> alice_cards;
    vector<int> bob_cards;
    for (int i = 1; i <= n; ++i) {
        if ((alice_mask >> i) & 1) {
            alice_cards.push_back(i);
        } else {
            bob_cards.push_back(i);
        }
    }

    // Alice tries every card she has
    for (int alice_card : alice_cards) {
        int bob_response = -1;
        
        // Bob's optimal move
        if (alice_card == n) { // Alice plays n
            bool bob_has_1 = false;
            for(int card : bob_cards) if(card == 1) bob_has_1 = true;
            if (bob_has_1) {
                bob_response = 1; // Bob wins with 1
            }
        } else { // Alice plays card < n
            int best_bob_card = -1;
            for (int card : bob_cards) {
                if (card > alice_card) {
                    if (best_bob_card == -1 || card < best_bob_card) {
                        best_bob_card = card;
                    }
                }
            }
            if (best_bob_card != -1) {
                bob_response = best_bob_card; // Bob wins with smallest winning card
            }
        }

        long long next_alice_mask;
        if (bob_response != -1) { // Bob wins the turn
            next_alice_mask = alice_mask & ~(1LL << alice_card);
        } else { // Alice wins the turn
            bob_response = bob_cards[0]; // Bob loses with his weakest card
            next_alice_mask = alice_mask | (1LL << bob_response);
        }

        if (can_alice_win(next_alice_mask)) {
            return memo[alice_mask] = true;
        }
    }

    return memo[alice_mask] = false;
}

void solve() {
    string s;
    cin >> n >> s;

    long long initial_alice_mask = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'A') {
            initial_alice_mask |= (1LL << (i + 1));
        }
    }

    memo.clear();
    if (can_alice_win(initial_alice_mask)) {
        cout << "Alice" << ln;
    } else {
        cout << "Bob" << ln;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
