// thor: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "CHOSEBOOK"
#define ln "\n"
#define sz size()

typedef long long ll;
typedef long double ld;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void docfile() {
    if (ifstream(NAME ".INP")) {
        freopen(NAME ".INP", "r", stdin);
        freopen(NAME ".OUT", "w", stdout);
    }
}

void time() {
    cerr << ln << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." 
         << ln;
}

#define BUF_SIZE (1 << 20)

char buf[BUF_SIZE];
size_t buf_pos = 0;
size_t buf_end = 0;

inline char read_char() {
    if (buf_pos >= buf_end) {
        buf_end = fread(buf, 1, BUF_SIZE, stdin);
        buf_pos = 0;
        if (buf_end == 0) return EOF;
    }
    return buf[buf_pos++];
}

inline long long read_ll() {
    char c;
    while ((c = read_char()) < '0' || c > '9') {}
    long long res = c - '0';
    while ((c = read_char()) >= '0' && c <= '9') {
        res = res * 10 + (c - '0');
    }
    return res;
}

void radix_sort(uint64_t* array, int n) {
    const int bits_per_pass = 8;
    const int num_passes = 64 / bits_per_pass;

    uint64_t* output = new uint64_t[n];
    uint64_t* src = array;
    uint64_t* dst = output;

    for (int pass = 0; pass < num_passes; pass++) {
        int shift = pass * bits_per_pass;
        int count[256] = {0};

        for (int i = 0; i < n; i++) {
            uint64_t digit = (src[i] >> shift) & 0xFF;
            count[digit]++;
        }

        int total = 0;
        for (int i = 0; i < 256; i++) {
            int old_count = count[i];
            count[i] = total;
            total += old_count;
        }

        for (int i = 0; i < n; i++) {
            uint64_t digit = (src[i] >> shift) & 0xFF;
            dst[count[digit]++] = src[i];
        }

        swap(src, dst);
    }

    if (src == output) {
        memcpy(array, output, n * sizeof(uint64_t));
    }

    delete[] output;
}

signed main() {
    fastio();
    docfile();

    int N = read_ll();
    int M = read_ll();

    vector<ll> a(N);
    for (int i = 0; i < N; ++i) {
        a[i] = read_ll();
    }

    radix_sort(reinterpret_cast<uint64_t*>(a.data()), N);

    ll min_diff = LLONG_MAX;
    for (int i = 0; i <= N - M; ++i) {
        min_diff = min(min_diff, a[i + M - 1] - a[i]);
    }

    cout << min_diff << ln;

    time();
    return 0;
}
