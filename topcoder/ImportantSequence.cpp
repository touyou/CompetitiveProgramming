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

class ImportantSequence {
public:
   int getCount( vector <int> B, string operators ) {
        int fp=0;
        int len=B.size();
        while (fp<len&&operators[fp]=='-') fp++;
        if (fp==len) return -1;
        if (fp==len-1) {
            return B[fp]-1;
        }
        if (operators[fp+1]=='-') return max(0,B[fp]-max(1,B[fp+1]+1));
        if (operators[fp+1]=='+') {
            int tp=fp+1;
            while (tp<len&&operators[tp]=='+') tp++;
            printf("%d\n",tp);
            if (tp==len) {
                int res=INT_MAX;
                for (int i=fp; i<tp; i++) res=min(res,B[i]);
                return res-1;
            }
            return max(0,B[tp-1]-max(1,B[tp]+1));
        }
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
			int B[]                   = {3, -1, 7};
			string operators          = "+-+";
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = ImportantSequence().getCount(vector <int>(B, B + (sizeof B / sizeof B[0])), operators);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int B[]                   = {1};
			string operators          = "-";
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = ImportantSequence().getCount(vector <int>(B, B + (sizeof B / sizeof B[0])), operators);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int B[]                   = {1};
			string operators          = "+";
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = ImportantSequence().getCount(vector <int>(B, B + (sizeof B / sizeof B[0])), operators);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int B[]                   = {10};
			string operators          = "+";
			int expected__            = 9;

			clock_t start__           = clock();
			int received__            = ImportantSequence().getCount(vector <int>(B, B + (sizeof B / sizeof B[0])), operators);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int B[]                   = {540, 2012, 540, 2012, 540, 2012, 540};
			string operators          = "-+-+-+-";
			int expected__            = 1471;

			clock_t start__           = clock();
			int received__            = ImportantSequence().getCount(vector <int>(B, B + (sizeof B / sizeof B[0])), operators);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int B[]                   = ;
			string operators          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ImportantSequence().getCount(vector <int>(B, B + (sizeof B / sizeof B[0])), operators);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int B[]                   = ;
			string operators          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ImportantSequence().getCount(vector <int>(B, B + (sizeof B / sizeof B[0])), operators);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int B[]                   = ;
			string operators          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ImportantSequence().getCount(vector <int>(B, B + (sizeof B / sizeof B[0])), operators);
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
