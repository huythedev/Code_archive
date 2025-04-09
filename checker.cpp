#include "testlib_themis_cms.h"
#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

#define NAME "LIS"

int main(int argc, char* argv[]) {
	#ifdef THEMIS
		registerTestlibThemis("NAME.INP", "NAME.OUT"); 
	#else
		registerTestlibCmd(argc, argv);
	#endif

	int res = ans.readInt();
	int contestant_res = ouf.readInt();
	
	if (res != contestant_res) {
		quitf(_wa, "LIS size not match with answer");
	}
	
	// Check increasing subsequence
	vector<int> a(res);
	for (int i = 0; i < res; ++i) {
		a[i] = ouf.readInt();
	}
	
	bool is_increase = true;
	for (int i = 1; i < res; ++i) {
		if (a[i] < a[i - 1]) {
			is_increase = false;
			break;
		}
	}
	
	if (is_increase) {
		quitf(_ok, "");
	}
	else {
		quitf(_wa, "Not an increasing subsequence");
	}
}