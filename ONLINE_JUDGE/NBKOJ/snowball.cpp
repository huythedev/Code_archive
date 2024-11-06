#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if(ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

const ll MAX_COORD = 1e13 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    ll N, T;
    cin >> N >> T;
    vector<ll> positions(N);
    for (ll i = 0; i < N; i++) {
        cin >> positions[i];
    }
    vector<ll> winds(T);
    for (ll i = 0; i < T; i++) {
        cin >> winds[i];
    }

    vector<ll> weights(N, 0);
    vector<bool> snow_cover(2 * MAX_COORD + 1, true);

    for (ll wind : winds) {
        vector<ll> new_positions;
        for (ll i = 0; i < N; i++) {
            ll pos = positions[i];
            ll new_pos = pos + wind;
            ll weight_gain = 0;
            if (wind > 0) {
                for (ll j = pos; j < new_pos; j++) {
                    if (snow_cover[j + MAX_COORD]) {
                        weight_gain++;
                        snow_cover[j + MAX_COORD] = false;
                    }
                }
            } else {
                for (ll j = new_pos; j < pos; j++) {
                    if (snow_cover[j + MAX_COORD]) {
                        weight_gain++;
                        snow_cover[j + MAX_COORD] = false;
                    }
                }
            }
            weights[i] += weight_gain;
            new_positions.push_back(new_pos);
        }
        positions = new_positions;
    }

    for (ll weight : weights) {
        cout << weight << '\n';
    }

    return 0;
}