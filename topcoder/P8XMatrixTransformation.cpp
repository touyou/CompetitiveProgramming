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
#define PI 3.14159265358979

class P8XMatrixTransformation {
public:
   string solve( vector <string> original, vector <string> target ) {
    int onum = 0, tnum = 0;
    for (int i=0; i<original.size(); i++) for (int j=0; j<original[i].length(); j++) if (original[i][j]=='1') onum++;
    for (int i=0; i<target.size(); i++) for (int j=0; j<target[i].length(); j++) if (target[i][j]=='1') tnum++;
    if (onum==tnum) return "YES";
    else return "NO";
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
			string original[]         = {"01"
,"11"};
			string target[]           = {"11"
,"10"};
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = P8XMatrixTransformation().solve(vector <string>(original, original + (sizeof original / sizeof original[0])), vector <string>(target, target + (sizeof target / sizeof target[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string original[]         = {"0111"
,"0011"};
			string target[]           = {"1011"
,"1100"};
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = P8XMatrixTransformation().solve(vector <string>(original, original + (sizeof original / sizeof original[0])), vector <string>(target, target + (sizeof target / sizeof target[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string original[]         = {"0"};
			string target[]           = {"1"};
			string expected__         = "NO";

			clock_t start__           = clock();
			string received__         = P8XMatrixTransformation().solve(vector <string>(original, original + (sizeof original / sizeof original[0])), vector <string>(target, target + (sizeof target / sizeof target[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string original[]         = {"1111"
,"1111"
,"0000"
,"0000"};
			string target[]           = {"1111"
,"1111"
,"0000"
,"0000"};
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = P8XMatrixTransformation().solve(vector <string>(original, original + (sizeof original / sizeof original[0])), vector <string>(target, target + (sizeof target / sizeof target[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string original[]         = {"0110"
,"1001"
,"0110"};
			string target[]           = {"1111"
,"0110"
,"0000"};
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = P8XMatrixTransformation().solve(vector <string>(original, original + (sizeof original / sizeof original[0])), vector <string>(target, target + (sizeof target / sizeof target[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			string original[]         = {"0000"
,"1111"
,"0000"};
			string target[]           = {"1111"
,"0000"
,"1111"};
			string expected__         = "NO";

			clock_t start__           = clock();
			string received__         = P8XMatrixTransformation().solve(vector <string>(original, original + (sizeof original / sizeof original[0])), vector <string>(target, target + (sizeof target / sizeof target[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string original[]         = ;
			string target[]           = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = P8XMatrixTransformation().solve(vector <string>(original, original + (sizeof original / sizeof original[0])), vector <string>(target, target + (sizeof target / sizeof target[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string original[]         = ;
			string target[]           = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = P8XMatrixTransformation().solve(vector <string>(original, original + (sizeof original / sizeof original[0])), vector <string>(target, target + (sizeof target / sizeof target[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string original[]         = ;
			string target[]           = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = P8XMatrixTransformation().solve(vector <string>(original, original + (sizeof original / sizeof original[0])), vector <string>(target, target + (sizeof target / sizeof target[0])));
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
