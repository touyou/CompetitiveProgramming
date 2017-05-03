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

class ReversedSum {
public:
   int toInt(string st) {
	   stringstream ss;
	   ss.str(st);
	   int res;
	   ss >> res;
	   return res;
   }
   string toStr(int num) {
	   stringstream ss;
	   ss << num;
	   return ss.str();
   }
	int getReversedSum( int x, int y ) {
		string revx, revy, revsum;
		revx = toStr(x);
		revy = toStr(y);
		reverse(revx.begin(), revx.end());
		reverse(revy.begin(), revy.end());
		int rx, ry;
		rx = toInt(revx);
		ry = toInt(revy);
		revsum = toStr(rx + ry);
		reverse(revsum.begin(), revsum.end());
		return toInt(revsum);
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
			int x                     = 123;
			int y                     = 100;
			int expected__            = 223;

			clock_t start__           = clock();
			int received__            = ReversedSum().getReversedSum(x, y);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int x                     = 111;
			int y                     = 111;
			int expected__            = 222;

			clock_t start__           = clock();
			int received__            = ReversedSum().getReversedSum(x, y);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int x                     = 5;
			int y                     = 5;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = ReversedSum().getReversedSum(x, y);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int x                     = 1000;
			int y                     = 1;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = ReversedSum().getReversedSum(x, y);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int x                     = 456;
			int y                     = 789;
			int expected__            = 1461;

			clock_t start__           = clock();
			int received__            = ReversedSum().getReversedSum(x, y);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int x                     = ;
			int y                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ReversedSum().getReversedSum(x, y);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int x                     = ;
			int y                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ReversedSum().getReversedSum(x, y);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int x                     = ;
			int y                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ReversedSum().getReversedSum(x, y);
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
