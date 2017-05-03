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

class KingXNewCurrency {
public:
    bool can(int s, int a, int b) {
        if (s%a==0||s%b==0) return true;
        for (int i=s; i>=0; i-=a) {
            if (i%b==0) return true;
        }
        for (int i=s; i>=0; i-=b) {
            if (i%a==0) return true;
        }
        return false;
    }
    int howMany( int A, int B, int X ) {
        if (A%X==0&&B%X==0) return -1;
        int cnt=0;
        for (int i=1; i<=max(A,B); i++) {
            if (X!=i&&can(A,X,i)&&can(B,X,i)) cnt++;
        }
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
			int A                     = 5;
			int B                     = 8;
			int X                     = 5;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = KingXNewCurrency().howMany(A, B, X);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int A                     = 8;
			int B                     = 4;
			int X                     = 2;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = KingXNewCurrency().howMany(A, B, X);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int A                     = 7;
			int B                     = 4;
			int X                     = 13;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = KingXNewCurrency().howMany(A, B, X);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int A                     = 47;
			int B                     = 74;
			int X                     = 44;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = KingXNewCurrency().howMany(A, B, X);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int A                     = 128;
			int B                     = 96;
			int X                     = 3;
			int expected__            = 65;

			clock_t start__           = clock();
			int received__            = KingXNewCurrency().howMany(A, B, X);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int A                     = ;
			int B                     = ;
			int X                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = KingXNewCurrency().howMany(A, B, X);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int A                     = ;
			int B                     = ;
			int X                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = KingXNewCurrency().howMany(A, B, X);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int A                     = ;
			int B                     = ;
			int X                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = KingXNewCurrency().howMany(A, B, X);
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
