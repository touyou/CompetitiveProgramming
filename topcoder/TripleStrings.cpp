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

class TripleStrings {
public:
   int getMinimumOperations( string init, string goal ) {
     if (init==goal) return 0;
     int len = init.length();
     int res=0;
     for (int i=len-1; i>0; i--) {
       //       cout<<goal.substr(0,i)<<" "<<init.substr(len-i,i)<<endl;
       if (goal.substr(0,i)==init.substr(len-i,i)) {
	 res = i;
	 break;
       }
     }
     return (len-res)*2;
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
			string init               = "ooxxox";
			string goal               = "xoxoxo";
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = TripleStrings().getMinimumOperations(init, goal);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string init               = "oooxxoo";
			string goal               = "oooxxoo";
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = TripleStrings().getMinimumOperations(init, goal);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string init               = "ox";
			string goal               = "xo";
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = TripleStrings().getMinimumOperations(init, goal);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string init               = "ooxxooxx";
			string goal               = "xxoxoxoo";
			int expected__            = 12;

			clock_t start__           = clock();
			int received__            = TripleStrings().getMinimumOperations(init, goal);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string init               = "oxxoxxoooxooooxxxoo";
			string goal               = "oxooooxxxooooxoxxxo";
			int expected__            = 16;

			clock_t start__           = clock();
			int received__            = TripleStrings().getMinimumOperations(init, goal);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			string init               = "xxxoxoxxooxooxoxooo";
			string goal               = "oxxooxxooxxoxoxooxo";
			int expected__            = 36;

			clock_t start__           = clock();
			int received__            = TripleStrings().getMinimumOperations(init, goal);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string init               = ;
			string goal               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TripleStrings().getMinimumOperations(init, goal);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string init               = ;
			string goal               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TripleStrings().getMinimumOperations(init, goal);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string init               = ;
			string goal               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TripleStrings().getMinimumOperations(init, goal);
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
