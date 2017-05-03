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

class grafixCorrupt {
public:
   int selectWord( vector <string> dictionary, string candidate ) {
       int m = 0;
       string rstr;
       int rpos = -1;
       for (int i=0; i<dictionary.size(); i++) {
           int same = 0;
           for (int j=0; j<candidate.length(); j++) {
               if (dictionary[i][j] == candidate[j]) same++;
           }
           if (same > m) {
               m = same;
               rstr = dictionary[i];
               rpos = i;
           }
       }
       return rpos;
       
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
			string dictionary[]       = {"cat", "cab", "lab"};
			string candidate          = "dab";
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = grafixCorrupt().selectWord(vector <string>(dictionary, dictionary + (sizeof dictionary / sizeof dictionary[0])), candidate);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string dictionary[]       = {"cat", "cab", "lab"};
			string candidate          = "lag";
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = grafixCorrupt().selectWord(vector <string>(dictionary, dictionary + (sizeof dictionary / sizeof dictionary[0])), candidate);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string dictionary[]       = {"cat", "cab", "lab"};
			string candidate          = "bic";
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = grafixCorrupt().selectWord(vector <string>(dictionary, dictionary + (sizeof dictionary / sizeof dictionary[0])), candidate);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string dictionary[]       = {"zkv", "izs", "fed", "waa", "ttx", "bgt", "quy", "dtq", "dgo", "yrs",
 "cid", "nln", "pvz", "txt", "zun", "erd", "jen", "klh", "kxy", "emf",
 "mqt", "lza", "dzb", "ndx", "vfr", "jhs", "dkm", "elb"};
			string candidate          = "cwd";
			int expected__            = 10;

			clock_t start__           = clock();
			int received__            = grafixCorrupt().selectWord(vector <string>(dictionary, dictionary + (sizeof dictionary / sizeof dictionary[0])), candidate);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string dictionary[]       = {"zhadjsg", "vzptftx", "fbaslxs", "ejejncm", "xpxkeae", "ixrrtzw",
 "ovctbzx", "sfzekhh", "lxzixjk", "jixdpik", "bkianck", "laclyin",
 "uqmdkfx", "dimswqo", "fojhetr", "grntrce", "obdtqwx", "bhojwcy",
 "zuuuvst", "mvqtoly", "aftmupx", "govuidx", "qklpret", "yptccki",
 "uxdnslh", "wudrusz", "uwxbvou", "ouytqun", "pjdexqe", "xraaqdw",
 "lxmoncl", "sjnjfgb", "qrlqgvc", "fgvoadm", "yohsrxw", "udpvrsr",
 "mklucgt"};
			string candidate          = "vklikgf";
			int expected__            = 36;

			clock_t start__           = clock();
			int received__            = grafixCorrupt().selectWord(vector <string>(dictionary, dictionary + (sizeof dictionary / sizeof dictionary[0])), candidate);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string dictionary[]       = ;
			string candidate          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = grafixCorrupt().selectWord(vector <string>(dictionary, dictionary + (sizeof dictionary / sizeof dictionary[0])), candidate);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string dictionary[]       = ;
			string candidate          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = grafixCorrupt().selectWord(vector <string>(dictionary, dictionary + (sizeof dictionary / sizeof dictionary[0])), candidate);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string dictionary[]       = ;
			string candidate          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = grafixCorrupt().selectWord(vector <string>(dictionary, dictionary + (sizeof dictionary / sizeof dictionary[0])), candidate);
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
