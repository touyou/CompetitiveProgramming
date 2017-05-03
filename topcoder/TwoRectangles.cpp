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

class TwoRectangles {
public:
   string describeIntersection( vector <int> A, vector <int> B ) {
        int lx=max(A[0],B[0]);
        int ly=max(A[1],B[1]);
        int rx=min(A[2],B[2]);
        int ry=min(A[3],B[3]);
        if (lx==rx&&ly==ry) return "point";
        if (lx<rx&&ly<ry) return "rectangle";
        if (lx>rx||ly>ry) return "none";
        return "segment";
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
	
	int verify_case(int casenum, const string &expected, const string &received, clock_t elapsed) { 
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
			cerr << "    Expected: \"" << expected << "\"" << endl; 
			cerr << "    Received: \"" << received << "\"" << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum) {
		switch (casenum) {
		case 0: {
			int A[]                   = {0,0,3,2};
			int B[]                   = {1,1,5,3};
			string expected__         = "rectangle";

			clock_t start__           = clock();
			string received__         = TwoRectangles().describeIntersection(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int A[]                   = {0,0,5,3};
			int B[]                   = {1,2,2,3};
			string expected__         = "rectangle";

			clock_t start__           = clock();
			string received__         = TwoRectangles().describeIntersection(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int A[]                   = {1,1,6,2};
			int B[]                   = {3,2,5,4};
			string expected__         = "segment";

			clock_t start__           = clock();
			string received__         = TwoRectangles().describeIntersection(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int A[]                   = {0,1,2,3};
			int B[]                   = {2,0,5,2};
			string expected__         = "segment";

			clock_t start__           = clock();
			string received__         = TwoRectangles().describeIntersection(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int A[]                   = {0,0,1,1};
			int B[]                   = {1,1,5,2};
			string expected__         = "point";

			clock_t start__           = clock();
			string received__         = TwoRectangles().describeIntersection(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			int A[]                   = {1,1,2,2};
			int B[]                   = {3,1,4,2};
			string expected__         = "none";

			clock_t start__           = clock();
			string received__         = TwoRectangles().describeIntersection(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int A[]                   = ;
			int B[]                   = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = TwoRectangles().describeIntersection(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int A[]                   = ;
			int B[]                   = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = TwoRectangles().describeIntersection(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int A[]                   = ;
			int B[]                   = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = TwoRectangles().describeIntersection(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
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
