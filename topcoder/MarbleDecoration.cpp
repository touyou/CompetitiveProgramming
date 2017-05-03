#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
using namespace std;
const double EPS = 1e-9;
typedef long long ll;

class MarbleDecoration {
public:
   int maxLength( int R, int G, int B ) {
		int res;
		vector<int> num(3); num[0]=R; num[1]=G; num[2]=B;
		sort(num.begin(), num.end());
		int max_n=num[2],semi=num[1];
		if (max_n==semi) res=semi*2;
		else res=semi*2+1;
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
			int R                     = 0;
			int G                     = 0;
			int B                     = 0;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = MarbleDecoration().maxLength(R, G, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int R                     = 3;
			int G                     = 0;
			int B                     = 0;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = MarbleDecoration().maxLength(R, G, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int R                     = 5;
			int G                     = 1;
			int B                     = 2;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = MarbleDecoration().maxLength(R, G, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int R                     = 7;
			int G                     = 7;
			int B                     = 4;
			int expected__            = 14;

			clock_t start__           = clock();
			int received__            = MarbleDecoration().maxLength(R, G, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int R                     = 2;
			int G                     = 3;
			int B                     = 5;
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = MarbleDecoration().maxLength(R, G, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			int R                     = 13;
			int G                     = 13;
			int B                     = 13;
			int expected__            = 26;

			clock_t start__           = clock();
			int received__            = MarbleDecoration().maxLength(R, G, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int R                     = ;
			int G                     = ;
			int B                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MarbleDecoration().maxLength(R, G, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int R                     = ;
			int G                     = ;
			int B                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MarbleDecoration().maxLength(R, G, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int R                     = ;
			int G                     = ;
			int B                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MarbleDecoration().maxLength(R, G, B);
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
