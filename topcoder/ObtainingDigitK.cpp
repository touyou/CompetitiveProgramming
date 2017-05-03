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

class ObtainingDigitK {
public:
   int minNumberToAdd( string originalNumber, int k ) {
	// int res = 0;
	// string temp = originalNumber;
	// for (int ix=0; ix<10; ix++) {
		// if (find(temp.begin(), temp.end(), k+'0')!=temp.end()) break;
		// int num = temp[temp.length() - 1] - '0';
		// num++;
		// if (num > 9) {
			// for (int i=temp.length()-2; i>=0; i--) {
				// if (num > 9) {
					// num -= 10;
					// temp[i+1] = num + '0';
					// num = 1;
				// } else {
					// temp[i+1] = num + '0';
					// num = 0;
				// }
				// num += temp[i] - '0';
			// }
		// } else {
			// temp[temp.length() - 1] = num + '0';
		// }
		// if (num > 9) {
			// temp[0] = num-10+'0';
			// temp = "1" + temp;
		// }
		// res++;
	// }
	// return res;
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
			string originalNumber     = "153";
			int k                     = 7;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = ObtainingDigitK().minNumberToAdd(originalNumber, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string originalNumber     = "158";
			int k                     = 7;
			int expected__            = 9;

			clock_t start__           = clock();
			int received__            = ObtainingDigitK().minNumberToAdd(originalNumber, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string originalNumber     = "7853192";
			int k                     = 2;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = ObtainingDigitK().minNumberToAdd(originalNumber, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string originalNumber     = "99999999999999999999999999999999999999999999999";
			int k                     = 0;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = ObtainingDigitK().minNumberToAdd(originalNumber, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string originalNumber     = ;
			int k                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ObtainingDigitK().minNumberToAdd(originalNumber, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string originalNumber     = ;
			int k                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ObtainingDigitK().minNumberToAdd(originalNumber, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string originalNumber     = ;
			int k                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ObtainingDigitK().minNumberToAdd(originalNumber, k);
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
