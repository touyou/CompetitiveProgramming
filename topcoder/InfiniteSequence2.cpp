#include <string>
#include <algorithm>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define EPS 1e-9
#define PI 3.14159265358979

class InfiniteSequence2 {
public:
    long long calc( long long n, int p, int q, int x, int y ) {
        ll div1=p-x, div2=q-y;
        ll dp[max((n+div1-1)/div1,(n+div2-1)/div2)];
    }
};

// BEGIN CUT HERE
namespace moj_harness {
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			cerr << "No test cases run." << endl;
		} else if (correct < total) {
			cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
		} else {
			cerr << "All " << total << " tests passed!" << endl;
		}
	}
	
	int verify_case(int casenum, const long long &expected, const long long &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		cerr << verdict;
		if (!info.empty()) {
			cerr << " (";
			for (int i=0; i<(int)info.size(); ++i) {
				if (i > 0) cerr << ", ";
				cerr << info[i];
			}
			cerr << ")";
		}
		cerr << endl;
		
		if (verdict == "FAILED") {
			cerr << "    Expected: " << expected << endl; 
			cerr << "    Received: " << received << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum) {
		switch (casenum) {
		case 0: {
			long long n               = 10000000;
			int p                     = 2;
			int q                     = 3;
			int x                     = 10000000;
			int y                     = 10000000;
			long long expected__      = 2;

			clock_t start__           = clock();
			long long received__      = InfiniteSequence2().calc(n, p, q, x, y);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			long long n               = 12;
			int p                     = 2;
			int q                     = 3;
			int x                     = 1;
			int y                     = 0;
			long long expected__      = 8;

			clock_t start__           = clock();
			long long received__      = InfiniteSequence2().calc(n, p, q, x, y);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			long long n               = 0;
			int p                     = 2;
			int q                     = 2;
			int x                     = 0;
			int y                     = 0;
			long long expected__      = 1;

			clock_t start__           = clock();
			long long received__      = InfiniteSequence2().calc(n, p, q, x, y);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			long long n               = 123;
			int p                     = 45;
			int q                     = 67;
			int x                     = 8;
			int y                     = 9;
			long long expected__      = 2;

			clock_t start__           = clock();
			long long received__      = InfiniteSequence2().calc(n, p, q, x, y);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			long long n               = ;
			int p                     = ;
			int q                     = ;
			int x                     = ;
			int y                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = InfiniteSequence2().calc(n, p, q, x, y);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			long long n               = ;
			int p                     = ;
			int q                     = ;
			int x                     = ;
			int y                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = InfiniteSequence2().calc(n, p, q, x, y);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			long long n               = ;
			int p                     = ;
			int q                     = ;
			int x                     = ;
			int y                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = InfiniteSequence2().calc(n, p, q, x, y);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}
 

int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(atoi(argv[i]));
	}
}
// END CUT HERE
