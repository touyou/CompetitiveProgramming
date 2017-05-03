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

class BusinessTasks {
public:
   string getTask( vector <string> list, int n ) {
       int npos = 0;
       for (;;) {
           npos += n-1;
           npos %= list.size();
           vector<string>::iterator it = list.begin();
           for (int i=0; i<npos; i++) it++;
           list.erase(it);
           if (list.size() == 1) break;
       }
       return list[0];
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
			string list[]             = {"a","b","c","d"};
			int n                     = 2;
			string expected__         = "a";

			clock_t start__           = clock();
			string received__         = BusinessTasks().getTask(vector <string>(list, list + (sizeof list / sizeof list[0])), n);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string list[]             = {"a","b","c","d","e"};
			int n                     = 3;
			string expected__         = "d";

			clock_t start__           = clock();
			string received__         = BusinessTasks().getTask(vector <string>(list, list + (sizeof list / sizeof list[0])), n);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string list[]             = {"alpha","beta","gamma","delta","epsilon"};
			int n                     = 1;
			string expected__         = "epsilon";

			clock_t start__           = clock();
			string received__         = BusinessTasks().getTask(vector <string>(list, list + (sizeof list / sizeof list[0])), n);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string list[]             = {"a","b"};
			int n                     = 1000;
			string expected__         = "a";

			clock_t start__           = clock();
			string received__         = BusinessTasks().getTask(vector <string>(list, list + (sizeof list / sizeof list[0])), n);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string list[]             = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t",
"u","v","w","x","y","z"};
			int n                     = 17;
			string expected__         = "n";

			clock_t start__           = clock();
			string received__         = BusinessTasks().getTask(vector <string>(list, list + (sizeof list / sizeof list[0])), n);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			string list[]             = {"zlqamum","yjsrpybmq","tjllfea","fxjqzznvg","nvhekxr","am","skmazcey","piklp",
"olcqvhg","dnpo","bhcfc","y","h","fj","bjeoaxglt","oafduixsz","kmtbaxu",
"qgcxjbfx","my","mlhy","bt","bo","q"};
			int n                     = 9000000;
			string expected__         = "fxjqzznvg";

			clock_t start__           = clock();
			string received__         = BusinessTasks().getTask(vector <string>(list, list + (sizeof list / sizeof list[0])), n);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string list[]             = ;
			int n                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = BusinessTasks().getTask(vector <string>(list, list + (sizeof list / sizeof list[0])), n);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string list[]             = ;
			int n                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = BusinessTasks().getTask(vector <string>(list, list + (sizeof list / sizeof list[0])), n);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string list[]             = ;
			int n                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = BusinessTasks().getTask(vector <string>(list, list + (sizeof list / sizeof list[0])), n);
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
