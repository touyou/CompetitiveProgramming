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

class CountExpressions {
public:
    int calcExpressions( int x, int y, int val ) {
	  int num[4] = {x, x, y, y};
	  sort(num, num+4);
	  int cnt = 0;
	  do {
		for (int i=0; i<3; i++) {
		  for (int j=0; j<3; j++) {
			for (int k=0; k<3; k++) {
			  int r=num[0];
			  if (i==0) r+=num[1];
			  else if (i==1) r-=num[1];
			  else r*=num[1];
			  if (j==0) r+=num[2];
			  else if (j==1) r-=num[2];
			  else r*=num[2];
			  if (k==0) r+=num[3];
			  else if (k==1) r-=num[3];
			  else r*=num[3];
			  if (r==val) {
				cnt++;
			  }
			}
		  }
		}
	  } while(next_permutation(num, num+4));
	  return cnt;
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
			int x                     = 7;
			int y                     = 8;
			int val                   = 16;
			int expected__            = 9;

			clock_t start__           = clock();
			int received__            = CountExpressions().calcExpressions(x, y, val);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int x                     = 3;
			int y                     = 5;
			int val                   = 7;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = CountExpressions().calcExpressions(x, y, val);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int x                     = 99;
			int y                     = 100;
			int val                   = 98010000;
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = CountExpressions().calcExpressions(x, y, val);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int x                     = -99;
			int y                     = 42;
			int val                   = -1764;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = CountExpressions().calcExpressions(x, y, val);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int x                     = 100;
			int y                     = -100;
			int val                   = -100000000;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = CountExpressions().calcExpressions(x, y, val);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			int x                     = 1;
			int y                     = 2;
			int val                   = 5;
			int expected__            = 17;

			clock_t start__           = clock();
			int received__            = CountExpressions().calcExpressions(x, y, val);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int x                     = ;
			int y                     = ;
			int val                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CountExpressions().calcExpressions(x, y, val);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int x                     = ;
			int y                     = ;
			int val                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CountExpressions().calcExpressions(x, y, val);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int x                     = ;
			int y                     = ;
			int val                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CountExpressions().calcExpressions(x, y, val);
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
