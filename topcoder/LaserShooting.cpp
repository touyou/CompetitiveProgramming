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

class LaserShooting {
public:
   double numberOfHits( vector <int> x, vector <int> y1, vector <int> y2 ) {

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
	
	static const double MAX_DOUBLE_ERROR = 1e-9; static bool topcoder_fequ(double expected, double result) { if (isnan(expected)) { return isnan(result); } else if (isinf(expected)) { if (expected > 0) { return result > 0 && isinf(result); } else { return result < 0 && isinf(result); } } else if (isnan(result) || isinf(result)) { return false; } else if (fabs(result - expected) < MAX_DOUBLE_ERROR) { return true; } else { double mmin = min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); double mmax = max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); return result > mmin && result < mmax; } }
	double moj_relative_error(double expected, double result) { if (isnan(expected) || isinf(expected) || isnan(result) || isinf(result) || expected == 0) return 0; return fabs(result-expected) / fabs(expected); }
	
	int verify_case(int casenum, const double &expected, const double &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (topcoder_fequ(expected, received)) {
			verdict = "PASSED";
			double rerr = moj_relative_error(expected, received); 
			if (rerr > 0) {
				sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
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
			int x[]                   = {1};
			int y1[]                  = {-1};
			int y2[]                  = {1};
			double expected__         = 0.5;

			clock_t start__           = clock();
			double received__         = LaserShooting().numberOfHits(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y1, y1 + (sizeof y1 / sizeof y1[0])), vector <int>(y2, y2 + (sizeof y2 / sizeof y2[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int x[]                   = {1,2};
			int y1[]                  = {-1,-2};
			int y2[]                  = {1,2};
			double expected__         = 1.0;

			clock_t start__           = clock();
			double received__         = LaserShooting().numberOfHits(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y1, y1 + (sizeof y1 / sizeof y1[0])), vector <int>(y2, y2 + (sizeof y2 / sizeof y2[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int x[]                   = {3,4,7,1};
			int y1[]                  = {1,2,3,4};
			int y2[]                  = {4,3,2,1};
			double expected__         = 0.4623163952488826;

			clock_t start__           = clock();
			double received__         = LaserShooting().numberOfHits(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y1, y1 + (sizeof y1 / sizeof y1[0])), vector <int>(y2, y2 + (sizeof y2 / sizeof y2[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int x[]                   = {134,298,151,942};
			int y1[]                  = {-753,-76,19,568};
			int y2[]                  = {440,689,-39,672};
			double expected__         = 1.444210260641501;

			clock_t start__           = clock();
			double received__         = LaserShooting().numberOfHits(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y1, y1 + (sizeof y1 / sizeof y1[0])), vector <int>(y2, y2 + (sizeof y2 / sizeof y2[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int x[]                   = ;
			int y1[]                  = ;
			int y2[]                  = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = LaserShooting().numberOfHits(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y1, y1 + (sizeof y1 / sizeof y1[0])), vector <int>(y2, y2 + (sizeof y2 / sizeof y2[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int x[]                   = ;
			int y1[]                  = ;
			int y2[]                  = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = LaserShooting().numberOfHits(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y1, y1 + (sizeof y1 / sizeof y1[0])), vector <int>(y2, y2 + (sizeof y2 / sizeof y2[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int x[]                   = ;
			int y1[]                  = ;
			int y2[]                  = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = LaserShooting().numberOfHits(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y1, y1 + (sizeof y1 / sizeof y1[0])), vector <int>(y2, y2 + (sizeof y2 / sizeof y2[0])));
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
