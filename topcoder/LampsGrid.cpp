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

class LampsGrid {
public:
    int mostLit( vector <string> initial, int K ) {
        int len=initial[0].length(), sz=initial.size();
        int res=0;
        vector<int> on[50];
        for (int i=0; i<sz; i++) {
            for (int j=0; j<len; j++) {
                if (initial[i][j]=='0') on[i].push_back(j);
            }
        }
        for (int i=0; i<sz; i++) {
            if (on[i].size()>K||(K-on[i].size())%2!=0) continue;
            int cnt=0;
            for (int j=0; j<sz; j++) {
                if (on[i]==on[j]) cnt++;
            }
            res=max(res,cnt);
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
			string initial[]          = {"01",
 "10",
 "10"};
			int K                     = 1;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = LampsGrid().mostLit(vector <string>(initial, initial + (sizeof initial / sizeof initial[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string initial[]          = {"101010"};
			int K                     = 2;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = LampsGrid().mostLit(vector <string>(initial, initial + (sizeof initial / sizeof initial[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string initial[]          = {"00", "11"};
			int K                     = 999;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = LampsGrid().mostLit(vector <string>(initial, initial + (sizeof initial / sizeof initial[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string initial[]          = {"0", "1", "0", "1", "0"}
;
			int K                     = 1000;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = LampsGrid().mostLit(vector <string>(initial, initial + (sizeof initial / sizeof initial[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string initial[]          = {"001", "101", "001", "000", "111", "001", "101", "111", "110", "000", "111", "010", "110", "001"};
			int K                     = 6;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = LampsGrid().mostLit(vector <string>(initial, initial + (sizeof initial / sizeof initial[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			string initial[]          = {"01", "10", "01", "01", "10"};
			int K                     = 1;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = LampsGrid().mostLit(vector <string>(initial, initial + (sizeof initial / sizeof initial[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string initial[]          = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LampsGrid().mostLit(vector <string>(initial, initial + (sizeof initial / sizeof initial[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string initial[]          = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LampsGrid().mostLit(vector <string>(initial, initial + (sizeof initial / sizeof initial[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string initial[]          = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LampsGrid().mostLit(vector <string>(initial, initial + (sizeof initial / sizeof initial[0])), K);
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
