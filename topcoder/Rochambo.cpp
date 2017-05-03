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

class Rochambo {
public:
   int wins( string opponent ) {
       int res = 0;
       string me = "RR";
       char one = opponent[0], two = opponent[1];
       for (int i=2; i<opponent.length(); i++) {
           if (one == two) {
               if (one == 'R') me += 'P';
               else if (one == 'P') me += 'S';
               else if (one == 'S') me += 'R';
           }
           else {
               if (one!='R'&&two!='R') me += 'P';
               else if (one!='P'&&two!='P') me += 'S';
               else if (one!='S'&&two!='S') me += 'R';
           }
           one = two;
           two = opponent[i];
       }
       for (int i=0; i<me.length(); i++) {
           if (me[i]=='R'&&opponent[i]=='S') res++;
           else if (me[i]=='P'&&opponent[i]=='R') res++;
           else if (me[i]=='S'&&opponent[i]=='P') res++;
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
			string opponent           = "PS";
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = Rochambo().wins(opponent);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string opponent           = "PSRRPS";
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = Rochambo().wins(opponent);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string opponent           = "PSRPSRPRSR";
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = Rochambo().wins(opponent);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string opponent           = "SRPSRPSPRSPRPSRPSRP";
			int expected__            = 16;

			clock_t start__           = clock();
			int received__            = Rochambo().wins(opponent);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string opponent           = "RPPPRRPSSSRRRSRSPPSSPRRPSRRRRSPPPPSSPSSSSSRSSSRPRR";
			int expected__            = 18;

			clock_t start__           = clock();
			int received__            = Rochambo().wins(opponent);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string opponent           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Rochambo().wins(opponent);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string opponent           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Rochambo().wins(opponent);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string opponent           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Rochambo().wins(opponent);
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
