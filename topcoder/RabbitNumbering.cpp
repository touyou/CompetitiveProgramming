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
#define MOD 1000000007

class RabbitNumbering {
public:
   int theCount( vector <int> maxNumber ) {
       ll res = 1;
       sort(maxNumber.begin(), maxNumber.end());
       for (int i=0; i<maxNumber.size(); i++) {
           res = res * (maxNumber[i] - i) % MOD;
           cout << res << endl;
       }
       return (int)res;
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
			int maxNumber[]           = {5};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = RabbitNumbering().theCount(vector <int>(maxNumber, maxNumber + (sizeof maxNumber / sizeof maxNumber[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int maxNumber[]           = {4, 4, 4, 4};
			int expected__            = 24;

			clock_t start__           = clock();
			int received__            = RabbitNumbering().theCount(vector <int>(maxNumber, maxNumber + (sizeof maxNumber / sizeof maxNumber[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int maxNumber[]           = {5, 8};
			int expected__            = 35;

			clock_t start__           = clock();
			int received__            = RabbitNumbering().theCount(vector <int>(maxNumber, maxNumber + (sizeof maxNumber / sizeof maxNumber[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int maxNumber[]           = {2, 1, 2};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = RabbitNumbering().theCount(vector <int>(maxNumber, maxNumber + (sizeof maxNumber / sizeof maxNumber[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int maxNumber[]           = {25, 489, 76, 98, 704, 98, 768, 39, 697, 8, 56, 74, 36, 95, 87, 2, 968, 4, 920, 54, 873, 90};
			int expected__            = 676780400;

			clock_t start__           = clock();
			int received__            = RabbitNumbering().theCount(vector <int>(maxNumber, maxNumber + (sizeof maxNumber / sizeof maxNumber[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int maxNumber[]           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = RabbitNumbering().theCount(vector <int>(maxNumber, maxNumber + (sizeof maxNumber / sizeof maxNumber[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int maxNumber[]           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = RabbitNumbering().theCount(vector <int>(maxNumber, maxNumber + (sizeof maxNumber / sizeof maxNumber[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int maxNumber[]           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = RabbitNumbering().theCount(vector <int>(maxNumber, maxNumber + (sizeof maxNumber / sizeof maxNumber[0])));
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
