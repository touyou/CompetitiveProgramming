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
typedef map<int,int> mp;

#define EPS 1e-9
#define PI 3.14159265358979

class ContestWinner {
public:
   int getWinner( vector <int> events ) {
        int res=0, p=0, sz=events.size();
        mp cnt;
        for (int i=0; i<sz; i++) {
            if (cnt.find(events[i])!=cnt.end()) {
                cnt[events[i]]++;
                if (cnt[events[i]]>p) {
                    res=events[i];
                    p=cnt[events[i]];
                }
            } else {
                cnt[events[i]]=1;
                if (1>p) {
                    res=events[i];
                    p=1;
                }
            }
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
			int events[]              = {4,7,4,1};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = ContestWinner().getWinner(vector <int>(events, events + (sizeof events / sizeof events[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int events[]              = {10,20,30,40,50};
			int expected__            = 10;

			clock_t start__           = clock();
			int received__            = ContestWinner().getWinner(vector <int>(events, events + (sizeof events / sizeof events[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int events[]              = {123,123,456,456,456,123};
			int expected__            = 456;

			clock_t start__           = clock();
			int received__            = ContestWinner().getWinner(vector <int>(events, events + (sizeof events / sizeof events[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int events[]              = {1,2,2,3,3,3,4,4,4,4};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = ContestWinner().getWinner(vector <int>(events, events + (sizeof events / sizeof events[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int events[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ContestWinner().getWinner(vector <int>(events, events + (sizeof events / sizeof events[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int events[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ContestWinner().getWinner(vector <int>(events, events + (sizeof events / sizeof events[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int events[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ContestWinner().getWinner(vector <int>(events, events + (sizeof events / sizeof events[0])));
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
