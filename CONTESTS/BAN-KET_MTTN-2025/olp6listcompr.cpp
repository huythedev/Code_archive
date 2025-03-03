#include    <bits/stdc++.h>
using namespace std;
#define     ull unsigned long long int
#define     ll long long
#define     str string
const   ll maxN=1e6;
const   ll MOD=1e9+7; 
const   ll inf=LLONG_MAX;
ll gd=0, tmp=0;
vector<int> vi,vj;
string s;
void    doc(){
    #ifndef ONLINE_JUDGE    
    freopen("OLP6LISTCOMPR.INP","r",stdin);
    freopen("OLP6LISTCOMPR.OUT","w",stdout);
    #endif
    getline(cin, s);
}
void    xuly(){
    size_t pos = s.find("i <- [");
    if (pos != string::npos) {
        pos += 5; 
        while (pos < s.size() && s[pos] != ']') {
            if (isdigit(s[pos])) {
                int num = 0;
                while (pos < s.size() && isdigit(s[pos])) {
                    num = num * 10 + (s[pos] - '0');
                    pos++;
                }
                vi.push_back(num);
            } else {
                pos++;
            }
        }
    }

    pos = s.find("j <- [");
    if (pos != string::npos) {
        pos += 5; 
        while (pos < s.size() && s[pos] != ']') {
            if (isdigit(s[pos])) {
                int num = 0;
                while (pos < s.size() && isdigit(s[pos])) {
                    num = num * 10 + (s[pos] - '0');
                    pos++;
                }
                vj.push_back(num);
            } else {
                pos++;
            }
        }
    }
    
    cout << "[";
    bool first = true;
    for (int i : vi) {
        for (int j : vj) {
            if (!first) cout << ", ";
            first = false;
            cout << "(" << (i+10) << "," << j << ")";
        }
    }
    cout << "]";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 
    doc();
    xuly();
}