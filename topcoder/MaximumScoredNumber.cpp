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

class MaximumScoredNumber {
public:
	int calc(int num) {
		int res=0;
		for (int i=0; i*i<=num; i++) for (int j=i; j*j<=num; j++) {
			if (i*i+j*j==num) res++;
		}
		return res;
	}
	int getNumber( int lowerBound, int upperBound ) {
		int res=-1, temp=-1;
		for (int i=lowerBound; i<=upperBound; i++) {
			int n=calc(i);
//			cout<<n<<endl;
			if (n>temp) {
				temp=n;
				res=i;
			} else if (n==temp) {
				res=i;
			}
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
			int lowerBound            = 0;
			int upperBound            = 2;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = MaximumScoredNumber().getNumber(lowerBound, upperBound);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int lowerBound            = 0;
			int upperBound            = 30;
			int expected__            = 25;

			clock_t start__           = clock();
			int received__            = MaximumScoredNumber().getNumber(lowerBound, upperBound);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int lowerBound            = 0;
			int upperBound            = 0;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = MaximumScoredNumber().getNumber(lowerBound, upperBound);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int lowerBound            = 5;
			int upperBound            = 99;
			int expected__            = 85;

			clock_t start__           = clock();
			int received__            = MaximumScoredNumber().getNumber(lowerBound, upperBound);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int lowerBound            = 0;
			int upperBound            = 10000;
			int expected__            = 9425;

			clock_t start__           = clock();
			int received__            = MaximumScoredNumber().getNumber(lowerBound, upperBound);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int lowerBound            = ;
			int upperBound            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MaximumScoredNumber().getNumber(lowerBound, upperBound);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int lowerBound            = ;
			int upperBound            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MaximumScoredNumber().getNumber(lowerBound, upperBound);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int lowerBound            = ;
			int upperBound            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MaximumScoredNumber().getNumber(lowerBound, upperBound);
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
