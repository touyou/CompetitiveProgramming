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

class TrueSpace {
public:
   long long calculateSpace( vector <int> sizes, int clusterSize ) {
       ll res = 0;
       for (int i = 0; i < sizes.size(); i++) {
           if (sizes[i] == 0) continue;
           if (sizes[i] < clusterSize) {
               res += clusterSize;
               continue;
           }
           if (sizes[i] % clusterSize == 0) res += sizes[i];
           else res += (sizes[i] / clusterSize + 1) * clusterSize;
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
	
	int verify_case(int casenum, const long long &expected, const long long &received, clock_t elapsed) { 
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
			int sizes[]               = {600};
			int clusterSize           = 512;
			long long expected__      = 1024;

			clock_t start__           = clock();
			long long received__      = TrueSpace().calculateSpace(vector <int>(sizes, sizes + (sizeof sizes / sizeof sizes[0])), clusterSize);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int sizes[]               = {16,32,128,128,0};
			int clusterSize           = 32768;
			long long expected__      = 131072;

			clock_t start__           = clock();
			long long received__      = TrueSpace().calculateSpace(vector <int>(sizes, sizes + (sizeof sizes / sizeof sizes[0])), clusterSize);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int sizes[]               = {4096, 33792, 76800};
			int clusterSize           = 1024;
			long long expected__      = 114688;

			clock_t start__           = clock();
			long long received__      = TrueSpace().calculateSpace(vector <int>(sizes, sizes + (sizeof sizes / sizeof sizes[0])), clusterSize);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int sizes[]               = {1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000} ;
			int clusterSize           = 1048576;
			long long expected__      = 50017075200LL;

			clock_t start__           = clock();
			long long received__      = TrueSpace().calculateSpace(vector <int>(sizes, sizes + (sizeof sizes / sizeof sizes[0])), clusterSize);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int sizes[]               = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
			int clusterSize           = 8;
			long long expected__      = 0;

			clock_t start__           = clock();
			long long received__      = TrueSpace().calculateSpace(vector <int>(sizes, sizes + (sizeof sizes / sizeof sizes[0])), clusterSize);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int sizes[]               = ;
			int clusterSize           = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = TrueSpace().calculateSpace(vector <int>(sizes, sizes + (sizeof sizes / sizeof sizes[0])), clusterSize);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int sizes[]               = ;
			int clusterSize           = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = TrueSpace().calculateSpace(vector <int>(sizes, sizes + (sizeof sizes / sizeof sizes[0])), clusterSize);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int sizes[]               = ;
			int clusterSize           = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = TrueSpace().calculateSpace(vector <int>(sizes, sizes + (sizeof sizes / sizeof sizes[0])), clusterSize);
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
