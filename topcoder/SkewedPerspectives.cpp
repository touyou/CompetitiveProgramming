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

class SkewedPerspectives {
public:
    vector <string> areTheyPossible( vector <int> cubes, int B, int w, vector <string> views ) {

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
	
	template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }
	template<> ostream& operator<<(ostream &os, const vector<string> &v) { os << "{"; for (vector<string>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " \"" << *vi << "\""; } os << " }"; return os; }

	int verify_case(int casenum, const vector <string> &expected, const vector <string> &received, clock_t elapsed) { 
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
			int cubes[]               = {1,1,1};
			int B                     = 1;
			int w                     = 2;
			string views[]            = { "012", "012bb", "bb0", "21bb", "21b", "1bb20" };
			string expected__[]       = {"valid", "valid", "valid", "valid", "valid", "valid" };

			clock_t start__           = clock();
			vector <string> received__ = SkewedPerspectives().areTheyPossible(vector <int>(cubes, cubes + (sizeof cubes / sizeof cubes[0])), B, w, vector <string>(views, views + (sizeof views / sizeof views[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int cubes[]               = {0,1,0};
			int B                     = 3;
			int w                     = 2;
			string views[]            = {"b","bb","bbb","bbbb","bbbbb","bbbbbb",
 "1", "1b","1bb","1bbb","1bbbb","1bbbbb","1bbbbbb",
 "b1","b1b","b1bb","b1bbb","b1bbbb","b1bbbbb",
 "bb1","bb1b","bb1bb","bb1bbb","bb1bbbb",
 "bbb1","bbb1b","bbb1bb","bbb1bbb",
 "bbbb1","bbbb1b","bbbb1bb",
 "bbbbb1","bbbbb1b",
 "bbbbbb1" };
			string expected__[]       = {"invalid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "invalid", "invalid", "invalid", "invalid", "invalid", "invalid", "valid", "valid", "valid", "invalid", "valid", "invalid", "invalid", "invalid", "invalid", "valid", "invalid", "valid", "invalid", "invalid", "valid" };

			clock_t start__           = clock();
			vector <string> received__ = SkewedPerspectives().areTheyPossible(vector <int>(cubes, cubes + (sizeof cubes / sizeof cubes[0])), B, w, vector <string>(views, views + (sizeof views / sizeof views[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int cubes[]               = {100,0,0};
			int B                     = 20;
			int w                     = 3;
			string views[]            = {"00000000000000000000000000000000000000000000000000",
 "00000000000000000000000000000000000b00000000000000",
 "0000000000000000000000000000000000000000000000000b",
 "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb0000000000000"};
			string expected__[]       = {"valid", "valid", "valid", "valid" };

			clock_t start__           = clock();
			vector <string> received__ = SkewedPerspectives().areTheyPossible(vector <int>(cubes, cubes + (sizeof cubes / sizeof cubes[0])), B, w, vector <string>(views, views + (sizeof views / sizeof views[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int cubes[]               = {5,6,3};
			int B                     = 0;
			int w                     = 1;
			string views[]            = {"00000111111222", "0000111111222", "0000011111222", "000001111111222", "0000011111122", "b"};
			string expected__[]       = {"valid", "valid", "valid", "invalid", "valid", "invalid" };

			clock_t start__           = clock();
			vector <string> received__ = SkewedPerspectives().areTheyPossible(vector <int>(cubes, cubes + (sizeof cubes / sizeof cubes[0])), B, w, vector <string>(views, views + (sizeof views / sizeof views[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			int cubes[]               = {100,100,100};
			int B                     = 100;
			int w                     = 50;
			string views[]            = {"2",
 "bb1b012012012012012012012",
 "bb1b012012012012012012012b",
 "bb1b012012012b012b012b012012b",
 "bb1b0b1b2b0b1b2b0b1b2bb012b012b012012b",
 "b1b0b1b2b0b1b2b0b1b2bb012b012b012012b",
 "bbb1b012012012012012012012"
};
			string expected__[]       = {"valid", "valid", "valid", "valid", "valid", "invalid", "valid" };

			clock_t start__           = clock();
			vector <string> received__ = SkewedPerspectives().areTheyPossible(vector <int>(cubes, cubes + (sizeof cubes / sizeof cubes[0])), B, w, vector <string>(views, views + (sizeof views / sizeof views[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 5: {
			int cubes[]               = {0,0,0};
			int B                     = 0;
			int w                     = 1;
			string views[]            = {"0", "bb"};
			string expected__[]       = {"invalid", "invalid" };

			clock_t start__           = clock();
			vector <string> received__ = SkewedPerspectives().areTheyPossible(vector <int>(cubes, cubes + (sizeof cubes / sizeof cubes[0])), B, w, vector <string>(views, views + (sizeof views / sizeof views[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 6: {
			int cubes[]               = {3,0,0};
			int B                     = 4;
			int w                     = 3;
			string views[]            = {"00b0b", "bbbbbbbb", "000b"};
			string expected__[]       = {"invalid", "valid", "valid" };

			clock_t start__           = clock();
			vector <string> received__ = SkewedPerspectives().areTheyPossible(vector <int>(cubes, cubes + (sizeof cubes / sizeof cubes[0])), B, w, vector <string>(views, views + (sizeof views / sizeof views[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			int cubes[]               = ;
			int B                     = ;
			int w                     = ;
			string views[]            = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = SkewedPerspectives().areTheyPossible(vector <int>(cubes, cubes + (sizeof cubes / sizeof cubes[0])), B, w, vector <string>(views, views + (sizeof views / sizeof views[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 8: {
			int cubes[]               = ;
			int B                     = ;
			int w                     = ;
			string views[]            = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = SkewedPerspectives().areTheyPossible(vector <int>(cubes, cubes + (sizeof cubes / sizeof cubes[0])), B, w, vector <string>(views, views + (sizeof views / sizeof views[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 9: {
			int cubes[]               = ;
			int B                     = ;
			int w                     = ;
			string views[]            = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = SkewedPerspectives().areTheyPossible(vector <int>(cubes, cubes + (sizeof cubes / sizeof cubes[0])), B, w, vector <string>(views, views + (sizeof views / sizeof views[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
