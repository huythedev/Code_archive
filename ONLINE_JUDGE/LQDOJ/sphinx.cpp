// Author: huythedev (https://huythedev.com)^
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
typedef vector<int> vi;

int perform_experiment(vector<int> E);
vector<int> find_colours(int N, vector<int> X, vector<int> Y);

const int N = 250;
const int M = N * (N - 1) / 2;
int n, m;
int *ej[N], eo[N], ii[M], jj[M];

void append(int i, int j) {
    int o = eo[i]++;
    if (o >= 2 && (o & o - 1) == 0) {
        ej[i] = (int *)realloc(ej[i], o * 2 * sizeof *ej[i]);
    }
    ej[i][o] = j;
}

int cc[N], iii[2][N], nn[2], nn_[2];

void dfs(int i, int c) {
    if (cc[i] != -1) return;
    cc[i] = c;
    iii[c][nn[c]++] = i;
    for (int o = eo[i]; o--; ) {
        int j = ej[i][o];
        dfs(j, c ^ 1);
    }
}

int ds[N];

int find(int i) {
    return ds[i] < 0 ? i : (ds[i] = find(ds[i]));
}

void join(int i, int j) {
    i = find(i);
    j = find(j);
    if (i == j) return;
    if (ds[i] > ds[j]) {
        ds[i] = j;
    } else {
        if (ds[i] == ds[j]) ds[i]--;
        ds[j] = i;
    }
}

int query(vi aa, int a) {
    int k = perform_experiment(aa);
    memset(ds, -1, n * sizeof *ds);
    
    for (int h = 0; h < m; h++) {
        int i = ii[h], j = jj[h];
        if (aa[i] == aa[j]) join(i, j);
    }
    
    for (int i = 0; i < n; i++) {
        if (ds[i] < 0 && (aa[i] == n || aa[i] == a)) k--;
    }
    return k;
}

int ii1[N], n1;
char first[N];

vector<int> find_colours(int n_, vector<int> ii_, vector<int> jj_) {
    n = n_;
    m = ii_.size();
    
    for (int h = 0; h < m; h++) {
        ii[h] = ii_[h];
        jj[h] = jj_[h];
    }
    
    for (int i = 0; i < n; i++) {
        ej[i] = (int *)malloc(2 * sizeof *ej[i]);
    }
    
    for (int h = 0; h < m; h++) {
        int i = ii[h], j = jj[h];
        append(i, j);
        append(j, i);
    }
    
    memset(cc, -1, n * sizeof *cc);
    dfs(0, 0);
    
    vi aa(n, -2);
    
    for (int c = 0; c < 2; c++) {
        vi bb(n, n);
        memset(first, 0, n * sizeof *first);
        n1 = 0;
        
        for (int h = 0, k = 0; h < nn[c]; h++) {
            int i = iii[c][h];
            bb[i] = -1;
            if (query(bb, -2) == k + 1) {
                first[i] = 1;
                ii1[n1++] = i;
                k++;
            } else {
                bb[i] = n;
            }
        }
        
        for (int a = 0; a < n; a++) {
            for (int i = 0; i < n; i++) bb[i] = a;
            for (int h = 0; h < nn[c]; h++) bb[iii[c][h]] = n;
            for (int h = 0; h < n1; h++) bb[ii1[h]] = -1;
            
            int lower = 0, upper = n1;
            int kl = 0, kr = upper - query(bb, a);
            
            while (kl != kr) {
                int upper = n1, kl_ = kr;
                while (upper - lower > 1) {
                    int n_ = (lower + upper) / 2;
                    for (int i = 0; i < n; i++) bb[i] = a;
                    for (int h = 0; h < nn[c]; h++) bb[iii[c][h]] = n;
                    for (int h = 0; h < n_; h++) bb[ii1[h]] = -1;
                    int k = n_ - query(bb, a);
                    if (k == kl) lower = n_;
                    else {
                        upper = n_;
                        kl_ = k;
                    }
                }
                aa[ii1[lower]] = a;
                lower = upper;
                kl = kl_;
            }
        }
        
        for (int h = 0; h < nn[c]; h++) {
            int i_ = iii[c][h];
            if (!first[i_]) {
                n1 = 0;
                for (int o = eo[i_]; o--; ) {
                    int j = ej[i_][o];
                    if (first[j]) ii1[n1++] = j;
                }
                
                int lower = 0, upper = n1;
                while (upper - lower > 1) {
                    int n_ = (lower + upper) / 2;
                    for (int i = 0; i < n; i++) bb[i] = n;
                    bb[i_] = -1;
                    for (int h = 0; h < n_; h++) bb[ii1[h]] = -1;
                    if (query(bb, -2) == n_ + 1) lower = n_;
                    else upper = n_;
                }
                aa[i_] = aa[ii1[lower]];
            }
        }
    }
    
    return aa;
}
