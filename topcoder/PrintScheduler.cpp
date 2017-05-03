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

class PrintScheduler {
public:
   string getOutput( vector <string> threads, vector <string> slices ) {
       string res = "";
       vector<int> npos(threads.size(), 0);
       for (int i=0; i<slices.size(); i++) {
           int nth, time;
           stringstream ss;
           ss.str(slices[i]);
           ss >> nth >> time;
           for (int j=0; j<time; j++) {
               int ad = npos[nth]+j;
               res += threads[nth][ad%threads[nth].length()];
           }
           npos[nth] += time;
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
			string threads[]          = {"AB","CD"};
			string slices[]           = {"0 1","1 1","0 1","1 2"} ;
			string expected__         = "ACBDC";

			clock_t start__           = clock();
			string received__         = PrintScheduler().getOutput(vector <string>(threads, threads + (sizeof threads / sizeof threads[0])), vector <string>(slices, slices + (sizeof slices / sizeof slices[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string threads[]          = {"ABCDE"};
			string slices[]           = {"0 20","0 21"};
			string expected__         = "ABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDEA";

			clock_t start__           = clock();
			string received__         = PrintScheduler().getOutput(vector <string>(threads, threads + (sizeof threads / sizeof threads[0])), vector <string>(slices, slices + (sizeof slices / sizeof slices[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string threads[]          = {"A","B"};
			string slices[]           = {"1 10","0 1","1 10","0 2"};
			string expected__         = "BBBBBBBBBBABBBBBBBBBBAA";

			clock_t start__           = clock();
			string received__         = PrintScheduler().getOutput(vector <string>(threads, threads + (sizeof threads / sizeof threads[0])), vector <string>(slices, slices + (sizeof slices / sizeof slices[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string threads[]          = {"A"};
			string slices[]           = {"0 1"};
			string expected__         = "A";

			clock_t start__           = clock();
			string received__         = PrintScheduler().getOutput(vector <string>(threads, threads + (sizeof threads / sizeof threads[0])), vector <string>(slices, slices + (sizeof slices / sizeof slices[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string threads[]          = ;
			string slices[]           = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = PrintScheduler().getOutput(vector <string>(threads, threads + (sizeof threads / sizeof threads[0])), vector <string>(slices, slices + (sizeof slices / sizeof slices[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string threads[]          = ;
			string slices[]           = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = PrintScheduler().getOutput(vector <string>(threads, threads + (sizeof threads / sizeof threads[0])), vector <string>(slices, slices + (sizeof slices / sizeof slices[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string threads[]          = ;
			string slices[]           = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = PrintScheduler().getOutput(vector <string>(threads, threads + (sizeof threads / sizeof threads[0])), vector <string>(slices, slices + (sizeof slices / sizeof slices[0])));
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
