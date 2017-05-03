#include <string>
#include <algorithm>
#include <cfloat>
#include <climits>
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
typedef pair<int, int> P;
typedef vector<int> vi;
typedef long long ll;
#define PI 3.14159265358979

class MinDifference {
public:
    int closestElements( int A0, int X, int Y, int M, int n ) {
	  vector<int> a(1, A0);
	  for (int i=1; i<n; i++) {
		a.push_back((a[i-1]*X+Y)%M);
	  }
	  sort(a.begin(), a.end());
	  int res = 10001;
	  for (int i=1; i<n; i++) {
		res = min(res, a[i]-a[i-1]);
	  }
	  return res;
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
	
	int verify_case(int casenum, const int &expected, const int &received, clock_t elapsed) { 
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
			int A0                    = 3;
			int X                     = 7;
			int Y                     = 1;
			int M                     = 101;
			int n                     = 5;
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = MinDifference().closestElements(A0, X, Y, M, n);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int A0                    = 3;
			int X                     = 9;
			int Y                     = 8;
			int M                     = 32;
			int n                     = 8;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = MinDifference().closestElements(A0, X, Y, M, n);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int A0                    = 67;
			int X                     = 13;
			int Y                     = 17;
			int M                     = 4003;
			int n                     = 23;
			int expected__            = 14;

			clock_t start__           = clock();
			int received__            = MinDifference().closestElements(A0, X, Y, M, n);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int A0                    = 1;
			int X                     = 1221;
			int Y                     = 3553;
			int M                     = 9889;
			int n                     = 11;
			int expected__            = 275;

			clock_t start__           = clock();
			int received__            = MinDifference().closestElements(A0, X, Y, M, n);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int A0                    = 1;
			int X                     = 1;
			int Y                     = 1;
			int M                     = 2;
			int n                     = 10000;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = MinDifference().closestElements(A0, X, Y, M, n);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			int A0                    = 1567;
			int X                     = 5003;
			int Y                     = 9661;
			int M                     = 8929;
			int n                     = 43;
			int expected__            = 14;

			clock_t start__           = clock();
			int received__            = MinDifference().closestElements(A0, X, Y, M, n);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int A0                    = ;
			int X                     = ;
			int Y                     = ;
			int M                     = ;
			int n                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MinDifference().closestElements(A0, X, Y, M, n);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int A0                    = ;
			int X                     = ;
			int Y                     = ;
			int M                     = ;
			int n                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MinDifference().closestElements(A0, X, Y, M, n);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int A0                    = ;
			int X                     = ;
			int Y                     = ;
			int M                     = ;
			int n                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MinDifference().closestElements(A0, X, Y, M, n);
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
