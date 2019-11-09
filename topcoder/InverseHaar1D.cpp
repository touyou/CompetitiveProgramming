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

class InverseHaar1D {
public:
   vector <int> transform( vector <int> transformedData, int L ) {

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

	int verify_case(int casenum, const vector <int> &expected, const vector <int> &received, clock_t elapsed) { 
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
			int transformedData[]     = {101, -53};
			int L                     = 1;
			int expected__[]          = {24, 77 };

			clock_t start__           = clock();
			vector <int> received__   = InverseHaar1D().transform(vector <int>(transformedData, transformedData + (sizeof transformedData / sizeof transformedData[0])), L);
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int transformedData[]     = {3, 8, -1, -2};
			int L                     = 1;
			int expected__[]          = {1, 2, 3, 5 };

			clock_t start__           = clock();
			vector <int> received__   = InverseHaar1D().transform(vector <int>(transformedData, transformedData + (sizeof transformedData / sizeof transformedData[0])), L);
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int transformedData[]     = {11, -5, -1, -2};
			int L                     = 2;
			int expected__[]          = {1, 2, 3, 5 };

			clock_t start__           = clock();
			vector <int> received__   = InverseHaar1D().transform(vector <int>(transformedData, transformedData + (sizeof transformedData / sizeof transformedData[0])), L);
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int transformedData[]     = {369, 477, 451, 262, 47, 135, -125, -2, 18, -23, 30, 101, -5, -18, 54, -20, 11, 45, -5, 70, -24, 2, -50, 15, 55, -62, -23, -17, 44, -8, -44, -52};
			int L                     = 3;
			int expected__[]          = {62, 51, 70, 25, 32, 37, 81, 11, 72, 96, 70, 68, 43, 93, 25, 10, 67, 12, 11, 73, 56, 79, 68, 85, 68, 24, 15, 23, 6, 50, 12, 64 };

			clock_t start__           = clock();
			vector <int> received__   = InverseHaar1D().transform(vector <int>(transformedData, transformedData + (sizeof transformedData / sizeof transformedData[0])), L);
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int transformedData[]     = ;
			int L                     = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = InverseHaar1D().transform(vector <int>(transformedData, transformedData + (sizeof transformedData / sizeof transformedData[0])), L);
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 5: {
			int transformedData[]     = ;
			int L                     = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = InverseHaar1D().transform(vector <int>(transformedData, transformedData + (sizeof transformedData / sizeof transformedData[0])), L);
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			int transformedData[]     = ;
			int L                     = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = InverseHaar1D().transform(vector <int>(transformedData, transformedData + (sizeof transformedData / sizeof transformedData[0])), L);
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
